#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int curr_w = 0, curr_d = 0;

pair<int,int> do_iteration(int w, int d, int maxW, int maxD) {
	int streak = 0, alone = 0;
	if (curr_w != w) {
		streak += w - curr_w - 1;
		if (maxD == 1) {
			alone += streak;
		}
		if (curr_d != maxD) {
			++streak;
		}
		if (curr_d + 1 == maxD) {
			++alone;
		}
		curr_w = w;
		curr_d = 0;
	}

	if (d - curr_d == 2) {
		++alone;
	}

	if (d - curr_d >= 2) {
		++streak;
	}

	return { streak, alone };
}

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	vector<pair<int, int>> inputs;
	vector<pair<int, int>> days;
	set<int> set;

	for (int i = 0; i < k; ++i) {
		int w, d;
		cin >> w >> d;
		inputs.push_back({ w, d });
		days.push_back({ d, w });
	}

	sort(inputs.begin(), inputs.end());
	
	int alone = 0, streak_w = 0;
	curr_d = n;
	for (int i = 0; i < k; ++i) {
		if (inputs[i].first != curr_w) {
			if (curr_d == n - 1) {
				set.insert(curr_d*m + curr_w);
			}
			if (inputs[i].second == 2) {
				set.insert(inputs[i].first);
			}
		}
		else {
			if (curr_d + 2 == inputs[i].second) {
				set.insert(curr_d*m + curr_w);
			}
		}

		auto answer = do_iteration(inputs[i].first, inputs[i].second, m, n);
		streak_w += answer.first;
		alone += answer.second;
		curr_w = inputs[i].first;
		curr_d = inputs[i].second;
	}

	if (curr_d == n - 1) {
		set.insert(curr_d*m + curr_w);
	}

	auto answer = do_iteration(m+1, 1, m, n);
	streak_w += answer.first;
	alone += answer.second;

	sort(days.begin(), days.end());

	int streak_d = 0;
	curr_w = 0;
	curr_d = m;
	for (int i = 0; i < k; ++i) {
		if (days[i].first != curr_w) {
			if (curr_d == m - 1) {
				int sz = set.size();
				set.insert(curr_w*m);
				if (sz == set.size()) {
					--alone;
				}
			}
			if (days[i].second == 2) {
				int sz = set.size();
				set.insert(m*(days[i].first-1) + 1);
				if (sz == set.size()) {
					--alone;
				}
			}
		}
		else {
			if (curr_d + 2 == days[i].second) {
				int sz = set.size();
				set.insert((curr_w - 1)*m + curr_d + 1);
				if (sz == set.size()) {
					--alone;
				}
			}
		}

		auto answer = do_iteration(days[i].first, days[i].second, n, m);
		streak_d += answer.first;
		alone += answer.second;
		curr_w = days[i].first;
		curr_d = days[i].second;
	}

	if (curr_d == m - 1) {
		int sz = set.size();
		set.insert(curr_w*m);
		if (sz == set.size()) {
			--alone;
		}
	}

	answer = do_iteration(n+1, 1, n, m);
	
	streak_d += answer.first;
	alone += answer.second;

	if (n == 1 || m == 1) {
		if (n == 1) {
			cout << streak_d;
		}
		else {
			cout << streak_w;
		}
	}
	else {
		cout << streak_w + streak_d - alone;
	}
}
