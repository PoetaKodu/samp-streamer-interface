#pragma once

#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Constants.hpp>
#include <SAMPStreamer/Streamable.hpp>

namespace samp_streamer
{

DECLARE_SMART_NATIVE(CreateDynamicPickup,
		(int modelid, int type, float x, float y, float z, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = PickupStreamDist, int areaid = -1, int priority = 0),
		(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance, areaid, priority)
	);
DECLARE_SMART_NATIVE(DestroyDynamicPickup,
		(int pickupid),
		(pickupid)
	);
DECLARE_SMART_NATIVE(IsValidDynamicPickup,
		(int pickupid),
		(pickupid)
	);

class DynamicPickup
	: public Streamable<StreamableType::Pickup>
{
public:

	using Streamable::Streamable;

	bool operator==(DynamicPickup const& other_) const { return _id == other_._id; }
	bool operator!=(DynamicPickup const& other_) const { return !(*this == other_); }

	static DynamicPickup create(int modelIdx_, samp_cpp::Pickup::Type type_, Vec3f const& pos_, int virtualWorld_ = -1, int interiorIdx_ = -1, int playerIdx_ = -1, float streamDistance_ = PickupStreamDist, int areaIdx_ = 0, int priority_ = 0);
	static DynamicPickup create(int modelIdx_, samp_cpp::Pickup::Type type_, float x_, float y_, float z_, int virtualWorld_ = -1, int interiorIdx_ = -1, int playerIdx_ = -1, float streamDistance_ = PickupStreamDist, int areaIdx_ = 0, int priority_ = 0);

	bool valid() const;

	bool destroy();
};

}