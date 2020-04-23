#include "MonteCarlo.h"
#include "SiatkaProstokatna.h"
#include <iostream>
#include <vector>
#include <algorithm>
MonteCarlo::MonteCarlo(int ilosc, std::vector<int> wektor_prawdopodobienstw, int w, int h):ilosc_symulacji(ilosc),wektor_p(wektor_prawdopodobienstw),Width(w),Height(h){}

std::vector<int> MonteCarlo::Symulacja() {

	std::vector<int>Wyniki(wektor_p.size()*ilosc_symulacji);
	SiatkaProstokatna s(Width, Height);
	std::vector<std::vector<bool>>siatka_perkolacji(Height, std::vector<bool>(Width));

	for (int z = 0; z < wektor_p.size(); z++) {
		int wynik = 0;
		for (int i = 0; i < ilosc_symulacji; i++) {
			s.losuj(wektor_p[z]);
			if (s.sprawdz(siatka_perkolacji)) {
				wynik++;
				Wyniki[z] = wynik;
			}
		}

		for (int f = 0; f < siatka_perkolacji.size(); f++) {
			for (int t = 0; t < siatka_perkolacji[f].size(); t++) {
				siatka_perkolacji[f][t] = false;
			}
		}
	}
	return Wyniki;
}

MonteCarlo::~MonteCarlo(){
	
}