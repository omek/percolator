
#include <iostream>
#include <time.h>
#include "SiatkaProstokatna.h"
#include "MonteCarlo.h"
int main()
{
	std::srand(time(NULL));
	//SiatkaProstokatna obj(200,100,60);
	//obj.pokaz();
	//obj.sprawdz();
	std::vector<int>iPerkolacja;
	for (int i = 0; i < 100; i += 10){
		iPerkolacja.push_back(i);
	}
	MonteCarlo s(100, iPerkolacja, 50, 50);
	s.Symulacja();
	std::cin.get();
	return 0;
}

