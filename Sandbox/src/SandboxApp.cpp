 
#include <Liquid.h>
 
class Sandbox : public Liquid::Application
{

public:
	Sandbox() 
	{
	
	}
	~Sandbox() 
	{
	
	}
	
};
  
Liquid::Application* Liquid::CreateApplication()
{
	return new Sandbox();
}
 