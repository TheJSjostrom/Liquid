#include "Application.h"

#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Log.h"

namespace Liquid {

	Application::Application() 
	{
	
	}

	Application::~Application() 
	{

	}
	 
	void Application::Run() 
	{
		WindowResizeEvent e(1200, 720);
		LQ_TRACE(e);
	}

}