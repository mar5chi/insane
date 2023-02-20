#pragma once

#ifdef IS_PLATFORM_WINDOWS

extern Insane::Application* Insane::CreateApplication();

int main(int argc, char** argv) {			// entry point
	//printf("Insane Engine\n");
	auto app = Insane::CreateApplication();
	app->Run();
	delete app;
}

#endif