#pragma once
#include<vector>


class Translation
{
	double cols;
	std::vector<std::vector<double>>translationMatrix;
	std::vector<std::vector<double>> inputMatrix;
	std::vector<std::vector<double>> result;


public:

	Translation(double cols);

	void setValue();

	void translation(double tx, double ty, double tz);

};



