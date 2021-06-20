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


}