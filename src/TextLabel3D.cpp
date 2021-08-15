#include SAMPSTREAMER_PCH

#include <SAMPStreamer/TextLabel3D.hpp>

namespace samp_streamer
{

//////////////////////////////////////////////////////
DynamicTextLabel3D DynamicTextLabel3D::create(
		std::string const& text_,
		samp_cpp::Color color_,
		Vec3f const& pos_,
		float drawDistance_,
		samp_cpp::Player attachedPlayer_,
		samp_cpp::Vehicle attachedVeh_,
		bool testLos_,
		int virtualWorld_,
		int interiorIdx_,
		samp_cpp::Player player_,
		float streamDistance_,
		int areaIdx_,
		int priority_
	)
{
	return DynamicTextLabel3D::create(
			text_.c_str(),
			color_,
			pos_.x, pos_.y, pos_.z,
			drawDistance_,
			attachedPlayer_,
			attachedVeh_,
			testLos_,
			virtualWorld_,
			interiorIdx_,
			player_,
			streamDistance_,
			areaIdx_,
			priority_
		);
}

//////////////////////////////////////////////////////
DynamicTextLabel3D DynamicTextLabel3D::create(
		char const* text_,
		samp_cpp::Color color_,
		float x_, float y_, float z_,
		float drawDistance_,
		samp_cpp::Player attachedPlayer_,
		samp_cpp::Vehicle attachedVeh_,
		bool testLos_,
		int virtualWorld_,
		int interiorIdx_,
		samp_cpp::Player player_,
		float streamDistance_,
		int areaIdx_,
		int priority_
	)
{
	return CreateDynamic3DTextLabel(
			text_,
			color_,
			x_, y_, z_,
			drawDistance_,
			attachedPlayer_.id(),
			attachedVeh_.id(),
			static_cast<int>(testLos_),
			virtualWorld_,
			interiorIdx_,
			player_.id(),
			streamDistance_,
			areaIdx_,
			priority_
		);
}


//////////////////////////////////////////////////////
bool DynamicTextLabel3D::destroy()
{
	return static_cast<bool>( DestroyDynamic3DTextLabel(_id) );
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::valid() const
{
	return static_cast<bool>( IsValidDynamic3DTextLabel(_id) );
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::attachTo(samp_cpp::Player player_, Vec3f const& offset_)
{
	return this->attachTo(player_, offset_.x, offset_.y, offset_.z);
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::attachTo(samp_cpp::Player player_, float offsetX_, float offsetY_, float offsetZ_)
{
	// TODO: test if this works.
	this->setIntData(FieldType::AttachedVehicle, INVALID_VEHICLE_ID);
	this->setIntData(FieldType::AttachedPlayer, player_.id());
	this->setFloatData(FieldType::AttachX, offsetX_);
	this->setFloatData(FieldType::AttachY, offsetY_);
	this->setFloatData(FieldType::AttachZ, offsetZ_);
	return true;
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::attachTo(samp_cpp::Vehicle vehicle_, Vec3f const& offset_)
{
	return this->attachTo(vehicle_, offset_.x, offset_.y, offset_.z);
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::attachTo(samp_cpp::Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_)
{
	// TODO: test if this works.
	this->setIntData(FieldType::AttachedVehicle, vehicle_.id());
	this->setIntData(FieldType::AttachedPlayer, INVALID_PLAYER_ID);
	this->setFloatData(FieldType::AttachX, offsetX_);
	this->setFloatData(FieldType::AttachY, offsetY_);
	this->setFloatData(FieldType::AttachZ, offsetZ_);
	return true;
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::updateText(samp_cpp::Color color_, std::string const& text_)
{
	return this->updateText(color_, text_.c_str());
}

//////////////////////////////////////////////////////
bool DynamicTextLabel3D::updateText(samp_cpp::Color color_, char const* text_)
{
	return UpdateDynamic3DTextLabelText(_id, color_, text_);
}

}