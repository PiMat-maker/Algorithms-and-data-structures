#include <iostream>

using namespace std;
int main()
{
	int a, b, c, d, prev = -1;
	long k;
	cin >> a >> b >> c >> d >> k;
	long i = 0;
	while (a > 0 && a <= d && i < k && prev != a){
		prev = a;
		a *= b;
		a -= c;
		++i;
	}
	if (a <= 0) {
		cout << 0;
		return 0;
	}
	if (a >= d) {
		cout << d;
		return 0;
	}
	cout << a;
	
}