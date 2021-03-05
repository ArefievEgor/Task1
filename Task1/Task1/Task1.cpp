#include "stdafx.h"
#include <iostream>
#include <chrono>
#include "math.h"
#define M_PI 3.14159265358979323846

using namespace std;
using namespace std::chrono;


//функция интеграла
double y(double x)
{
	double y = 4 / (1 + x * x);
	return y;
}

//функция для нахождения интеграла методом правых прямоугольников
void right(int N)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	double I = 0;
	double d = 1.0 / N;
	double x = d;
	//Для отключения векториизации
	//#pragma loop(no_vector)
	//Для автоматического параллелизатора
	//#pragma loop(hint_parallel(8))
	for (int i = 0; i < N; i++)
	{
		I = I + y(x)*d;
		x = x + d;
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> duration = (t2 - t1);

	double er = abs(I - M_PI);

	cout << "Метод правых прямоугольников: " << endl;
	cout << "I = " << I << endl;
	cout << "Отклонение от истинного результата = " << er << endl;
	cout << "Время работы = " << duration.count() << " секунд" << endl;
}

//функция для нахождения интеграла методом левых прямоугольников
void left(int N)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	double I = 0;
	double d = 1.0 / N;
	double x = 0;
	//Для отключения векториизации
	//#pragma loop(no_vector)
	//Для автоматического параллелизатора
	//#pragma loop(hint_parallel(8))
	for (int i = 0; i < N; i++)
	{
		I = I + y(x)*d;
		x = x + d;
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> duration = (t2 - t1);

	double er = abs(I - M_PI);

	cout << "Метод левых прямоугольников: " << endl;
	cout << "I = " << I << endl;
	cout << "Отклонение от истинного результата = " << er << endl;
	cout << "Время работы = " << duration.count() << " секунд" << endl;
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

