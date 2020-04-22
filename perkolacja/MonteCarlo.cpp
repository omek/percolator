#include "MonteCarlo.h"
#include "SiatkaProstokatna.h"
#include <iostream>
#include <vector>
MonteCarlo::MonteCarlo(int ilosc, std::vector<int> wektor_prawdopodobienstw, int w, int h):ilosc_symulacji(ilosc),wektor_p(wektor_prawdopodobienstw),Width(w),Heigth(h){}

std::vector<int> MonteCarlo::Symulacja() {

	int wynik = 0;
	std::vector<int>Wyniki(wektor_p.size()*ilosc_symulacji);

	for (int z = 0; z < wektor_p.size(); z++) {
		for (int i = 0; i < ilosc_symulacji; i++) {
			SiatkaProstokatna s(Width, Heigth, wektor_p[z]);
			if (s.sprawdz()) {
				wynik++;
				Wyniki[z] = wynik;
			}
		}
		wynik = 0;
	}
	return Wyniki;
}

MonteCarlo::~MonteCarlo(){
	
}