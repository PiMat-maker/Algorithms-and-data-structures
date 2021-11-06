#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> before_middle;
	deque<int> after_middle;
	int iter_nop = 0, iter_wp = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		int a;
		cin >> c;
		if (c == '+') {
			cin >> a;
			after_middle.push_back(a);
		}
		if (c == '*') {
			cin >> a;
			after_middle.push_front(a);
		}
		if (c == '-') {
			cout << before_middle.front() << endl;
			before_middle.pop();
		}

		if ((after_middle.size() + before_middle.size()) % 2 == 1 && after_middle.size() > before_middle.size()) {
			int a = after_middle.front();
			after_middle.pop_front();
			before_middle.push(a);
		}
	}

}