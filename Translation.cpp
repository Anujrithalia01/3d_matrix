#include "Translation.h"
#include<vector>
#include<iostream>
#include"Matrice.h"


Translation::Translation(double cols) {
	this->cols = cols;
	inputMatrix.resize(4, std::vector<double>(cols, 0));

}


void Translation::setValue() {

	for (int j = 0; j < cols; j++) {
		std::cout << "Enter the value of point " << j + 1 << ":" << std::endl;
		for (int i = 0; i < 3; i++) {

			std::cin >> inputMatrix[i][j];
		}
		inputMatrix[3][j] = 1;
	}
}


void Translation::translation(double tx, double ty, double tz) {

	setValue();

	translationMatrix.resize(4, std::vector<double>(4, 0.0));

	translationMatrix[0][0] = 1.0;
	translationMatrix[1][1] = 1.0;
	translationMatrix[2][2] = 1.0;
	translationMatrix[0][3] = tx;
	translationMatrix[1][3] = ty;
	translationMatrix[2][3] = tz;
	translationMatrix[3][3] = 1.0;

	result.resize(4, std::vector<double>(cols, 0));

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < this->cols; j++) {
			result[i][j] = 0;
			for (int k = 0; k < 4; k++) {

				result[i][j] += translationMatrix[i][k] * inputMatrix[k][j];
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