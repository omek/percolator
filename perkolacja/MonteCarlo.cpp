#include "MonteCarlo.h"
#include "SiatkaProstokatna.h"
#include <iostream>
#include <vector>
MonteCarlo::MonteCarlo(int ilosc, std::vector<int> wektor_prawdopodobienstw, int w, int h):ilosc_symulacji(ilosc),wektor_p(wektor_prawdopodobienstw),Width(w),Heigth(h){}

void MonteCarlo::Symulacja() {
	float wynik = 0;
	for (int z = 0; z < wektor_p.size(); z++) {
		for (int i = 0; i < ilosc_symulacji; i++) {
			SiatkaProstokatna s(Width, Heigth, wektor_p[z]);
			if (s.sprawdz())
				wynik++;
		}
		float odsetek = wynik / ilosc_symulacji * 100;
		std::cout << "Na " << ilosc_symulacji << " przeprowadzonych symulacji  " << wynik << " dalo wynik pozytywny, i jest to " << odsetek << "% wszystkich przypadkow." << std::endl;
		std::cout << "Prawdopodobienstwo przeciekania: " << wektor_p[z] << std::endl;
		std::cout << std::endl;
		wynik = 0;
	}
	std::cout << std::endl;
	std::cout << "Skonczone!" << std::endl;
}

MonteCarlo::~MonteCarlo(){
	
}