
#pragma once
#include<vector>

class Matrice
{
private:
	int rows;
	int cols;
	std::vector<std::vector<double>>mat;

public:

	Matrice(int numRow, int numCol);

	void set_value();

	void print_it();

	Matrice operator+(const Matrice& other) const;
	Matrice operator-(const Matrice& other) const;
	Matrice operator*(const Matrice& other) const;
	Matrice operator *(int number) const;
	Matrice transpose(const Matrice& matrix) const;
	Matrice rotate(const Matrice& matrix) const;
	double cofactor(int row, int col) const;
	//Matrice getCofactorMatrix(const Matrice& matrix);
	Matrice inverse(const Matrice& matrix) const;

	double determinent(const Matrice& matrix) const;

};


