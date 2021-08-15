#pragma once

#include SAMPSTREAMER_PCH

#include <SAMPStreamer/DataManipulation.hpp>

namespace samp_streamer
{

template <StreamableType EStreamableType>
class Streamable
{
public:
	static constexpr StreamableType StreamableType = EStreamableType;

	Streamable() = default;
	Streamable(int32_t id_)
		: _id(id_)
	{
	}


	bool 	getFloatData(FieldType fieldType_, float& value_) const;
	bool 	setFloatData(FieldType fieldType_, float value_);
	int 	getIntData(FieldType fieldType_) const;
	bool 	setIntData(FieldType fieldType_, int value_);
	
	static int getUpperBound();

	int32_t id() const { return _id; }
protected:
	int32_t _id;
};

}