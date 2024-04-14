#include "Matrice.h"
#include <iostream>
#include <vector>

Matrice::Matrice(int numRow, int numCol) {
	this->rows = numRow;
	this->cols = numCol;
	mat.resize(numRow, std::vector < double >(numCol, 0));
}

void Matrice::set_value() {
	int value;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> value;
			mat[i][j] = value;
		}
	}
}

void Matrice::print_it() {
	for (int i = 0; i < rows; i++) {
		std::cout << "[ ";
		for (int j = 0; j < cols; j++) {
			std::cout << this->mat[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}
}

Matrice Matrice::operator+(const Matrice& other) const {
	if (rows != other.rows || cols != other.cols) {
		std::cerr << "Error: Rows and Columns of both the matrix should be equal" << std::endl;
		return *this;
	}

	Matrice new_matrix(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			new_matrix.mat[i][j] = mat[i][j] + other.mat[i][j];
		}
	}

	return new_matrix;
}

Matrice Matrice::operator -(const Matrice& other) const {
	if (rows != other.rows || cols != other.cols) {

		std::cerr << "This is invalid because the dimesions of the 2 matrix should be same";
		return *this;
	}
	Matrice new_matrix(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			new_matrix.mat[i][j] = mat[i][j] - other.mat[i][j];
		}
	}
	return new_matrix;
}

Matrice Matrice:: operator *(const Matrice& other) const {

	if (cols != other.rows) {
		std::cerr << "This is invalid because the column of first matrix should be equal to the rows of the other matrix";
		return *this;
	}

	Matrice computed(rows, other.cols);

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < other.cols; j++) {

			for (int k = 0; k < cols; k++) {

				computed.mat[i][j] += mat[i][k] * other.mat[k][j];
			}
		}
	}

	return computed;

}

Matrice Matrice:: operator *(int number) const {                             // This is for scaler multiplication of matrix

	Matrice matrice(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrice.mat[i][j] = mat[i][j] * number;
		}
	}
	return matrice;
}

Matrice Matrice::transpose(const Matrice& matrix) const {                     //This is a function made to Transpose and then print a matrix 
	Matrice transposed_mat(matrix.cols, matrix.rows);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposed_mat.mat[j][i] = matrix.mat[i][j];
		}
	}
	//transposed_mat.print_it();
	return transposed_mat;
}

Matrice Matrice::rotate(const Matrice& matrix) const {

	Matrice new_matrix(matrix.rows, matrix.cols);
	new_matrix = transpose(matrix);

	for (int i = 0; i < matrix.rows; i++) {

		int left = 0; int right = matrix.rows - 1;

		while (left < right) {
			int temp = new_matrix.mat[i][left];
			new_matrix.mat[i][left] = new_matrix.mat[i][right];
			new_matrix.mat[i][right] = temp;
			left++;
			right--;
		}

	}

	new_matrix.print_it();
	return new_matrix;
}

double Matrice::determinent(const Matrice& matrix) const {
	if (matrix.rows != matrix.cols) {
		std::cout << "Not a square matrix" << std::endl;
		return 0.0;
	}

	int n = matrix.rows;

	if (n == 1) {
		return matrix.mat[0][0];
	}

	if (n == 2) {
		return (matrix.mat[0][0] * matrix.mat[1][1]) - (matrix.mat[0][1] * matrix.mat[1][0]);
	}

	double det = 0;
	for (int i = 0; i < n; ++i) {
		Matrice submatrix(n - 1, n - 1);

		for (int j = 1; j < n; ++j) {
			for (int k = 0, col = 0; k < n; ++k) {
				if (k == i) continue; //skipping current column
				submatrix.mat[j - 1][col++] = matrix.mat[j][k];
			}

		}

		double subdet = determinent(submatrix);

		det += (i % 2 == 0 ? 1 : -1) * matrix.mat[0][i] * subdet;
	}

	return det;
}

double Matrice::cofactor(int row, int col) const {
	Matrice submatrix(rows - 1, cols - 1);

	for (int i = 0, r = 0; i < rows; ++i) {
		if (i == row) continue; // Skipping current row
		for (int j = 0, c = 0; j < cols; ++j) {
			if (j == col) continue; // Skipping current column
			submatrix.mat[r][c++] = mat[i][j];
		}
		++r;
	}

	return ((row + col) % 2 == 0 ? 1 : -1) * determinent(submatrix);
}
Matrice Matrice:: inverse(const Matrice& matrix) const{
	if (determinent(matrix) ==0) {
		std::cerr << "This is invalid because the determinent of this matrix is 0 "<<std::endl;
		return *this;
	}
	Matrice cofactorMat(rows, cols);
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cofactorMat.mat[i][j] = matrix.cofactor(i, j);
		}
	}
	
	double det = determinent(matrix);
	Matrice inverseMat(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			inverseMat.mat[i][j] = cofactorMat.mat[i][j] / det;
		}
	}

	return transpose(inverseMat);
}


