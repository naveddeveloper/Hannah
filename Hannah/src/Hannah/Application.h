#pragma once
#include "Core.h"

namespace Hannah {
	class HANNAH_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}
