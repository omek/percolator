#include "MonteCarlo.h"
#include "SiatkaProstokatna.h"
#include <iostream>
#include <vector>
MonteCarlo::MonteCarlo(int ilosc, std::vector<int> wektor_prawdopodobienstw, int w, int h):ilosc_symulacji(ilosc),wektor_p(wektor_prawdopodobienstw),Width(w),Heigth(h){}

std::vector<int> MonteCarlo::Symulacja() {

	
	std::vector<int>Wyniki(wektor_p.size()*ilosc_symulacji);
	SiatkaProstokatna s(Width, Heigth);
	for (int z = 0; z < wektor_p.size(); z++) {
		int wynik = 0;
		for (int i = 0; i < ilosc_symulacji; i++) {
			s.losuj(wektor_p[z]);
			if (s.sprawdz()) {
				wynik++;
				Wyniki[z] = wynik;
			}
		}
	}
	return Wyniki;
}

MonteCarlo::~MonteCarlo(){
	
}