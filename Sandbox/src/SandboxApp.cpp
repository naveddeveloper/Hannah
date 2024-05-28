#include <Hannah.h>

class Sandbox : public Hannah::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Hannah::Application* Hannah::CreateApplication()
{
	return new Sandbox();
}