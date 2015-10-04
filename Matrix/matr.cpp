#include "matr.h"
#include <iomanip>
#include <string>

matr::matr()
{
	fstream DATA;
	string name;
	cout << "Please, input filename: \Data";
	cin >> name;
	name = "Data" + name;
	DATA.open(name);
	char *str = new char[1024];
	while (!DATA.eof())
	{
		DATA.getline(str, 1024, '\n');
		size++;
	}
	
	DATA.seekg(0);

	mat = new float*[size];
	for (int i = 0; i < size; i++)
	{
		mat[i] = new float[size];
	}

	b = new float [size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			if (j == size)
			{
				DATA >> b[i];
			} else
			DATA >> mat[i][j];
		}
	}
	DATA.close();
}

void matr:: printmat()
{
	cout << "============ Your matrix: \n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			if (j == size)
			{
				cout << " | " << setw(5) << internal << b[i];
			} else
			cout << setw(10) << right << mat[i][j];
		}
		cout << '\n';
	}
	cout << endl;
}

matr::~matr()
{
	for (int i = 0; i < size; i++)
	{
		delete[]mat[i];
	}
	delete[]mat;
	delete[]b;
}
