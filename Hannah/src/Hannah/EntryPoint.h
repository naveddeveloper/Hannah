#pragma once

#ifdef HN_PLATFORM_WINDOWS

extern Hannah::Application* Hannah::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hannah Engine\n");
	auto app = Hannah::CreateApplication();
	app->Run();
	delete app;
}


#endif