#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> tasks;
	multiset<int> free_intervals;
	priority_queue<pair<int, int>> queue;
	queue.push({ n, 1 });
	free_intervals.insert(1);
	free_intervals.insert(n);
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		if (a > 0) {
			auto top = queue.top();
			queue.pop();
			auto it = free_intervals.find(top.second);
			int upper = n;
			if (it != free_intervals.end() && ++it != free_intervals.end()) {
				upper = *it;
			}
			while ((free_intervals.find(top.second) == free_intervals.end() || upper - top.second + 1 != top.first) && !queue.empty()) {
				top = queue.top();
				queue.pop();
				upper = n;
				it = free_intervals.find(top.second);
				if (it != free_intervals.end() && ++it != free_intervals.end()) {
					upper = *it;
				}
			}
			if (top.first >= a && free_intervals.find(top.second) != free_intervals.end() && upper - top.second + 1 == top.first) {
				cout << top.second << endl;
				tasks.push_back({ a, top.second});
				free_intervals.erase(free_intervals.find(top.second));
				if (top.first != a) {
					free_intervals.insert(top.second + a);
				}
				else {
					free_intervals.erase(free_intervals.find(top.second + a - 1));
				}
				queue.push({ top.first - a, top.second + a });
			}
			else {
				cout << -1 << endl;
				tasks.push_back({ 0, 0 });
				queue.push(top);
			}
		}
		else {
			a = abs(a);
			tasks.push_back({ 0, 0 });
			if (tasks[a - 1].first != 0) {
				free_intervals.insert(tasks[a - 1].second);
				free_intervals.insert(tasks[a - 1].second + tasks[a - 1].first - 1);
				if (free_intervals.find(tasks[a - 1].second - 1) != free_intervals.end()) {
					free_intervals.erase(free_intervals.find(tasks[a - 1].second - 1));
					free_intervals.erase(free_intervals.find(tasks[a - 1].second));
				}
				if (free_intervals.find(tasks[a - 1].second + tasks[a - 1].first) != free_intervals.end()) {
					free_intervals.erase(free_intervals.find(tasks[a - 1].second + tasks[a - 1].first));
					free_intervals.erase(free_intervals.find(tasks[a - 1].second + tasks[a - 1].first - 1));
				}
				auto it = free_intervals.lower_bound(tasks[a - 1].second);
				if (*it != tasks[a - 1].second) {
					int right = *it;
					--it;
					queue.push({ right - *it + 1, *it });
				}
				else {
					int left = *it;
					++it;
					queue.push({ *it - left + 1, left });
				}
				tasks[a - 1].first = 0;
			}
		}
	}
}
