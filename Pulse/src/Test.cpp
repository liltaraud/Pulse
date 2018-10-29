#include <iostream>

namespace Pulse {

	__declspec(dllexport)	void		Print();

	void		Print()
	{
		std::cout << "Hello form the Pulse engine";
	}
}