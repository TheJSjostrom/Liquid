#include <Liquid.h>
#include "Liquid/Events/Event.h"
#include "Liquid/Events/MouseEvent.h"

class ExampleLayer : public Liquid::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//LQ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Liquid::Event& event) override
	{
		LQ_TRACE("{0}", event);
	}


};

class Sandbox : public Liquid::Application
{

public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Liquid::ImGuiLayer);
	}

	~Sandbox() 
	{
	}
	
};
  
Liquid::Application* Liquid::CreateApplication()
{
	return new Sandbox();
}
 