#pragma once
#include<vector>

class Scaling
{
	double cols;
	std::vector<std::vector<double>>scalingMatrix;
	std::vector<std::vector<double>> inputMatrix;
	std::vector<std::vector<double>> result;

public:

	Scaling(double cols);

	void setValue();

	void scaling(double sx, double sy, double sz);

};