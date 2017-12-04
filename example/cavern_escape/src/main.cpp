#include "Main.hpp"

int main(int ac, char ** av)
{
	Main engine;

	if (engine.init(ac, av) == false)
		return 1;
	return engine.run();
}
