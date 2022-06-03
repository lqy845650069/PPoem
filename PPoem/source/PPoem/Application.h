#pragma once
#include "Core.h"

namespace PPoem {
	class PPOEM_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


