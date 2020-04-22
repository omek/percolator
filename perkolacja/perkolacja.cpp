
#include <iostream>
#include <time.h>
#include "SiatkaProstokatna.h"
#include "MonteCarlo.h"

int main()
{
	std::srand(time(NULL));
	int x = 10;
	int y = 10;
	int iloscSymulacji = 100;
	std::vector<int>iPerkolacja;
	std::vector<int>WynikiSymulacji;
	for (int i = 0; i < 100; i += 10){
		iPerkolacja.push_back(i);
	}
	MonteCarlo s(iloscSymulacji, iPerkolacja, x, y);
	WynikiSymulacji = s.Symulacja();
	for (int i = 0; i < iPerkolacja.size(); i++) {
		std::cout <<"Dla "<<iPerkolacja[i]<<"% perkolacji "<< WynikiSymulacji[i]<<"% symulacji powiodlo sie." << std::endl;
	}
	std::cin.get();
	return 0;
}

