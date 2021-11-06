#include <iostream>
#include <vector>

using namespace std;

vector<int> sets(100, 0);

int get_root(int v) {
	if (sets[v] == v) {
		return v;
	}
	else {
		return sets[v] = get_root(sets[v]);
	}
}

bool merge(int a, int b) {
	int ra = get_root(a), rb = get_root(b);
	if (ra == rb) {
		return false;
	}
	else {
		sets[ra] = rb;
		return true;
	}
}

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		sets[i] = i;
	}

	int res = n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (merge(i, a - 1)) {
			--res;
		}
	}

	cout << res;
}