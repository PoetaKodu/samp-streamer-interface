#pragma once

#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Constants.hpp>
#include <SAMPStreamer/Streamable.hpp>

namespace samp_streamer
{

DECLARE_SMART_NATIVE(CreateDynamic3DTextLabel,
		(char const* text, int color, float x, float y, float z, float drawdistance, int attachedplayer = INVALID_PLAYER_ID, int attachedvehicle = INVALID_VEHICLE_ID, int testlos = 0, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = TextLabel3DStreamDist, int areaid = -1, int priority = 0 ),
		(text, color, x, y, z, drawdistance, attachedplayer, attachedvehicle, testlos, worldid, interiorid, playerid, streamdistance, areaid, priority)
	);
DECLARE_SMART_NATIVE(DestroyDynamic3DTextLabel,
		(int id),
		(id)
	);
DECLARE_SMART_NATIVE(IsValidDynamic3DTextLabel,
		(int id),
		(id)
	);
// DECLARE_SMART_NATIVE(GetDynamic3DTextLabelText,
// 		(int id, char * text, int maxtext),
// 		(id, text, maxtext)
// 	);
DECLARE_SMART_NATIVE(UpdateDynamic3DTextLabelText,
		(int id, int color, char const* text),
		(id, color, text)
	);

class DynamicTextLabel3D
	: public Streamable<StreamableType::TextLabel3D>
{
public:
	using Streamable::Streamable;

	bool operator==(DynamicTextLabel3D const& other_) const { return _id == other_._id; }
	bool operator!=(DynamicTextLabel3D const& other_) const { return !(*this == other_); }

	static DynamicTextLabel3D create(
			std::string const& text_,
			samp_cpp::Color color_,
			Vec3f const& pos_,
			float drawDistance_ 				= 100,
			samp_cpp::Player attachedPlayer_ 	= INVALID_PLAYER_ID,
			samp_cpp::Vehicle attachedVeh_ 		= INVALID_VEHICLE_ID,
			bool testLos_ 						= true,
			int virtualWorld_ 					= 0,
			int interiorIdx_ 					= -1,
			samp_cpp::Player player_ 			= INVALID_PLAYER_ID,
			float streamDistance_ 				= TextLabel3DStreamDist,
			int areaIdx_						= -1,
			int priority_ 						= 0
		);
	static DynamicTextLabel3D create(
			char const* text_,
			samp_cpp::Color color_,
			float x_, float y_, float z_,
			float drawDistance_ 				= 100,
			samp_cpp::Player attachedPlayer_ 	= INVALID_PLAYER_ID,
			samp_cpp::Vehicle attachedVeh_ 		= INVALID_VEHICLE_ID,
			bool testLos_ 						= true,
			int virtualWorld_ 					= 0,
			int interiorIdx_ 					= -1,
			samp_cpp::Player player_ 			= INVALID_PLAYER_ID,
			float streamDistance_ 				= TextLabel3DStreamDist,
			int areaIdx_ 						= -1,
			int priority_ 						= 0
		);
	bool destroy();
	bool valid() const;

	// TODO: add GetDynamic3DTextLabel

	bool attachTo(samp_cpp::Player player_, Vec3f const& offset_);
	bool attachTo(samp_cpp::Player player_, float offsetX_, float offsetY_, float offsetZ_);
	bool attachTo(samp_cpp::Vehicle vehicle_, Vec3f const& offset_);
	bool attachTo(samp_cpp::Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_);
	bool updateText(samp_cpp::Color color_, std::string const& text_);
	bool updateText(samp_cpp::Color color_, char const* text_);
};

}