#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Pickup.hpp>

namespace samp_streamer
{

////////////////////////////////////////////////
DynamicPickup DynamicPickup::create(int modelIdx_, samp_cpp::Pickup::Type type_, Vec3f const& pos_, int virtualWorld_, int interiorIdx_, int playerIdx_, float streamDistance_, int areaIdx_, int priority_)
{
	return DynamicPickup::create(modelIdx_, type_, pos_.x, pos_.y, pos_.z, virtualWorld_, interiorIdx_, playerIdx_, streamDistance_, areaIdx_, priority_);
}

////////////////////////////////////////////////
DynamicPickup DynamicPickup::create(int modelIdx_, samp_cpp::Pickup::Type type_, float x_, float y_, float z_, int virtualWorld_, int interiorIdx_, int playerIdx_, float streamDistance_, int areaIdx_, int priority_)
{
	return DynamicPickup{
		CreateDynamicPickup(modelIdx_, static_cast<int>(type_), x_, y_, z_, virtualWorld_, interiorIdx_, playerIdx_, streamDistance_, areaIdx_, priority_)
	};
}

////////////////////////////////////////////////
bool DynamicPickup::valid() const
{
	return _id != -1 && static_cast<bool>( IsValidDynamicPickup(_id) );
}

////////////////////////////////////////////////
bool DynamicPickup::destroy()
{
	return static_cast<bool>( DestroyDynamicPickup(_id) );
}

}