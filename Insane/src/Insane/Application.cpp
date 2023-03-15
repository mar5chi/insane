#include "ispch.h"
#include "Application.h"

#include "Insane/Events/ApplicationEvent.h"
#include "Insane/Log.h"

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
			m_Window->OnUpdate();
		};
	}

}