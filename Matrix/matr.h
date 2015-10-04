#include <fstream>
#include <iostream>

using namespace std;

class matr
{
protected:
	float **mat;
	float *b;
	float *res;
	int size;

public:
	matr();
	void printmat();
	~matr();
};

