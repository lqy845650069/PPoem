#include <PPoem.h>
class Sandbox : public PPoem::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

PPoem::Application* PPoem::CreateApplication() {
	return new Sandbox();
}