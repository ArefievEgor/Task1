#include "stdafx.h"
#include <iostream>
#include <chrono>
#include "math.h"
#define M_PI 3.14159265358979323846

using namespace std;
using namespace std::chrono;


//������� ���������
double y(double x)
{
	double y = 4 / (1 + x * x);
	return y;
}

//������� ��� ���������� ��������� ������� ������ ���������������
void right(int N)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	double I = 0;
	double d = 1.0 / N;
	double x = d;
	//��� ���������� �������������
	//#pragma loop(no_vector)
	//��� ��������������� ���������������
	//#pragma loop(hint_parallel(8))
	for (int i = 0; i < N; i++)
	{
		I = I + y(x)*d;
		x = x + d;
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> duration = (t2 - t1);

	double er = abs(I - M_PI);

	cout << "����� ������ ���������������: " << endl;
	cout << "I = " << I << endl;
	cout << "���������� �� ��������� ���������� = " << er << endl;
	cout << "����� ������ = " << duration.count() << " ������" << endl;
}

//������� ��� ���������� ��������� ������� ����� ���������������
void left(int N)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	double I = 0;
	double d = 1.0 / N;
	double x = 0;
	//��� ���������� �������������
	//#pragma loop(no_vector)
	//��� ��������������� ���������������
	//#pragma loop(hint_parallel(8))
	for (int i = 0; i < N; i++)
	{
		I = I + y(x)*d;
		x = x + d;
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> duration = (t2 - t1);

	double er = abs(I - M_PI);

	cout << "����� ����� ���������������: " << endl;
	cout << "I = " << I << endl;
	cout << "���������� �� ��������� ���������� = " << er << endl;
	cout << "����� ������ = " << duration.count() << " ������" << endl;
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");

	int N = 100;
	cout << "N = " << N << endl;
	right(N);
	left(N);

	N = 1000;
	cout << "N = " << N << endl;
	right(N);
	left(N);

	N = 10000;
	cout << "N = " << N << endl;
	right(N);
	left(N);

	N = 100000;
	cout << "N = " << N << endl;
	right(N);
	left(N);

	N = 1000000;
	cout << "N = " << N << endl;
	right(N);
	left(N);

	cin.get();
	return 0;
}

