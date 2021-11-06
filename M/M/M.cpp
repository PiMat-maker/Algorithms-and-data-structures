#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int n, m;
	int start_x, start_y, end_x, end_y;
	cin >> n >> m >> start_x >> start_y >> end_x >> end_y;
	vector<vector<int>> field(n, vector<int>(m, -1));
	vector<vector<int>> steps(n, vector<int>(m, 3000001));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char a;
			cin >> a;
			if (a == '.') {
				field[i][j] = 1;
			}
			if (a == 'W') {
				field[i][j] = 2;
			}
		}
	}

	queue<pair<int, int>> queue;
	end_x -= 1;
	end_y -= 1;
	steps[start_x - 1][start_y - 1] = 0;
	queue.push({start_x - 1, start_y - 1});
	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();

		if (x - 1 > -1) {
			if (field[x - 1][y] != -1) {
				if (steps[x - 1][y] > steps[x][y] + field[x - 1][y]) {
					steps[x - 1][y] = steps[x][y] + field[x - 1][y];
					queue.push({ x - 1, y });
				}
			}
		}

		if (x + 1 < n) {
			if (field[x + 1][y] != -1) {
				if (steps[x + 1][y] > steps[x][y] + field[x + 1][y]) {
					steps[x + 1][y] = steps[x][y] + field[x + 1][y];
					queue.push({ x + 1, y });
				}
			}
		}

		if (y - 1 > -1) {
			if (field[x][y - 1] != -1) {
				if (steps[x][y - 1] > steps[x][y] + field[x][y - 1]) {
					steps[x][y - 1] = steps[x][y] + field[x][y - 1];
					queue.push({ x, y - 1});
				}
			}
		}

		if (y + 1 < m) {
			if (field[x][y + 1] != -1) {
				if (steps[x][y + 1] > steps[x][y] + field[x][y + 1]) {
					steps[x][y + 1] = steps[x][y] + field[x][y + 1];
					queue.push({ x, y + 1});
				}
			}
		}
	}

	int x = end_x;
	int y = end_y;
	if (steps[x][y] == 3000001) {
		cout << -1;
		return 0;
	}

	cout << steps[x][y] << endl;
	string path = "";
	while (steps[x][y] != 0) {
		if (x - 1 > -1 && steps[x - 1][y] + field[x][y] == steps[x][y]) {
			path = "S" + path;
			--x;
			continue;
		}
		
		if (x + 1 < n && steps[x + 1][y] + field[x][y] == steps[x][y]) {
			path = "N" + path;
			++x;
			continue;
		}

		if (y - 1 > -1 && steps[x][y - 1] + field[x][y] == steps[x][y]) {
			path = "E" + path;
			--y;
			continue;
		}

		if (y + 1 < m && steps[x][y + 1] + field[x][y] == steps[x][y]) {
			path = "W" + path;
			++y;
			continue;
		}
		
	}

	cout << path;

	return 0;
}