#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Constants.hpp>

namespace samp_streamer
{

DECLARE_SMART_NATIVE(Streamer_GetFloatData,
		(int type, int id, int data, float* result),
		(type, id, data, result)
	);

DECLARE_SMART_NATIVE(Streamer_SetFloatData,
		(int type, int id, int data, float value),
		(type, id, data, value)
	);

DECLARE_SMART_NATIVE(Streamer_GetIntData,
		(int type, int id, int data),
		(type, id, data)
	);

DECLARE_SMART_NATIVE(Streamer_SetIntData,
		(int type, int id, int data, int value),
		(type, id, data, value)
	);

DECLARE_SMART_NATIVE(Streamer_GetUpperBound,
		(int type),
		(type)
	);


}