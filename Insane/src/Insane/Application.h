#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Insane {

	class INSANE_API Application
	{
	public:
		Application();
		virtual ~Application();  // will be subclassed by Sandbox Application

		void Run();
	private:
		std::unique_ptr<Window> m_Window;  // is platform independent
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

