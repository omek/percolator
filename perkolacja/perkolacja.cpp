
#include <iostream>
#include <time.h>
#include <chrono>
#include "SiatkaProstokatna.h"
#include "MonteCarlo.h"

int main()
{
	std::srand(time(NULL));
	int x = 10;
	int y = 10;
	int iloscSymulacji = 10000;
	std::vector<int>iPerkolacja;
	std::vector<int>WynikiSymulacji;

	for (int i = 0; i < 100; i += 10){
		iPerkolacja.push_back(i);
	}

	MonteCarlo s(iloscSymulacji, iPerkolacja, x, y);

	auto start = std::chrono::high_resolution_clock::now();
	WynikiSymulacji = s.Symulacja();
	auto stop = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

	for (int i = 0; i < iPerkolacja.size(); i++) {
		float wynik = WynikiSymulacji[i] * 100 / iloscSymulacji;
		std::cout <<"Dla "<<iPerkolacja[i]<<"% perkolacji "<< wynik<<"% symulacji powiodlo sie." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Czas trwania symulacji: " << dur.count() <<" milisekund"<< std::endl;

	std::cin.get();
	return 0;
}

