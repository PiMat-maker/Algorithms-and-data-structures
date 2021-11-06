#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;
	vector<int> weight(n);
	for (int i = 0; i < n; ++i) {
		cin >> weight[i];
		sum += weight[i];
	}
	int mask = 0, min = 2000001;
	while (mask < (1 << (n-1))) {
		int temp = mask;
		int heapSum = 0;
		for (int i = 0; i < n; ++i) {
			if (temp % 2 == 1) {
				heapSum += weight[i];
			}
			temp /= 2;
		}
		if (min > abs((sum - heapSum) - heapSum)) min = abs((sum - heapSum) - heapSum);
		++mask;
	}
	cout << min;
}
