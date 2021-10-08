#include <iostream>

using namespace std;
double perim(double a, double b, double c); //считает периметр
double square(double p, double a, double b, double c); //считает площадь

int main()
{
	setlocale(LC_ALL, "rus");
	double T1A, T1B, T1C, T2A, T2B, T2C, T3A, T3B, T3C, T1per, T2per, T3per, T1sq, T2sq, T3sq, sum;
	cout << "Введите 9 чисел - длины сторон 3 треугольников" << endl;
	cin >> T1A >> T1B >> T1C >> T2A >> T2B >> T2C >> T3A >> T3B >> T3C;
	if (T1A <= 0 || T1B <= 0 || T1C <= 0 || T2A <= 0 || T2B <= 0 || T2C <= 0 || T3A <= 0 || T3B <= 0 || T3C <= 0) {
		cout << "Сторона треугольника должна быть больше 0";
		return 0;
	}
	if (T1A < T1B - T1C || T1B < T1A - T1C || T1C < T1A - T1B || T2A < T2B - T2C || T2B < T2A - T2C || T2C < T2A - T2B || T3A < T3B - T3C || T3B < T3A - T3C || T3C < T3A - T3C) {
		cout << "Один или больше треугольников нельзя построить" << endl;
		return 0;
	}
	T1per = perim(T1A, T1B, T1C);
	T2per = perim(T2A, T2B, T2C);
	T3per = perim(T3A, T3B, T3C);
	T1sq = square(T1per, T1A, T1B, T1C);
	T2sq = square(T2per, T2A, T2B, T2C);
	T3sq = square(T3per, T3A, T3B, T3C);
	if (T1sq > T2sq && T1sq > T3sq) {
		cout << "У 1 треугольника максимальная площадь" << endl;
	}
	if (T2sq > T1sq && T2sq > T3sq) {
		cout << "У 2 треугольника максимальная площадь" << endl;
	}
	if (T3sq > T1sq && T3sq > T2sq) {
		cout << "У 3 треугольника максимальная площадь" << endl;
	}
	sum = T1per + T2per + T3per;
	cout << "Сумма периметров всех треугольников = " << sum << endl;
	return 0;
}

double perim(double a, double b, double c)
{
	return (a + b + c) / 2;
}

double square(double p, double a, double b, double c)
{
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}