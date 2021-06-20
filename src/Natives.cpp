#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Objects.hpp>

namespace samp_streamer
{

////////////////////////////////////
samp_cpp::NativeLoader::NativeMap& getNatives()
{
	static samp_cpp::NativeLoader::NativeMap instance({
		{ "CreateDynamicObject", 				&CreateDynamicObject },
		{ "CreateDynamicObject", 				&CreateDynamicObject },
		{ "DestroyDynamicObject", 				&DestroyDynamicObject },
		{ "IsValidDynamicObject", 				&IsValidDynamicObject },
		{ "GetDynamicObjectPos", 				&GetDynamicObjectPos },
		{ "SetDynamicObjectPos", 				&SetDynamicObjectPos },
		{ "GetDynamicObjectRot", 				&GetDynamicObjectRot },
		{ "SetDynamicObjectRot", 				&SetDynamicObjectRot },
		{ "MoveDynamicObject", 					&MoveDynamicObject },
		{ "StopDynamicObject", 					&StopDynamicObject },
		{ "IsDynamicObjectMoving", 				&IsDynamicObjectMoving },
		{ "AttachCameraToDynamicObject", 		&AttachCameraToDynamicObject },
		{ "AttachDynamicObjectToObject", 		&AttachDynamicObjectToObject },
		{ "AttachDynamicObjectToPlayer", 		&AttachDynamicObjectToPlayer },
		{ "AttachDynamicObjectToVehicle", 		&AttachDynamicObjectToVehicle },
		{ "EditDynamicObject", 					&EditDynamicObject },
		{ "IsDynamicObjectMaterialUsed", 		&IsDynamicObjectMaterialUsed },
		{ "RemoveDynamicObjectMaterial", 		&RemoveDynamicObjectMaterial },
		{ "SetDynamicObjectMaterial", 			&SetDynamicObjectMaterial },
		{ "IsDynamicObjectMaterialTextUsed", 	&IsDynamicObjectMaterialTextUsed },
		{ "RemoveDynamicObjectMaterialText", 	&RemoveDynamicObjectMaterialText },
		{ "SetDynamicObjectMaterialText", 		&SetDynamicObjectMaterialText },
		{ "GetPlayerCameraTargetDynObject", 	&GetPlayerCameraTargetDynObject },
	});

	return instance;
}

}