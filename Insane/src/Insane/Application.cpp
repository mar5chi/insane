#include "Application.h"

#include "Insane/Events/ApplicationEvent.h"
#include "Insane/Log.h"

namespace Insane {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		IS_TRACE(e.ToString());

		while (true) {};
	}

}