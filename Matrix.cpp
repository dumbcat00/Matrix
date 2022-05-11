// Matrix.cpp : Определяет функции для статической библиотеки.
#include "pch.h"
#include "Matrix.h"

double** MatrixLibrary::Matrixx::allocate_mem(int row, int column) {
	double** arr = new double* [row];
	for (int n = 0; n < row; n++) {
		arr[n] = new double[column];
	}
	return arr;
}

double** MatrixLibrary::Matrixx::fill_mat(int row, int column) {
	double** arr = allocate_mem(row, column);
	for (int n = 0; n < row; n++) {
		for (int m = 0; m < column; m++) {
			arr[n][m] = rand() % 100;
		}
	}
	return arr;
}

void MatrixLibrary::Matrixx::sum(double** arr1, double** arr2, int row1, int column1, int row2, int column2)
{
	if (row1 == row2 and column1 == column2) {
		for (int n = 0; n < row1; n++) {
			for (int m = 0; m < column1; m++) {
				std::cout << arr1[n][m] + arr2[n][m] << "\t";//ну здесь просто складываем поэлементно
			}
			std::cout << "\n";
		}
	}
	else { std::cout << "error"<<"\n"; }
} 

void MatrixLibrary::Matrixx::set(double** arr, int i, int j) {
	for (int n = 0; n < i; n++) {
		for (int m = 0; m < j; m++) {
			std::cout << arr[n][m] << "\t";//те псевдорандомные числа из маина засовываем сюда и выводим на консоль
		}
		std::cout << "\n";
	}
}

double** MatrixLibrary::Matrixx::trans(double** arr, int i, int j) {
	double** tarr = allocate_mem(j, i);
	for (int n = 0; n < j; n++) {
		for (int m = 0; m < i; m++) {
			tarr[n][m] = arr[m][n];//здесь транспонирует
		}
	}
	return tarr;
}

void MatrixLibrary::Matrixx::multiply(double** arr1, double** arr2, int row1, int column1, int row2, int column2) {
	if (row1 == column2) {
		double** narr = new double* [row1];
		for (int n = 0; n < row1; n++) {
			narr[n] = new double[column2];//тут отводит место для new-матрицы
		}
		for (int n = 0; n < row1; n++) {
			for (int m = 0; m < column2; m++) {
				narr[n][m] = 0;
				for (int inner = 0; inner < column1; inner++) {
					narr[n][m] += arr1[n][inner] * arr2[inner][m];
				}
				std::cout << narr[n][m] << "\t";
			}
			std::cout << "\n";

		}
	}
	else { std::cout << "error"; }
}

double** MatrixLibrary::Matrixx::scalar_mult(double** arr, int row, int column, int a) {
	double** res = allocate_mem(row, column);
	for (int n = 0; n < row; n++) 
		for (int m = 0; m < column; m++) {
			res[n][m] = a*arr[n][m];
		}
	return res;
}

double MatrixLibrary::Matrixx::det(double** arr, int row, int column) {

	if (row == 1) return arr[0][0];
	else if (row == 2) return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	else if (row >= 3) {
		double** narr;
		narr = new double* [row - 1];
		for (int n = 0; n < row - 1; n++) narr[n] = new double[row - 1];

		double det = 0;
		int a, b;

		for (int j = 0; j < row; j++) {
			a = 0;
			for (int k = 1; k < row; k++) {
				b = 0;
				for (int s = 0; s < row; s++) {
					if (s != j) {
						narr[a][b] = arr[k][s];
						b++;
					}
				}
				a++;
			}
			det += pow(-1, j + 2) * arr[0][j] * MatrixLibrary::Matrixx::det(narr, row - 1, column - 1);
		}
		return det;
	}

}

double** MatrixLibrary::Matrixx::invert(double** AA, int N)
{
	double temp;
	double** A = new double* [N];
	for (int i = 0; i < N; i++)
		A[i] = new double[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = AA[i][j];

	double** B = new double* [N];
	for (int i = 0; i < N; i++)
		B[i] = new double[N];



	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			B[i][j] = 0.0;

			if (i == j)
				B[i][j] = 1.0;
		}

	for (int k = 0; k < N; k++)
	{
		temp = A[k][k];

		for (int j = 0; j < N; j++)
		{
			A[k][j] /= temp;
			B[k][j] /= temp;
		}

		for (int i = k + 1; i < N; i++)
		{
			temp = A[i][k];

			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				B[i][j] -= B[k][j] * temp;
			}
		}
	}

	for (int k = N - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = A[i][k];

			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				B[i][j] -= B[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = B[i][j];

	return A;
}

void MatrixLibrary::Matrixx::left_division(double** arr1, double** arr2, int row1, int column1, int row2, int column2) {

	double** narr1 = allocate_mem(row1, column1);

	narr1 = invert(arr1, row1);

	MatrixLibrary::Matrixx::multiply(narr1, arr2, row1, column1, row2, column2);
}

void MatrixLibrary::Matrixx::right_division(double** arr1, double** arr2, int row1, int column1, int row2, int column2) {
	
	double** narr2 = allocate_mem(row2, column2);

	narr2 = invert(arr2, row2);

	MatrixLibrary::Matrixx::multiply(arr1, narr2, row1, column1, row2, column2);
}

void MatrixLibrary::Matrixx::print_mat(double** arr, int row, int column){
	for (int i = 0; i < row; i++){
		
		for (int j = 0; j < column; j++)
			std::cout << arr[i][j] << "\t";
		std::cout << "\n";
	}
}

void MatrixLibrary::Matrixx::delete_mat(double** arr, int row, int column)
{
	for (int n = 0; n < row; n++) {
		delete[] arr[n];
	}
	delete[] arr;
}

