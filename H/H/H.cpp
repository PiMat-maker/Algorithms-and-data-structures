#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	long sum = 0;
	vector<int> prices(n);
	for (int i = 0; i < n; ++i) {
		cin >> prices[i];
		sum += prices[i];
	}
	sort(prices.begin(), prices.end());
	long res = 0;
	for (int i = n - k; i > -1; i -= k) {
		res += prices[i];
	}
	cout << sum - res;
}
