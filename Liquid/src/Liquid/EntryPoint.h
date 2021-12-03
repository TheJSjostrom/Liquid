#pragma once

#ifdef LQ_PLATFORM_WINDOWS

extern Liquid::Application* Liquid::CreateApplication();

int main(int argc, char** argv)
{
	 
	Liquid::Log::Init();

	LQ_CORE_WARN("Initialized Log!");
	int a = 2;
	LQ_INFO("Hello! Var={0}", 0);

	auto app = Liquid::CreateApplication();
	app->Run();
	delete app;
	 
}

#endif