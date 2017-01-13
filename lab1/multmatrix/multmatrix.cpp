#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MATRIX_ROW = 3;
const int MATRIX_COLUMN = 3;

typedef float Matrix[MATRIX_ROW][MATRIX_COLUMN];

bool ReadMatrixFromFile(ifstream &inputFile, Matrix &matrix)
{
	float number;
	for (int row = 0; row < MATRIX_ROW; row++)
	{
		for (int col = 0; col < MATRIX_COLUMN; col++)
		{
			if (!(inputFile >> number))
			{
				cout << "Wrong input matrix\n";
				return false;
			}
			matrix[row][col] = number;
		}
	}
	return true;
}

void MatrixMultiplication(Matrix &matrix1, Matrix &matrix2, Matrix &resultMatrix)
{
	for (int row = 0; row < MATRIX_ROW; ++row)
	{
		for (int col = 0; col < MATRIX_COLUMN; ++col)
		{
			resultMatrix[row][col] = 0;
			for (int i = 0; i < 3; ++i)
			{
				resultMatrix[row][col] += matrix1[row][i] * matrix2[i][col];
			}
		}
	}
}

void PrintMatrix(Matrix &matrix)
{
	std::cout << std::fixed;
	for (int row = 0; row < MATRIX_ROW; row++)
	{
		for (int col = 0; col < MATRIX_COLUMN; col++)
		{
			cout << setprecision(3) << matrix[row][col] << ' ';
		}
		cout << '\n';
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return 1;
	}

	ifstream matrix1File(argv[1]);
	if (!matrix1File.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	ifstream matrix2File(argv[2]);
	if (!matrix2File.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	Matrix matrix1;
	Matrix matrix2;
	Matrix resultMatrix;

	if (!ReadMatrixFromFile(matrix1File, matrix1) || !ReadMatrixFromFile(matrix2File, matrix2))
	{
		return 1;
	}

	MatrixMultiplication(matrix1, matrix2, resultMatrix);

	PrintMatrix(resultMatrix);

	return 0;
}