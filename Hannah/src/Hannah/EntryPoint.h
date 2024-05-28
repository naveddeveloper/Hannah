#pragma once

#ifdef HN_PLATFORM_WINDOWS

extern Hannah::Application* Hannah::CreateApplication();

int main(int argc, char** argv)
{
	Hannah::Log::Init();
	HN_CORE_WARN("Initialized Log!");
	int a = 5;
	HN_INFO("Hello! Var={0}", a);

	auto app = Hannah::CreateApplication();
	app->Run();
	delete app;
}


#endif