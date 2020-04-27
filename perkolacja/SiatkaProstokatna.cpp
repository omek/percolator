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

bool SiatkaProstokatna::sprawdzRekurencja(std::vector<std::vector<bool>> &siatka_bazowa, std::vector<std::vector<bool>> &siatka_perkolacji, int h, int w) {
	siatka_perkolacji[h][w] = true;

	if (h == Height - 1)
		return true;
	
	if (h < Height - 1) {
		if (siatka_bazowa[h + 1][w] && !siatka_perkolacji[h + 1][w]) {
			if (sprawdzRekurencja(siatka_bazowa, siatka_perkolacji, h + 1, w))
				return true;
		}
	}
	if (w < Width - 1) {
		if (siatka_bazowa[h][w + 1] && !siatka_perkolacji[h][w + 1]) {
			if (sprawdzRekurencja(siatka_bazowa, siatka_perkolacji, h, w + 1))
				return true;
		}
	}
	if (w > 0) {
		if (siatka_bazowa[h][w - 1] && !siatka_perkolacji[h][w - 1]) {
			if (sprawdzRekurencja(siatka_bazowa, siatka_perkolacji, h, w - 1))
				return true;
		}
	}
	if (h > 0) {
		if (siatka_bazowa[h - 1][w] && !siatka_perkolacji[h - 1][w]) {
			if (sprawdzRekurencja(siatka_bazowa, siatka_perkolacji, h - 1, w))
				return true;
		}
	}
	return false;
}

bool SiatkaProstokatna::sprawdz(std::vector<std::vector<bool>> sP) {
	bool test = false;
	for (int i = 0; i < siatka_bazowa[0].size(); i++)
		if (siatka_bazowa[0][i] && !test)
			test = sprawdzRekurencja(siatka_bazowa, sP, 0, i);
	return test;
}


SiatkaProstokatna::~SiatkaProstokatna() { }
