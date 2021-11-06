#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<char, int>> letters;
	for (int i = 0; i < s.size(); ++i) {
		letters.push_back({ s[i], i });
	}

	sort(letters.begin(), letters.end());
	
	string res = "";
	int current_pos = letters[n - 1].second;
	while (res.size() < s.size()) {
		res += s.substr(current_pos, 1);
		current_pos = letters[current_pos].second;
	}

	cout << res;
}

