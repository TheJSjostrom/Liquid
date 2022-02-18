#include "lqpch.h"

#include "Liquid/Application.h"
#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Log.h"

#include "GLFW/glfw3.h"

namespace Liquid {

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{

	}
	 
	void Application::Run() 
	{
		while (m_Running)
		{
			glClearColor(1, 1, 0, 0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}