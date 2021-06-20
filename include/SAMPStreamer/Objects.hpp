#pragma once

#include SAMPSTREAMER_PCH

namespace samp_streamer
{

constexpr float STREAMER_OBJECT_SD = 300.f;
constexpr float STREAMER_OBJECT_DD = 0.f;
DECLARE_SMART_NATIVE(CreateDynamicObject,
		(int modelid, float x, float y, float z, float rx, float ry, float rz, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_OBJECT_SD, float drawdistance = STREAMER_OBJECT_DD, int areaid = -1, int priority = 0),
		(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority)
	);

DECLARE_SMART_NATIVE(DestroyDynamicObject,
		(int objectid),
		(objectid)
	);
DECLARE_SMART_NATIVE(IsValidDynamicObject,
		(int objectid),
		(objectid)
	);
DECLARE_SMART_NATIVE(GetDynamicObjectPos,
		(int objectid, float* x, float* y, float* z),
		(objectid, x, y, z)
	);
DECLARE_SMART_NATIVE(SetDynamicObjectPos,
		(int objectid, float x, float y, float z),
		(objectid, x, y, z)
	);
DECLARE_SMART_NATIVE(GetDynamicObjectRot,
		(int objectid, float* rx, float* ry, float* rz),
		(objectid, rx, ry, rz)
	);
DECLARE_SMART_NATIVE(SetDynamicObjectRot,
		(int objectid, float rx, float ry, float rz),
		(objectid, rx, ry, rz)
	);
DECLARE_SMART_NATIVE(MoveDynamicObject,
		(int objectid, float x, float y, float z, float speed, float rx = -1000.0, float ry = -1000.0, float rz = -1000.0),
		(objectid, x, y, z, speed, rx, ry, rz)
	);
DECLARE_SMART_NATIVE(StopDynamicObject,
		(int objectid),
		(objectid)
	);
DECLARE_SMART_NATIVE(IsDynamicObjectMoving,
		(int objectid),
		(objectid)
	);
DECLARE_SMART_NATIVE(AttachCameraToDynamicObject,
		(int playerid, int objectid),
		(playerid, objectid)
	);
DECLARE_SMART_NATIVE(AttachDynamicObjectToObject,
		(int objectid, int attachtoid, float offsetx, float offsety, float offsetz, float rx, float ry, float rz, int syncrotation = 1),
		(objectid, attachtoid, offsetx, offsety, offsetz, rx, ry, rz, syncrotation)
	);
DECLARE_SMART_NATIVE(AttachDynamicObjectToPlayer,
		(int objectid, int playerid, float offsetx, float offsety, float offsetz, float rx, float ry, float rz),
		(objectid, playerid, offsetx, offsety, offsetz, rx, ry, rz)
	);
DECLARE_SMART_NATIVE(AttachDynamicObjectToVehicle,
		(int objectid, int vehicleid, float offsetx, float offsety, float offsetz, float rx, float ry, float rz),
		(objectid, vehicleid, offsetx, offsety, offsetz, rx, ry, rz)
	);
DECLARE_SMART_NATIVE(EditDynamicObject,
		(int playerid, int objectid),
		(playerid, objectid)
	);
DECLARE_SMART_NATIVE(IsDynamicObjectMaterialUsed,
		(int objectid, int materialindex),
		(objectid, materialindex)
	);
DECLARE_SMART_NATIVE(RemoveDynamicObjectMaterial,
		(int objectid, int materialindex),
		(objectid, materialindex)
	);
// DECLARE_SMART_NATIVE(GetDynamicObjectMaterial,
// 		(int objectid, int materialindex, int* modelid, char* txdname, char* texturename, int* materialcolor, int maxtxdname = sizeof txdname, maxtexturename = sizeof texturename),
// 		(objectid, materialindex, &modelid, txdname[], texturename[], &materialcolor, maxtxdname = sizeof txdname, maxtexturename = sizeof texturename)
// 	);
DECLARE_SMART_NATIVE(SetDynamicObjectMaterial,
		(int objectid, int materialindex, int modelid, char const* txdname, char const* texturename, int materialcolor = 0),
		(objectid, materialindex, modelid, txdname, texturename, materialcolor)
	);
DECLARE_SMART_NATIVE(IsDynamicObjectMaterialTextUsed,
		(int objectid, int materialindex),
		(objectid, materialindex)
	);
DECLARE_SMART_NATIVE(RemoveDynamicObjectMaterialText,
		(int objectid, int materialindex),
		(objectid, materialindex)
	);
// DECLARE_SMART_NATIVE(GetDynamicObjectMaterialText,
// 		(int objectid, int materialindex, text[], &materialsize, fontface[], &fontsize, &bold, &fontcolor, &backcolor, &textalignment, maxtext = sizeof text, maxfontface = sizeof fontface),
// 		(objectid, materialindex, text[], &materialsize, fontface[], &fontsize, &bold, &fontcolor, &backcolor, &textalignment, maxtext = sizeof text, maxfontface = sizeof fontface)
// 	);
DECLARE_SMART_NATIVE(SetDynamicObjectMaterialText,
		(int objectid, int materialindex, char const* text, int materialsize = OBJECT_MATERIAL_SIZE_256x128, char const* fontface = "Arial", int fontsize = 24, int bold = 1, int fontcolor = 0xFFFFFFFF, int backcolor = 0, int textalignment = 0),
		(objectid, materialindex, text, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment)
	);
DECLARE_SMART_NATIVE(GetPlayerCameraTargetDynObject,
		(int playerid),
		(playerid)
	);



class DynamicObject
{
public:
	DynamicObject() = default;
	DynamicObject(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(DynamicObject const& other_) const { return _id == other_._id; }
	bool operator!=(DynamicObject const& other_) const { return !(*this == other_); }

	int32_t id() const { return _id; }

	float dist(Vec3f const& pos_) const { return this->pos().distanceSquared(pos_); }

	// A shorthand for this->getRotation()
	Vec3f rot() const { return this->getRotation(); }

	// A shorthand for this->getPosition()
	Vec3f pos() const { return this->getPosition(); }

	static DynamicObject create(int modelIdx_, Vec3f const& pos_, Vec3f const& rot_, int worldIdx_ = -1, int interiorIdx_ = -1, samp_cpp::Player player_ = {}, float streamDistance_ = STREAMER_OBJECT_SD, float drawDistance_ = STREAMER_OBJECT_DD, int areaIdx_ = -1, int priority_ = 0);
	static DynamicObject create(int modelIdx_, float x_, float y_, float z_, float rX_, float rY_, float rZ_, int worldIdx_ = -1, int interiorIdx_ = -1, samp_cpp::Player player_ = {}, float streamDistance_ = STREAMER_OBJECT_SD, float drawDistance_ = STREAMER_OBJECT_DD, int areaIdx_ = -1, int priority_ = 0);
	bool attachToVehicle(samp_cpp::Vehicle vehicle_, Vec3f const& offset_, Vec3f const& rot_);
	bool attachToVehicle(samp_cpp::Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_);
	bool attachToObject(DynamicObject attachTo_, Vec3f const& offset_, Vec3f const& rot_, bool syncRotation_);
	bool attachToObject(DynamicObject attachTo_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_, bool syncRotation_);
	bool attachToPlayer(samp_cpp::Player player_, Vec3f const& offset_, Vec3f const& rot_);
	bool attachToPlayer(samp_cpp::Player player_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_);
	bool setPosition(Vec3f const& pos_);
	bool setPosition(float x_, float y_, float z_);
	Vec3f getPosition() const;
	bool setRotation(Vec3f const& rot_);
	bool setRotation(float rotX_, float rotY_, float rotZ_);
	Vec3f getRotation() const;
	// int getModel() const;
	// bool setNoCameraCol();
	bool valid() const;
	bool destroy();
	int move(Vec3f const& targetPos_, float speed_, Vec3f rot_ = {-1000.f, -1000.f, -1000.f});
	int move(float x_, float y_, float z_, float speed_, float rotX_ = -1000.f, float rotY_ = -1000.f, float rotZ_ = -1000.f);
	bool stop();
	bool isMoving() const;
	bool setMaterial(int materialIndex_, int modelIdx_, std::string const& txdName_, std::string const& textureName_, samp_cpp::Color materialColor_);
	bool setMaterial(int materialIndex_, int modelIdx_, char const* txdName_, char const* textureName_, samp_cpp::Color materialColor_);
	bool setMaterialText(std::string const& text_, int materialIndex_,
			int materialSize_,
			std::string const& fontFace_ = "Arial", int fontSize_ = 24, bool bold_ = true,
			samp_cpp::Color fontColor_ = samp_cpp::colors::white,
			samp_cpp::Color backColor_ = samp_cpp::colors::transparent,
			int textAlignment_ = 0);

	bool setMaterialText(char const* text_, int materialIndex_,
			int materialSize_ = OBJECT_MATERIAL_SIZE_256x128,
			char const* fontFace_ = "Arial", int fontSize_ = 24, bool bold_ = true,
			samp_cpp::Color fontColor_ = samp_cpp::colors::white,
			samp_cpp::Color backColor_ = samp_cpp::colors::transparent,
			int textAlignment_ = 0
		);

private:
	int32_t _id = -1;
};


}