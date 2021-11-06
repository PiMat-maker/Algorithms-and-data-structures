#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> values;
vector<bool> isDelete(100000, false);
string s;

void deleteItem(vector<pair<int,int>> ends) {
	for (int j = 0; j < ends.size(); ++j) {
		for (int i = ends[j].first; i < ends[j].second; ++i) {
			isDelete[i] = true;
		}
	}
	
}

int findValue(vector<int> &v) {
	while (v.size()){
		if (isDelete[v.back()]) {
			v.pop_back();
		}
		else {
			return v.back();
		}
	}
	return -1;
}

void doBlockLevel(unordered_map<string, vector<int>> &map, int start) {
	vector<pair<int, int>> ends(1, {start, 0});
	while (cin >> s) {
		if (s[0] == '}') {
			values.push_back(0);
			ends.back().second = values.size();
			deleteItem(ends);
			return;
		}
		if (s[0] == '{') {
			values.push_back(0);
			ends.back().second = values.size() - 1;
			doBlockLevel(map, values.size() - 1);
			ends.push_back({ values.size(), 0 });
			continue;
		}
		int pos = s.find("=");
		string nameVar = s.substr(0, pos);
		s.erase(0, pos + 1);
		int value = 0;

		if (isdigit(s[0]) || s[0] == '-') {
			value = stoi(s);
		}
		else {
			auto it = map.find(s);
			if (it != map.end()) {
				int ptr = findValue(it->second);
				if (ptr != -1) {
					value = values[ptr];
				}
				cout << value << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		auto iter = map.find(nameVar);
		if (iter != map.end()) {
			vector<int> v = iter->second;
			map.erase(nameVar);
			v.push_back(values.size());
			values.push_back(value);
			map.insert({ nameVar, v });
		}
		else {
			vector<int> v;
			v.push_back(values.size());
			values.push_back(value);
			map.insert({ nameVar, v });
		}
	}
}

int main()
{
	unordered_map<string, vector<int>> map;
	doBlockLevel(map, 0);
}