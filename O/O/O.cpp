#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(100);
vector<char> color(100);
bool is_bipartite = true;

inline char invert(int c) {
	return c == 1 ? 2 : 1;
}

void dfs(int v, char c) {
	color[v] = c;

	for (int u : graph[v]) {
		if (color[u] == 0) {
			dfs(u, invert(c));
		}
		else if (color[u] == c) {
			is_bipartite = false;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; ++i) {
		if (color[i] == 0) {
			dfs(i, 1);
		}
	}

	if (is_bipartite) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}