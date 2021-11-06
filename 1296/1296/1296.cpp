#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, a;
	cin >> n;
	long max = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		sum += a;
		if (sum < 0) sum = 0;
		if (max < sum) max = sum;
	}
	cout << max;
}
