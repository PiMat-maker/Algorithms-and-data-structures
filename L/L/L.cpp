#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vect(150000, 0);
vector<int> tree(600004, 0);

void build_tree(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v] = vect[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build_tree(v * 2, tl, tm);
		build_tree(v * 2 + 1, tm + 1, tr);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}

int get_min(int l, int r, int v, int tl, int tr) {
	if (l <= tl && tr <= r) {
		return tree[v];
	}
	if (l > tr || r < tl) return 1000000;

	int tm = (tl + tr) / 2;
	return min(get_min(l, r, v * 2, tl, tm), get_min(l, r, v * 2 + 1, tm + 1, tr));
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> vect[i];
	}
	build_tree(1, 0, n - 1);
	for (int i = 0; i < n - k + 1; ++i) {
		cout << get_min(i, i + k - 1, 1, 0, n - 1) << " ";
	}
}