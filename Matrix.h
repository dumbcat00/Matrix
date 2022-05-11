#pragma once
#include <iostream>
#include "pch.h"
#include "framework.h"

namespace MatrixLibrary {
	class Matrixx {
	public:
		static double** allocate_mem(int, int);
		static double** fill_mat(int, int);
		static void sum(double**, double**, int, int, int, int);
		static void set(double**, int, int);
		static double** trans(double**, int, int);
		static void multiply(double**, double**, int, int, int, int);
		static double** scalar_mult(double**, int, int, int);
		static double det(double**, int, int);
		static double** invert(double** A, int N);
		static void left_division(double**, double**, int, int, int, int);
		static void right_division(double**, double**, int, int, int, int);
		static void print_mat(double**, int, int);
		static void delete_mat(double**, int, int);
	};
}