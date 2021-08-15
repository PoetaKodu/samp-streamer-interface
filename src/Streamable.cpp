#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Streamable.hpp>

namespace samp_streamer
{

////////////////////////////////////////////////
template <StreamableType EStreamableType>
bool Streamable<EStreamableType>::getFloatData(FieldType fieldType_, float& value_) const
{
	return static_cast<bool>( Streamer_GetFloatData(static_cast<int>(EStreamableType), _id, static_cast<int>(fieldType_), &value_) );
}

////////////////////////////////////////////////
template <StreamableType EStreamableType>
bool Streamable<EStreamableType>::setFloatData(FieldType fieldType_, float value_)
{
	return static_cast<bool>( Streamer_SetFloatData(static_cast<int>(EStreamableType), _id, static_cast<int>(fieldType_), value_) );
}

////////////////////////////////////////////////
template <StreamableType EStreamableType>
int Streamable<EStreamableType>::getIntData(FieldType fieldType_) const
{
	return Streamer_GetIntData(static_cast<int>(EStreamableType), _id, static_cast<int>(fieldType_));
}

////////////////////////////////////////////////
template <StreamableType EStreamableType>
bool Streamable<EStreamableType>::setIntData(FieldType fieldType_, int value_)
{
	return static_cast<bool>( Streamer_SetIntData(static_cast<int>(EStreamableType), _id, static_cast<int>(fieldType_), value_) );
}

////////////////////////////////////////////////
template <StreamableType EStreamableType>
int Streamable<EStreamableType>::getUpperBound()
{
	return Streamer_GetUpperBound(static_cast<int>(EStreamableType));
}

// Instantiate streamable classes
template Streamable<StreamableType::Object>;
template Streamable<StreamableType::Pickup>;
template Streamable<StreamableType::Checkpoint>;
template Streamable<StreamableType::RaceCheckpoint>;
template Streamable<StreamableType::MapIcon>;
template Streamable<StreamableType::TextLabel3D>;
template Streamable<StreamableType::Area>;
template Streamable<StreamableType::Actor>;

}