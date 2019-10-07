// Tester.cpp : Ётот файл содержит функцию "main". «десь начинаетс€ и заканчиваетс€ выполнение программы.
//


#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string hundreds[10] = { "сто","двести","тристо","четыреста","п€тьсот","шестьсот","семьсот","восемьсот","дев€тьсот" };
string teens[10] = { "одиннадцать","двенадцать","тринадцать","четырнадцать","п€тнадцать","шестнадцать","семнадцать","восемнадцать","дев€тнадцать" };
string dozens[10] = { "дес€ть","двадцать","тридцать","сорок","п€тьдес€т","шестьдес€т","семьдес€т","восемдес€ть","дев€тьсот" };
string units[10] = { "один","два","три","четыре","п€ть","шесть","семь","восемь","дев€ть" };

int discr(int a, int b, int c) {
	int d = b * b - 4 * a * c;
	if (d < 0)
		return -1;
	else
		return pow(d, 0.5);
}

int check_round(int x1, int y1, int r, int x, int y) {
	return(pow(x - x1, 2) + pow(y - y1, 2) <= pow(r, 2));
}
int check_line(int k, int b, int x, int y) {
	return (k * x + b < y);//выше - true ниже false
}

string three_num(int a) {
	string res = "";
	if (a >= 100) {
		res += "-" + hundreds[int(a / 100) - 1];
		a %= 100;
	}
	if (a > 20) {
		res += "-" + dozens[int(a / 10) - 1];
		a %= 10;
		res += "-" + units[a - 1];
	}
	else {
		a %= 10;
		res += "-" + teens[a - 1];
	}

	return res;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Select the task: ";
	int task = 0; cin >> task;
	if (task == 1) {
		int a = 0; cin >> a;
		int b = 0; cin >> b;
		int c = 0; cin >> c;

		int d = discr(a, b, c);
		if (d == -1)
			cout << "Error";
		else {
			cout << "x1 = " << (-b + d) / 2 * a;
			cout << "x2 = " << (-b - d) / 2 * a;
		}
	}
	else if (task == 2) {
		int x = 0; cin >> x;
		int y = 0; cin >> y;

		int ax = abs(x);
		if (check_round(1, 0, 1, ax, y) && y < 0)
			cout << "in 1" << endl;
		else if (ax < 1 && !check_line(-2, 2, ax, y))
			cout << "in 1" << endl;
		if (check_round(0, 0, 3, x, y) && !check_round(0, 0, 2, x, y) || check_round(0, 0, 1, x, y))
			cout << "in 2" << endl;
		if (check_round(0, 0, 2, x, y) &&
			(!check_line(1, -2, x, y) || check_line(-1, 2, x, y)
				|| check_line(1, 2, x, y) || !check_line(-1, -2, x, y))) {
			cout << "in 3" << endl;
		}
	}
	else if (task == 3) {
		string week[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
		cout << "Input day week ";
		int n = 0; cin >> n;
		if (n <= 0 || n > 7)
			cout << "Error" << endl;
		else
			cout << week[n];
		cout << endl;
		cout << "Input day year " << endl;
		cout << "Year: " << endl; int y = 0; cin >> y;
		cout << "Month: " << endl; int m = 0; cin >> m;
		cout << "Day: " << endl; int d = 0; cin >> d;
		cout << week[(d + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7 + 1];
	}
	else if (task == 4) {
		cout << pow(10, 6);
		/*
		if (n / 1000 > 0) {
			for (int i = 0; i < n / 1000; i++)
				cout << "M";
			n %= 1000;
		}
		if (n / 1000 > 0) {
			for (int i = 0; i < n / 1000; i++)
				cout << "M";
			n %= 1000;
		}
		*/
		cout << "Rome nums";
	}
	else if (task == 5) {
		int n = 0; cin >> n;
		if (n > 1000000) {
			int three = int(n / 1000000);
			cout << three_num(three);
			if (three % 10 < 5)
				cout << "-миллиона";
			else
				cout << "-миллионов";
			n = n % 1000000;
		}
		if (n > 1000) {
			int three = int(n / 1000);
			cout << three_num(three);
			if (three % 10 < 5)
				cout << "-тыс€чи";
			else
				cout << "-тыс€ч";
			n = n % 1000;
		}
		if (n > 0) {
			int three = int(n);
			cout << three_num(three);

		}

	}
	return 0;
}