#include "ispch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Insane {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		//m_Window = Window::Create();
		m_Window = std::unique_ptr<Window>(Window::Create());  // because it's an explicit constructor: unique_ptr needed
		// means we dont have to delete the window ourself when the application terminates
		// it's kind of a Singleton

		// dispatch Event 
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()
	{
	}

	// Event callback
	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		IS_CORE_TRACE("{0}", e);  // Log all events
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

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

}