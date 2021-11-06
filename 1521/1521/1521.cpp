#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree(400004, 0);

int build_tree(int v, int l, int r) {
	if (l == r) return tree[v] = 1;

	int mid = (l + r) / 2;
	return tree[v] = build_tree(v * 2, l, mid) + build_tree(v*2+1, mid+1, r);
}

int delete_soldier(int curr, int k, int n) {
	int l = 0, r = n - 1, v = 1;
	while (l != curr) {
		int mid = (l + r) / 2;
		if (mid < curr) {
			l = mid + 1;
			v = v * 2 + 1;
		}
		else {
			r = mid;
			v *= 2;
		}
	}

	while (tree[v] < k && v != 1) {
		k -= tree[v];
		v = v / 2 + 1;
		while (v % 2 == 0) {
			v /= 2;
		}
	}

	int curr_v = v;
	l = 0;
	r = n - 1;
	int rev_v = 0;
	while (curr_v != 1) {
		rev_v = rev_v << 1;
		rev_v += curr_v % 2;
		curr_v = curr_v >> 1;
	}

	while (rev_v) {
		int a = rev_v % 2;
		rev_v = rev_v >> 1;
		int mid = (l + r) / 2;
		if (a == 0) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	if (v == 1) {
		if (k % tree[v] == 0) {
			k = tree[v];
		}
		else {
			k %= tree[v];
		}
	}
	while (l != r) {
		int mid = (l + r) / 2;
		if (k <= tree[v*2]) {
			r = mid;
			v *= 2;
		}
		else {
			k -= tree[v * 2];
			l = mid + 1;
			v = v * 2 + 1;
		}
	}

	v = 1;
	int target = l;
	l = 0;
	r = n - 1;
	--tree[v];
	while (l != r) {
		int mid = (l + r) / 2;
		if (mid < target) {
			l = mid + 1;
			v = v * 2 + 1;
		}
		else {
			r = mid;
			v *= 2;	
		}
		--tree[v];
	}

	return l;
}

int main()
{
	int n, k;
	cin >> n >> k;
	build_tree(1, 0, n - 1);
	vector<int> v;
	int curr = 0;
	for (int i = 0; i < n; ++i) {
		curr = delete_soldier(curr, k, n);
		cout << curr + 1 << " ";
	}
}