#pragma once
#include <vector>
#include <time.h>
class SiatkaProstokatna {
public:
	SiatkaProstokatna(int w, int h);
	~SiatkaProstokatna();
	bool sprawdz(std::vector<std::vector<bool>>);
	void sprawdzRekurencja(std::vector<std::vector<bool>> &siatka_bazowa,std::vector<std::vector<bool>> &siatka_perkolacji, int h,int w);
	void pokaz();
	void losuj(int prawdopodobienstwo);
private:
	int Width;
	int Height;
	std::vector<std::vector<bool>> siatka_bazowa;
	//std::vector<std::vector<bool>> siatka_perkolacji;
};