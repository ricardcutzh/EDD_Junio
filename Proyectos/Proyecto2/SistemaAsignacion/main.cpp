#include "sistemaasignacion.h"

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
	return new SistemaAsignacion(env);
}

int main(int argc, char *argv[])
{
	return Wt::WRun(argc, argv, &createApplication);
}
