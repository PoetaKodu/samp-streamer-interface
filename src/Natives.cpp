#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Objects.hpp>
#include <SAMPStreamer/Pickup.hpp>
#include <SAMPStreamer/TextLabel3D.hpp>

namespace samp_streamer
{

////////////////////////////////////
samp_cpp::NativeLoader::NativeMap& getNatives()
{
	static samp_cpp::NativeLoader::NativeMap instance({
		// Objects:
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
		
		// Pickups:
		{ "CreateDynamicPickup", 				&CreateDynamicPickup },
		{ "DestroyDynamicPickup", 				&DestroyDynamicPickup },
		{ "IsValidDynamicPickup", 				&IsValidDynamicPickup },

		// Text Labels 3D:
		{ "CreateDynamic3DTextLabel", 			&CreateDynamic3DTextLabel },
		{ "DestroyDynamic3DTextLabel", 			&DestroyDynamic3DTextLabel },
		{ "IsValidDynamic3DTextLabel", 			&IsValidDynamic3DTextLabel },
		// { "GetDynamic3DTextLabelText", 			&GetDynamic3DTextLabelText },
		{ "UpdateDynamic3DTextLabelText", 		&UpdateDynamic3DTextLabelText },
	});

	return instance;
}

}