#include "Rotation.h"
#include<vector>
#include<cmath>
#include<iostream>
#include"Matrice.h"

Rotation::Rotation(double cols) {
	this->cols = cols;

	inputMatrix.resize(3, std::vector < double >(cols, 0));
}

void Rotation::setValue() {
	for (int j = 0; j < cols; j++) {
		std::cout << "Enter the value of point " << j + 1 << ":" << std::endl;
		for (int i = 0; i < 3; i++) {

			std::cin >> inputMatrix[i][j];
		}
	}
}

void Rotation::rotation(int angle, char axis) {
	setValue();

	rotationMatrix.resize(3, std::vector<double>(3, 0));

	double radian = (angle * M_PI) / 180;

	if (axis == 'x') {
		rotationMatrix[0][0] = 1;
		rotationMatrix[1][1] = cos(radian);
		rotationMatrix[1][2] = -sin(radian);
		rotationMatrix[2][1] = sin(radian);
		rotationMatrix[2][2] = cos(radian);
	}

	if (axis == 'y') {
		rotationMatrix[0][0] = cos(radian);
		rotationMatrix[0][2] = sin(radian);
		rotationMatrix[2][0] = -sin(radian);
		rotationMatrix[2][2] = cos(radian);
		rotationMatrix[1][1] = 1;

	} 

	if (axis == 'z') {
		rotationMatrix[0][0] = cos(radian);
		rotationMatrix[0][1] = -sin(radian);
		rotationMatrix[1][0] = sin(radian);
		rotationMatrix[1][1] = cos(radian);
		rotationMatrix[2][2] = 1;

	}

	result.resize(3, std::vector<double>(cols, 0));

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < this->cols; j++) {
			result[i][j] = 0;
			for (int k = 0; k < 3; k++) {

				result[i][j] += rotationMatrix[i][k] * inputMatrix[k][j];
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
