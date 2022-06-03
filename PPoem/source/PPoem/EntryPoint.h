#pragma once

#ifdef PP_PLATFORM_WINDOWS

//extern PPoem::Application* PPoem::CreateApplication();

int main(int argc, char** argv) {
	auto app = PPoem::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error PPoem only support Windows!
#endif // PP_PLATFORM_WINDOWS
