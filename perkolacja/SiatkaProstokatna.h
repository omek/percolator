#pragma once
#include <vector>
#include <time.h>
class SiatkaProstokatna {
public:
	SiatkaProstokatna(int w, int h, float p);
	~SiatkaProstokatna();
	bool sprawdz();
	void pokaz();
private:
	int Width;
	int Height;
	std::vector<std::vector<bool>> siatka_bazowa;
};