#pragma once
#include<vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif 

class Rotation
{
private:

	double cols;
	std::vector<std::vector<double>> rotationMatrix;
	std::vector<std::vector<double>> inputMatrix;
	std::vector<std::vector<double>> result;

public:

	Rotation(double cols);

	void setValue();
	void rotation(int angle , char axis);
};

