#include <iostream>
#include <fstream>

#include "sqrtmat.h"
using namespace std;


int main()
{
	sqrtmat matrix;  
	matrix.printmat();
	matrix.PrintUMat();
	matrix.ReverseSqrt();
	matrix.PrintY();
	matrix.PrintX();
	system("pause");
	return 0;
}

