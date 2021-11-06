#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> positions;

void addInPositions(queue<int> &queue, int num_of_car) {
	if (!queue.empty()) {
		positions.push({ queue.front() , num_of_car });
	}
	else {
		positions.push({ 500001, num_of_car });
	}
}

int main()
{
	int n, k, p, a;
	cin >> n >> k >> p;
	vector<bool> is_on_the_floor(n, false);
	vector<queue<int>> pos_of_cars(n);
	vector<int> order(p);
	
	for (int i = 0; i < p; ++i) {
		cin >> order[i];
		pos_of_cars[--order[i]].push(i);
	}
	
	int num_of_changes = 0;
	int num_of_cars = 0;
	for (int i = 0; i < p; ++i) {
		if (num_of_cars < k) {
			if (!is_on_the_floor[order[i]]) {
				++num_of_changes;
				is_on_the_floor[order[i]] = true;
				++num_of_cars;
			}
		}
		else {
			if (!is_on_the_floor[order[i]]) {
				int num_of_car = positions.top().second;
				positions.pop();
				is_on_the_floor[num_of_car] = false;
				is_on_the_floor[order[i]] = true;
				++num_of_changes;
			}
		}
		pos_of_cars[order[i]].pop();
		addInPositions(pos_of_cars[order[i]], order[i]);
	}

	cout << num_of_changes;
}