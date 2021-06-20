#include SAMPSTREAMER_PCH

#include <SAMPStreamer/Objects.hpp>

namespace samp_streamer
{

////////////////////////////////////
samp_cpp::NativeLoader::NativeMap& getNatives()
{
	static samp_cpp::NativeLoader::NativeMap instance({
		{ "CreateDynamicObject", &CreateDynamicObject }
	});

	return instance;
}

}