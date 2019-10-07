#include <iostream>
#include "string"
using namespace std;

int func(double e) {
	return(floor(2/e-1));
}
float opr(int n, double e) {
	return (abs((n + 1.0) / (n + 3.0) * pow(2, 1 / n) - 1));
}
int main()
{
	
	int n = 0;
	float e = 0;
	long float delta = 0;
	for (int i = 2; i < 1000; i++) {
		e = 1.0 / i;
		n = func(e);
		delta = opr(n, e);
		if(e<=delta)
			cout << "e = " << e << " n = " << n << " delta " << delta << endl;
	}
}