#include "SiatkaProstokatna.h"

#include <iostream>

SiatkaProstokatna::SiatkaProstokatna(int w, int h):siatka_bazowa(h, std::vector<bool>(w,false)),Width(w),Height(h) {
}

void SiatkaProstokatna::losuj(int prawdopodobienstwo){
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			siatka_bazowa[i][j] = (rand() % 100 <= prawdopodobienstwo);
		}
	}
}

void SiatkaProstokatna::pokaz() {
	for (int i = 0; i < siatka_bazowa.size(); i++) {
		for (int j = 0; j < siatka_bazowa[i].size(); j++) {
			std::cout << siatka_bazowa[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


bool SiatkaProstokatna::sprawdz() {

	std::vector<std::vector<bool>>siatka_perkolacji(Height, std::vector<bool>(Width));
	for (int i = 0; i < siatka_bazowa[0].size(); i++)
		if (siatka_bazowa[0][i])
			siatka_perkolacji[0][i] = true;

	bool zmiana = true;
	while (zmiana) {
		zmiana = false;
		for (int i = 0; i < siatka_bazowa.size(); i++) {
			for (int j = 0; j < siatka_bazowa[i].size(); j++) {
				if (siatka_perkolacji[i][j]) {
					if (i < Height - 1) {
						if (siatka_bazowa[i + 1][j] && !siatka_perkolacji[i + 1][j]) {
							siatka_perkolacji[i + 1][j] = true;
							zmiana = true;
						}
					}
					if (j < Width - 1) {
						if (siatka_bazowa[i][j + 1] && !siatka_perkolacji[i][j + 1]) {
							siatka_perkolacji[i][j + 1] = true;
							zmiana = true;
						}
					}
					if (j > 0) {
						if (siatka_bazowa[i][j - 1] && !siatka_perkolacji[i][j - 1]) {
							siatka_perkolacji[i][j - 1] = true;
							zmiana = true;
						}
					}
					if (i > 0) {
						if (siatka_bazowa[i - 1][j] && !siatka_perkolacji[i - 1][j]) {
							siatka_perkolacji[i - 1][j] = true;
							zmiana = true;
						}
					}
				}
			}
		}
	}
	
	//wydruk macierzy po sprawdzaniu
	/*
	for (int i = 0; i < siatka_perkolacji.size(); i++) {
		for (int j = 0; j < siatka_perkolacji[i].size(); j++) {
			std::cout << siatka_perkolacji[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/

	bool perk = false;
	for (int j = 0; j < Width - 1; j++) {
		if (siatka_perkolacji[Height - 1][j])
			perk = true;
	}
	if (perk)
		return true;
	else
		return false;
}


SiatkaProstokatna::~SiatkaProstokatna() { }
