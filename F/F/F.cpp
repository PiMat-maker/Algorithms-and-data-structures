#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
	return a + b > b + a;
}

int main()
{
	vector<string> strings;
	string s;
	while (cin >> s) {
		strings.push_back(s);
	}
	sort(strings.begin(), strings.end(), comp);
	for (auto s : strings) {
		cout << s;
	}
}
