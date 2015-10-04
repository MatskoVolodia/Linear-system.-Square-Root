#include "matr.h"
using namespace std;

class sqrtmat :
	public matr
{
protected:
	float **U;
	float *y;
	float *x;

public:
	sqrtmat();
	void PrintUMat();
	void PrintY();
	void PrintX();
	void DirectSqrt();
	void ReverseSqrt();
	~sqrtmat();
};

