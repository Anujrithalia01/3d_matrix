#pragma once
#include<vector>

class Skewing
{
private:
	double cols;
	std::vector<std::vector<double>>skewingMatrix;
	std::vector<std::vector<double>> inputMatrix;
	std::vector<std::vector<double>> result;

public:

	Skewing(double cols);

	void setValue();

	void skewing(char axis, int sx, int sy, int sz);

};

