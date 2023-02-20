#include <Insane.h>

class Sandbox : public Insane::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Insane::Application* Insane::CreateApplication() {
	return new Sandbox();
}