#include <iostream>
#include <time.h>

using namespace std;

void Create(double*& a, int n) 
{
	 
	for (int i = 0; i < n; i++)
		a[i] = -100. + rand() * (100. + 100.) / RAND_MAX;
}

void Print(double*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " , ";
	}
}

double Product(double*& a, int n)
{
	double p = 1.;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			p *= a[i];
		}
	}
	return p;
}

double IMax(double*& a, int n, int& imax)
{
	double max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	return imax;
}

double Sum(double*& a, int n, int& imax)
{
	double S = 0.;
	double max = IMax(a, n, imax);
	for (int i = 0; i < imax; i++)
		if (a[i] > 0)
		{
			S += a[i];
			if ( a[i] == max)
				break;

		}
		
		return S;
}

void Inverse(double*& a, int n)
{
	double tmp;
	for (int i = 0; i < n / 2; i++)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}

void Print_Inverse(double*& a, int n)
{
	for (int i = 0; i < n; i++)
	cout << a[i] << " , ";
}



int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
    double* a = new double [n];
	int imax;
	Create(a, n);
	cout << "a {"; Print(a, n); cout << "}" << endl;
	cout << "1.1) P = " << Product(a, n) << endl;
	cout << "1.2) S = " << Sum(a, n, imax) << endl;
	Inverse(a, n);
	cout << "2) Inverse a{"; Print_Inverse(a, n); cout << "}" << endl;

	delete[]a;
}

