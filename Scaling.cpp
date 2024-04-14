#include "Scaling.h"
#include<vector>
#include<iostream>


Scaling::Scaling(double cols) {
	this->cols = cols;
	inputMatrix.resize(4, std::vector<double>(cols, 0));

}


void Scaling::setValue() {

	for (int j = 0; j < cols; j++) {
		std::cout << "Enter the value of point " << j + 1 << ":" << std::endl;
		for (int i = 0; i < 3; i++) {

			std::cin >> inputMatrix[i][j];
		}
		inputMatrix[3][j] = 1;
	}
}


void Scaling::scaling(double sx, double sy, double sz) {

	setValue();

	scalingMatrix.resize(4, std::vector<double>(4, 0.0));

	scalingMatrix[0][0] = sx;
	scalingMatrix[1][1] = sy;
	scalingMatrix[2][2] = sz;
	scalingMatrix[3][3] = 1.0;

	result.resize(4, std::vector<double>(cols, 0));

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < this->cols; j++) {
			result[i][j] = 0;
			for (int k = 0; k < 4; k++) {

				result[i][j] += scalingMatrix[i][k] * inputMatrix[k][j];
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