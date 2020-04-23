#pragma once
#include <vector>
#include <time.h>
class SiatkaProstokatna {
public:
	SiatkaProstokatna(int w, int h);
	~SiatkaProstokatna();
	bool sprawdz();
	void pokaz();
	void losuj(int prawdopodobienstwo);
private:
	int Width;
	int Height;
	std::vector<std::vector<bool>> siatka_bazowa;
};