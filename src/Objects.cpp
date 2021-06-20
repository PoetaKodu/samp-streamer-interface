#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Objects.hpp>

namespace samp_streamer
{

////////////////////////////////////////////////////////////
DynamicObject DynamicObject::create(int modelIdx_, Vec3f const& pos_, Vec3f const& rot_, int worldIdx_, int interiorIdx_, samp_cpp::Player player_, float streamDistance_, float drawDistance_, int areaIdx_, int priority_)
{
	return DynamicObject::create(modelIdx_, pos_.x, pos_.y, pos_.z, rot_.x, rot_.y, rot_.z, worldIdx_, interiorIdx_, player_, streamDistance_, drawDistance_, areaIdx_, priority_);
}

////////////////////////////////////////////////////////////
DynamicObject DynamicObject::create(int modelIdx_, float x_, float y_, float z_, float rX_, float rY_, float rZ_, int worldIdx_, int interiorIdx_, samp_cpp::Player player_, float streamDistance_, float drawDistance_, int areaIdx_, int priority_)
{
	return DynamicObject{ CreateDynamicObject(modelIdx_, x_, y_, z_, rX_, rY_, rZ_, worldIdx_, interiorIdx_, player_.id(), streamDistance_, drawDistance_, areaIdx_, priority_) };
}

////////////////////////////////////////////////////////////
bool DynamicObject::attachTo(samp_cpp::Vehicle vehicle_, Vec3f const& offset_, Vec3f const& rot_)
{
	return this->attachTo(vehicle_, offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
bool DynamicObject::attachTo(samp_cpp::Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_)
{
	return AttachDynamicObjectToVehicle(_id, vehicle_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::attachTo(DynamicObject attachTo_, Vec3f const& offset_, Vec3f const& rot_, bool syncRotation_)
{
	return this->attachTo(attachTo_, offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z, syncRotation_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::attachTo(DynamicObject attachTo_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_, bool syncRotation_)
{
	return AttachDynamicObjectToObject(_id, attachTo_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_, syncRotation_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::attachTo(samp_cpp::Player player_, Vec3f const& offset_, Vec3f const& rot_)
{
	return this->attachTo(player_, offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
bool DynamicObject::attachTo(samp_cpp::Player player_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_)
{
	return AttachDynamicObjectToPlayer(_id, player_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setPosition(Vec3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setPosition(float x_, float y_, float z_)
{
	return SetDynamicObjectPos(_id, x_, y_, z_);
}

////////////////////////////////////////////////////////////
Vec3f DynamicObject::getPosition() const
{
	Vec3f result;
	GetDynamicObjectPos(_id, &result.x, &result.y, &result.z);
	return result;
}

////////////////////////////////////////////////////////////
bool DynamicObject::setRotation(Vec3f const& rot_)
{
	return this->setRotation(rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setRotation(float rotX_, float rotY_, float rotZ_)
{
	return SetDynamicObjectRot(_id, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
Vec3f DynamicObject::getRotation() const
{
	Vec3f result;
	GetDynamicObjectRot(_id, &result.x, &result.y, &result.z);
	return result;
}

// ////////////////////////////////////////////////////////////
// int DynamicObject::getModel() const
// {
// 	return -1;
// 	// return GetDynamicObjectModel(_id); // TODO: add this function
// }

// ////////////////////////////////////////////////////////////
// bool DynamicObject::setNoCameraCol()
// {
// 	return SetDynamicObjectNoCameraCol(_id); // TODO: add this function
// }

////////////////////////////////////////////////////////////
bool DynamicObject::valid() const
{
	return IsValidDynamicObject(_id);
}

////////////////////////////////////////////////////////////
bool DynamicObject::destroy()
{
	return DestroyDynamicObject(_id);
}

////////////////////////////////////////////////////////////
int DynamicObject::move(Vec3f const& targetPos_, float speed_, Vec3f rot_)
{
	return this->move(targetPos_.x, targetPos_.y, targetPos_.z, speed_, rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
int DynamicObject::move(float x_, float y_, float z_, float speed_, float rotX_, float rotY_, float rotZ_)
{
	return MoveDynamicObject(_id, x_, y_, z_, speed_, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::stop()
{
	return StopDynamicObject(_id);
}

////////////////////////////////////////////////////////////
bool DynamicObject::isMoving() const
{
	return IsDynamicObjectMoving(_id);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setMaterial(int materialIndex_, int modelIdx_, std::string const& txdName_, std::string const& textureName_, samp_cpp::Color materialColor_)
{
	return this->setMaterial(materialIndex_, modelIdx_, txdName_.c_str(), textureName_.c_str(), materialColor_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setMaterial(int materialIndex_, int modelIdx_, char const* txdName_, char const* textureName_, samp_cpp::Color materialColor_)
{
	return SetDynamicObjectMaterial(_id, materialIndex_, modelIdx_, txdName_, textureName_, materialColor_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setMaterialText(std::string const& text_, int materialIndex_, int materialSize_, std::string const& fontFace_, int fontSize_, bool bold_, samp_cpp::Color fontColor_, samp_cpp::Color backColor_, int textAlignment_)
{
	return this->setMaterialText(text_.c_str(), materialIndex_, materialSize_, fontFace_.c_str(), fontSize_, bold_, fontColor_, backColor_, textAlignment_);
}

////////////////////////////////////////////////////////////
bool DynamicObject::setMaterialText(char const* text_, int materialIndex_, int materialSize_, char const* fontFace_, int fontSize_, bool bold_, samp_cpp::Color fontColor_, samp_cpp::Color backColor_, int textAlignment_)
{
	return SetDynamicObjectMaterialText(_id, materialIndex_, text_, materialSize_, fontFace_, fontSize_, bold_, fontColor_, backColor_, textAlignment_);
}


}