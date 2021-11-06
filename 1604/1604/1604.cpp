#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>> queue;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		queue.push({ a, i + 1 });
	}

	int prev = 0;
	while (!queue.empty()) {
		pair<int, int> pair1 = queue.top();
		queue.pop();
		if (prev == pair1.second && !queue.empty()) {
			pair<int, int> pair2 = queue.top();
			queue.pop();
			cout << pair2.second << " ";
			--pair2.first;
			prev = pair2.second;
			if (pair2.first != 0) {
				queue.push(pair2);
			}
		}
		else {
			cout << pair1.second << " ";
			--pair1.first;
			prev = pair1.second;
		}

		if (pair1.first != 0) {
			queue.push(pair1);
		}
	}
}
