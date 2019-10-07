#include <iostream>
using namespace std;

int* make_arr(int* arr, int n) {
	for (int i = 0; i < 32; ++i) {
		arr[i] = 0;
	}
	int j = 0;
	while (n != 0) {
		arr[j] = n % 2;
		j += 1;
		n /= 2;
	}

	return arr;
}

void show_arr(int* arr) {
	for (int i = 31; i > 0; i--)
		cout << arr[i];
	cout << endl;
}

int main()
{
	/*
	cout << ~k << endl; //побитовое интвертирование
	cout << (0 & 1) << endl; //битовое и
	cout << (1 | 1) << endl; //битовое или
	cout << (1 ^ 1) << endl; //исключающее или

	cout << (3 << 2) << endl;//побитовый сдвиг
	cout << (4 >> 2) << endl;//право
	cout << endl;
	cout << (1 && 4) << endl;//логическое и
	cout << (3 || 4) << endl;//логическое или
	*/
	int n = 0;
	int num = 0;
	int k = 0;
	int r = 0;
	int a[32];
	int b[32];
	int n2 = 0;

	cout << "Select the task: ";
	int task = 0; cin >> task;
	if (task == 2) {//вывод подчисла в двоич
		cin >> num;
		cin >> n;
		cin >> k;
		for (int i = 0; i < n; i++) {
			num /= 2;
		}
		for (int i = 0; i < k; i++) {
			r += pow((num % 2), i);
			num /= 2;
		}
		cout << r;
	}
	else if (task == 3) {//вывод числа в двоич
		cin >> num;
		make_arr(a, abs(n));
		show_arr(a);
	}
	else if (task == 4) {
		cin >> n;
		if (n < 0)
			n -= 1;
		make_arr(a, n);
		a[31] = 1;
		show_arr(a);
	}
	else if (task == 5) {//цикл сдвиг
		cin >> n;
		cin >> k;
		make_arr(a, n);
		show_arr(a);
		for (int i = 0; i < abs(k); i++) {
			if (k > 0) {
				int end = a[0];
				for (int j = 0; j < 31; j++) {
					a[j] = a[j + 1];
				}
				a[31] = end;
			}
			if (k < 0) {
				int end = a[31];
				for (int j = 31; j > 0; j--) {
					a[j] = a[j - 1];
				}
				a[0] = end;
			}

		}
		for (int i = 31; i >= 0; i--) {
			cout << a[i];
		}
	}
	else if (task == 6) {//побитовое сравнение
		cin >> n;
		cin >> n2;

		make_arr(a, n);
		make_arr(b, n2);
		show_arr(a);
		show_arr(b);

		for (int i = 31; i > 0; i--) {
			cout << (a[i] == b[i]);
		}
	}
	else if (task == 7) {//битовая инверция
		cin >> n;
		make_arr(a, n);
		show_arr(a);
		for (int i = 0; i < 32; i++) {
			a[i] = !a[i];
		}
		show_arr(a);
	}
	else if (task == 8) {//четный и неч обмен
		cin >> n;
		cin >> n2;
		make_arr(a, n);
		make_arr(b, n2);
		show_arr(a);
		show_arr(b);
		int ch[32]; make_arr(ch, n);
		int nch[32]; make_arr(nch, n2);
		for (int i = 0; i < 32; i++) {
			if (i % 2)
				ch[i] = a[i];
			else
				ch[i] = b[i];
		}
		for (int i = 0; i < 32; i++) {
			if (!(i % 2))
				nch[i] = a[i];
			else
				nch[i] = b[i];
		}
		show_arr(ch);
		show_arr(nch);
	}
	else if (task == 9)
		cout << "In progress";
	else
		cout << "Incorrect task number!";

	return 0;
}