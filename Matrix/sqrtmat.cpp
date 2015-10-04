#include "sqrtmat.h"
#include <fstream>
#include <iomanip>
using namespace std;

sqrtmat::sqrtmat() : matr()
{
	U = new float*[size];
	for (int i = 0; i < size; i++)
	{
		U[i] = new float[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			U[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j < i)
			{
				U[i][j] = 0;
			}
			if (j > i)
			{
				float temp = 0;
				for (int k = 0; k < i; k++)
				{
					temp += (U[k][i] * U[k][j]);
				}
				if (U[i][i] == 0)
				{
					cout << "Matrix has no unambiguous interpretation, because U[i][i] = 0." << endl;
					system("pause");
					exit(1);
				}
				U[i][j] = (mat[i][j] - temp) / U[i][i];
			}
			if (j == i)
			{
				float temp = 0;
				for (int k = 0; k < size - 1; k++)
				{
					temp += (U[k][i] * U[k][i]);
				}

				if ((mat[i][i] - temp) < 0)
				{
					cout << "Matrix has no unambiguous interpretation." << endl;
					system("pause");
					exit(1);
				}
				U[i][i] = sqrt(mat[i][i] - temp);
			}
		}
	}

	y = new float[size];
	x = new float[size];
}

void sqrtmat::PrintY()
{
	cout << "============ Vector Y: "<< endl;
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(4);
		cout << setw(10) << y[i];
	}
	cout << "\n\n";
}

void sqrtmat::PrintX()
{
	cout << "============ Vector X: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(4);
		cout << setw(10) << x[i];
	}
	cout << "\n\n";
}

void sqrtmat::PrintUMat()
{
	cout << "============ Triangular matrix: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(10) << right << U[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void sqrtmat::DirectSqrt()
{
	for (int j = 0; j < size; j++)
	{
		float temp = 0;
		for (int i = 0; i < j; i++)
		{
			temp += (y[i] * U[i][j]);
		}
		y[j] = (b[j] - temp) / U[j][j];
	}
}
void sqrtmat::ReverseSqrt()
{
	DirectSqrt();
	for (int i = size - 1; i >= 0; i--)
	{
		float temp = 0;
		for (int j = i + 1; j < size; j++)
		{
			temp += (x[j] * U[i][j]);
		}
		x[i] = (y[i] - temp) / U[i][i];
	}
}
sqrtmat::~sqrtmat()
{
	for (int i = 0; i < size; i++)
	{
		delete[]U[i];
	}
	delete[]U;
}