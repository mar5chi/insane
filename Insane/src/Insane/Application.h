#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Insane {

	class INSANE_API Application
	{
	public:
		Application();
		virtual ~Application();  // will be subclassed by Sandbox Application

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

