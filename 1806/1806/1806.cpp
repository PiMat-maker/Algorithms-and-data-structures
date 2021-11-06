#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> cost(10);
	for (int i = 0; i < 10; ++i) {
		cin >> cost[i];
	}

	unordered_map<long long, int> telegrafs;
	vector<long long> number(50000);
	vector<vector<pair<int, int>>> graph(50000);
	for (int i = 0; i < n; ++i) {
		cin >> number[i];
		telegrafs.insert({number[i], i});
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			long long del = pow(10, 10 - j - 1);
			for (int k = 0; k < 10; ++k) {
				long long a = number[i]/(del*10)*del*10 + k*del + number[i]%del;

				auto res = telegrafs.find(a);
				if (res != telegrafs.end() && res->second != i) {
					graph[i].push_back({ res->second, j});
				}
			}

			int digit = (number[i] / del) % 10;
			for (int k = j + 1; k < 10; ++k) {
				long long del2 = pow(10, 10 - k - 1);
				int digit_k = (number[i] / del2) % 10;
				long long del_m = pow(10, k - j - 1);
				long long a = number[i]/(del*10)*del*10 + digit_k*del + ((number[i]/(del/del_m))%del_m)*(del/del_m) + digit*del2 + number[i]%del2;

				auto res = telegrafs.find(a);
				if (res != telegrafs.end() && res->second != i) {
					graph[i].push_back({ res->second, j });
				}
			}
		}
	}

	vector<int> dist(n, 1000000000);
	vector<int> prev(n, -1);
	dist[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		pair<int, int> c = q.top();
		q.pop();

		int dst = c.first, v = c.second;
		if (v == n - 1) break;
		if (dist[v] < dst) {
			continue;
		}

		for (pair<int, int> e : graph[v]) {
			int u = e.first, len_vu = cost[e.second];

			int n_dst = dst + len_vu;
			if (n_dst < dist[u]) {
				dist[u] = n_dst;
				prev[u] = v;
				q.push({ n_dst, u });
			}
		}
	}

	if (dist[n - 1] == 1000000000) {
		cout << -1;
		return 0;
	}
	cout << dist[n - 1] << endl;

	vector<int> path;

	int curr = n-1;
	path.push_back(curr);
	while (prev[curr] != -1) {
		curr = prev[curr];
		path.push_back(curr);
	}

	reverse(path.begin(), path.end());

	cout << path.size() << endl;
	for (int v : path) {
		cout << v + 1 << " ";
	}

	return 0;
}