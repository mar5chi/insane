#pragma once

#ifdef IS_PLATFORM_WINDOWS

extern Insane::Application* Insane::CreateApplication();

int main(int argc, char** argv) {			// entry point
	//printf("Insane Engine\n");

	Insane::Log::Init();
	IS_CORE_WARN("Initialized Log!");
	int a = 5;	
	IS_INFO("Hello Var={0}", a);  // Test with some variable

	auto app = Insane::CreateApplication();
	app->Run();
	delete app;
}

#endif