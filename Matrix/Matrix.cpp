#include <iostream>
#include <vector>
#include <string>
using namespace std;

void make_vec(vector<vector<int>>& mx, int n, int m) {
	for (int i = 0; i < n; i++) {
		vector<int> l;
		int k = 0;
		for (int j = 0; j < m; j++) {
			cin >> k;
			l.push_back(k);
		}
		mx.push_back(l);
	}
}

void show_vec(vector<vector<int>>& a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

bool mult_vec(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& r) {
	if (m1[0].size() != m2.size()) {
		cout << "Incorrect size for mult \n";
		return false;
	}
	for (int i = 0; i < m1.size(); i++) {
		vector<int> line;
		for (int j = 0; j < m2[0].size(); j++) {
			int num = 0;
			for (int k = 0; k < m2.size(); k++)
				num += m1[i][k] * m2[k][j];
			line.push_back(num);
		}
		r.push_back(line);
	}
	return true;
}

void transpose(vector<vector<int>>& m, vector<vector<int>>& mt) {
	for (int i = 0; i < m[0].size(); i++) {
		vector<int> line;
		for (int j = 0; j < m.size(); j++)
			line.push_back(m[j][i]);
		mt.push_back(line);
	}
}

int main()
{
	int n, m = 0;
	cout << "Input size (n m): ";
	cin >> n;
	cin >> m;
	vector<vector <int>> matrix1;
	make_vec(matrix1, n, m);

	cout << "Input size (n m): ";
	cin >> n;
	cin >> m;
	vector<vector <int>> matrix2;
	make_vec(matrix2, n, m);

	vector<vector<int>> mult;
	mult_vec(matrix1, matrix2, mult);
	cout << "Multiplication is: \n";
	show_vec(mult);
	cout << "Transpose is:\n";
	vector<vector<int>> transp;
	transpose(mult, transp);
	show_vec(transp);

}
