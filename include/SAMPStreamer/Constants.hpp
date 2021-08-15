#pragma once

namespace samp_streamer
{

constexpr inline float ObjectStreamDist 			= 300.0f;
constexpr inline float ObjectDrawDistance 			= 0.0f;
constexpr inline float PickupStreamDist 			= 200.0f;
constexpr inline float CheckpointStreamDist 		= 200.0f;
constexpr inline float RaceCheckpointStreamDist 	= 200.0f;
constexpr inline float MapIconStreamDist 			= 200.0f;
constexpr inline float TextLabel3DStreamDist 		= 200.0f;
constexpr inline float ActorStreamDist 				= 200.0f;

enum class StreamableType
{
	Object			= 0,
	Pickup			= 1,
	Checkpoint		= 2,
	RaceCheckpoint	= 3,
	MapIcon			= 4,
	TextLabel3D		= 5,
	Area			= 6,
	Actor			= 7,
};

enum class FieldType
{
	AreaId,
	AttachedObject,
	AttachedPlayer,
	AttachedVehicle,
	AttachOffsetX,
	AttachOffsetY,
	AttachOffsetZ,
	AttachRX,
	AttachRY,
	AttachRZ,
	AttachX,
	AttachY,
	AttachZ,
	Color,
	DrawDistance,
	ExtraId,
	Health,
	InteriorId,
	Invulnerable,
	MaxX,
	MaxY,
	MaxZ,
	MinX,
	MinY,
	MinZ,
	ModelId,
	MoveRX,
	MoveRY,
	MoveRZ,
	MoveSpeed,
	MoveX,
	MoveY,
	MoveZ,
	NextX,
	NextY,
	NextZ,
	PlayerId,
	Priority,
	Rotation,
	RX,
	RY,
	RZ,
	Size,
	StreamDistance,
	Style,
	SyncRotation,
	TestLos,
	Type,
	WorldId,
	X,
	Y,
	Z,
};


}