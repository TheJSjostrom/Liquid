#pragma once

#ifdef LQ_PLATFORM_WINDOWS

extern Liquid::Application* Liquid::CreateApplication();

int main(int argc, char** argv)
{
	 
	auto app = Liquid::CreateApplication();
	app->Run();
	delete app;

}

#endif