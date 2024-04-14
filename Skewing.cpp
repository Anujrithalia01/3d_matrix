#include "Skewing.h"
#include<iostream>
#include<vector>

Skewing::Skewing(double cols) {
	this->cols = cols;

	inputMatrix.resize(4, std::vector<double>(cols, 0));
}

void Skewing::setValue() {
	for (int j = 0; j < cols; j++) {
		std::cout << "Enter the value of point " << j + 1 << ":" << std::endl;
		for (int i = 0; i < 3; i++) {

			std::cin >> inputMatrix[i][j];
		}
		inputMatrix[3][j] = 1;
	}
}

void Skewing::skewing(char axis, int sx, int sy, int sz) {
	setValue();

	skewingMatrix.resize(4, std::vector<double>(4, 0));

	if (axis == 'x') {
		skewingMatrix[0][1] = sy;
		skewingMatrix[0][2] = sz;
	}
	if (axis == 'y') {
		skewingMatrix[1][0] = sx;
		skewingMatrix[1][2] = sz;
	}
	if (axis == 'z') {
		skewingMatrix[2][0] = sx;
		skewingMatrix[2][1] = sy;
	}
	skewingMatrix[0][0] = 1;
	skewingMatrix[1][1] = 1;
	skewingMatrix[2][2] = 1;
	skewingMatrix[3][3] = 1;

	result.resize(4, std::vector<double>(cols, 0));

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < this->cols; j++) {
			result[i][j] = 0;
			for (int k = 0; k < 4; k++) {

				result[i][j] += skewingMatrix[i][k] * inputMatrix[k][j];
			}
		}
	}

	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "[ ";
		for (int j = 0; j < this->cols; j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;



}
