#include "ispch.h"
#include "Application.h"

#include "Insane/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Insane {

	Application::Application()
	{
		//m_Window = Window::Create();
		m_Window = std::unique_ptr<Window>(Window::Create());  // because it's an explicit constructor: unique_ptr needed
		// means we dont have to delete the window ourself when the application terminates
		// it's kind of a Singleton
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		//WindowResizeEvent e(1280, 720);
		//if (e.IsInCategory(EventCategoryApplication)) {
		//	IS_TRACE(e.ToString());
		//}
		//if (e.IsInCategory(EventCategoryInput)) {
		//	IS_TRACE(e.ToString());
		//}
		
		while (m_Running) {
			glClearColor(0, 0.5, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		};
	}

}