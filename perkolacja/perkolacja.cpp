
#include <iostream>
#include <time.h>
#include "SiatkaProstokatna.h"
int main()
{
	std::srand(time(NULL));
	SiatkaProstokatna obj(100,100,60);
	obj.pokaz();
	obj.sprawdz();
	std::cin.get();
	return 0;
}

