/*Реализовать библиотеку функций для работы с матрицами, 
размером до 128x128. Библиотека должна включать в себя функции сложения++, 
умножения матриц++, скалярного умножения++, инвертирования+-, определения детерминанта++, 
левостороннего+- и правостороннего деления+-. Также необходимо реализовать функцию, 
отображающую на экран содержимое матрицы.*/

#include <iostream>
#include "..\Matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	
	int row1, row2, column1, column2, row3, column3;
	cout << "Размерность матрицы 1:\n";
	cin >> row1 >> column1;
	cout<<endl<< "Размерность матрицы 2:\n";
	cin >> row2 >> column2;
	cout << "Размерность матрицы 3:\n";
	cin >> row3 >> column3;

	//отводит память для динамического массива
	//и
	//задает массив рандомными числами
	double** arr1 = MatrixLibrary::Matrixx::fill_mat(row1, column1);
	double** arr2 = MatrixLibrary::Matrixx::fill_mat(row2, column2);
	double** arr3 = MatrixLibrary::Matrixx::fill_mat(row3, column3);
	
	//выводит матрицу на консоль
	cout << "Матрица 1:\n";
	MatrixLibrary::Matrixx::set(arr1, row1, column1);

	cout << "Транс-Матрица 1:\n";
	double** trans1 = MatrixLibrary::Matrixx::trans(arr1, row1, column1);
	MatrixLibrary::Matrixx::print_mat(trans1, column1, row1);

	//Скалярное произведение матрицы на число
	cout << "Скалярное произведение матрицы на число a." << endl;
	int a;
	cout << "enter a: ";
	cin >> a;
	cout << "A * a = " << endl;
	double** scalar_mult = MatrixLibrary::Matrixx::scalar_mult(arr1, row1, column1, a);
	MatrixLibrary::Matrixx::print_mat(scalar_mult, row1, column1);
	
	cout << "Матрица 2:\n";
	MatrixLibrary::Matrixx::set(arr2, row2, column2);

	//Сложение
	cout << "Матрица 1 + Матрица 2:\n";
	MatrixLibrary::Matrixx::sum(arr1, arr2, row1, column1, row2, column2);

	//Произведение
	cout << "Матрица 1 * Матрица 2:\n";
	MatrixLibrary::Matrixx::multiply(arr1, arr2, row1, column1, row2, column2);
	cout << endl;
	
	cout << "Матрица 3:\n";
	MatrixLibrary::Matrixx::set(arr3, row3, column3);
	
	if (row3 == column3) {
		//Определитель
		cout << "Определитель Матрицы 3 = ";
		cout << MatrixLibrary::Matrixx::det(arr3, row3, column3) << endl;

		//обьратная
		cout << "Обратная матрица 3:\n";
		double** invert = MatrixLibrary::Matrixx::invert(arr3, row3);
		MatrixLibrary::Matrixx::print_mat(invert, row3, row3);
		cout << endl;
	}
	else cout << "Определитель Матрицы 3 = error"<<endl<<"Обратная матрица 3: error"<<endl;
	

	cout << "Матрица 1:\n";
	MatrixLibrary::Matrixx::set(arr1, row1, column1);
	cout << "Матрица 2:\n";
	MatrixLibrary::Matrixx::set(arr2, row2, column2);

	//псевдоделение левостороннее
	cout << "A^(-1) * B = \n";
	MatrixLibrary::Matrixx::left_division(arr1, arr2, row1, column1, row2, column2);
	//правостороннеее
	cout << "A * B^(-1) = \n";
	MatrixLibrary::Matrixx::right_division(arr1, arr2, row1, column1, row2, column2);

	//очищает оперативку
	
	MatrixLibrary::Matrixx::delete_mat(arr1, row1, column1);
	MatrixLibrary::Matrixx::delete_mat(arr2, row2, column2);
	MatrixLibrary::Matrixx::delete_mat(arr3, row3, column3);

	return 0;
}




