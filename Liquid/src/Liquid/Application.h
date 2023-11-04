#pragma once

#include "Core.h"

#include "Window.h"
#include "Liquid/LayerStack.h"
#include "Liquid/Events/Event.h"
#include "Liquid/Events/ApplicationEvent.h"

namespace Liquid {

	class LIQUID_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	 
	// To be defined in client.
	Application* CreateApplication();

}
