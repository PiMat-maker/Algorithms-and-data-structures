#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

void deleteTrash(unordered_map<string, vector<int>> &map, string name, int numOfBlocks) {
	
}

int main()
{
	string s;
	vector<unordered_map<string, string>> stack(1);
	int numOfBlocks = 0;

	while (cin >> s) {
		if (s[0] = '{') {
			++numOfBlocks;
			unordered_map<string, string> map;
			stack.push_back(map);
			continue;
		}
		if (s[0] = '}') {
			--numOfBlocks;
			stack.pop_back();
			continue;
		}
		int pos = s.find("=");
		string nameVar = s.substr(0, pos);
		s.erase(0, pos + 1);
		if (isdigit(s[0]) || s[0] == '-') {
			unordered_map<string, string> map = stack.back();
			stack.pop_back();
			map.erase(nameVar);
			map.insert({ nameVar, s });
			stack.push_back(map);
			
			
		}
		else {
			unordered_map<string, string> map = stack.back();
			stack.pop_back();
			if (map.find(s) != map.end()) {

			}
			stack.push_back(map);
		}
	}
}