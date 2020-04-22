#pragma once
#include <vector>
class MonteCarlo
{
public:
	MonteCarlo(int ilosc, std::vector<int> wektor_prawdopodobienstw, int W, int H);
	~MonteCarlo();
	std::vector<int> Symulacja();
private:
	int ilosc_symulacji;
	int Width;
	int Heigth;
	std::vector<int>wektor_p;
};
