#pragma once

#ifdef PP_PLATFORM_WINDOWS

//extern PPoem::Application* PPoem::CreateApplication();

int main(int argc, char** argv)
{
	PPoem::Log::Init();
	PP_CORE_WARN("Initialized Log!");
	int a = 5;
	PP_INFO("Hello! Var = {0}", a);

	auto app = PPoem::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error PPoem only support Windows!
#endif // PP_PLATFORM_WINDOWS
