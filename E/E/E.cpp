#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> coordinates(100000);
int n, k;

bool checkDistance(int dist) {
	int numOfCows = 1;
	int leftptr = 0;
	for (int i = 1; i < n; ++i) {
		if (coordinates[i] - coordinates[leftptr] >= dist) {
			leftptr = i;
			++numOfCows;
		}
	}
	if (numOfCows >= k) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> coordinates[i];
	}
	
	int l = 0;
	int r = coordinates[n - 1] - coordinates[0];
	int res = 0;
	while (r >= l) {
		int mid = (l + r) / 2;
		if (checkDistance(mid)) {
			l = mid + 1;
			res = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res;
}
