#include <iostream>
#include <ctime>
#include <iomanip> 
#include <cmath> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������ ����� �������: ";
	int n; cin >> n;
	cout << endl;
	if (n == 1) {
		cout << "������� �����: �� �� " << endl;
		int y = 2019;
		cout << "����� " << endl; int m = 0; cin >> m;
		cout << "����: " << endl; int d = 0; cin >> d;

		while ((d + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7 + 1 != 4) {
			y += 1;
		};
		cout << "��� � ������� ��� ����� ������� -" << y;
	}
	if(n==2){
		int y = 1900;
		int m = 1;
		int d = 13;
		int count = 0;
		for (y = 1900; y < 2000; y++) {
			for (m = 1; m <= 12; m++) {
				if( (d + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7 + 1 == 4)
					count += 1;
			}
		}
		cout << "������ 13�� � 20� ����: " << count<<endl;
	}
	if (n == 3) {
		cout << "������� n: ";
		int n; cin >> n;
		int rabbits = int(n / 2);
		int chiks = n % 2;
		for (rabbits = rabbits; rabbits > 0; rabbits--) {
			cout << "������� - " << rabbits << " ���� - " << chiks<<endl;
			chiks += 2;
		}
	}
	if (n == 4) {
		srand(time(0));
		int a[10];
		for (int j = 0; j < 3; j++) {
			int s = 0;
			for (int i = 0; i < 10; i++) {
				a[i] = rand() % 10;
				cout << a[i] << " ";
				s += a[i];
			}
			cout << "������� �����. " << (s / 10.0) << endl;
		}
	}
	if (n == 5) {
		cout << "������� ����� : ";
		int n = 0; cin >> n;
		int s = 0;
		while (n > 0) {
			s += n % 10;
			n = int(n / 10);
		}
		if (s % 3 == 0)
			cout << "������� �� ���";
		else
			cout << "�� ������� �� ���";
	}
	if (n == 6) {
		cout << "������� �������� �������� : ";
		int n; cin >> n;
		long float pi = 1;//pi/4
		for (int i = 1; i <= n; i++) {
			pi += pow(-1, i) * 1.0 / (i + 2.0);
		}
		cout << fixed << setprecision(50) << 4*pi << endl;
	}
}