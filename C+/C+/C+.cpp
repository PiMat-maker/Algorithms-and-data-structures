#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct cmp_str{

	bool operator()(char const *a, char const *b) const
	{
		return strcmp(a, b) == 0;
	}
};

struct Hash_Func {
	int operator()(char * str)const
	{
		int seed = 131;
		int hash = 0;
		while (*str)
		{
			hash = (hash * seed) + (*str);
			str++;
		}

		return hash & (0x7FFFFFFF);
	}
};

void doBlockLevel(unordered_map<char*, int, Hash_Func, cmp_str> map) {
	string s;
	while (cin >> s) {
		if (s[0] == '}') return;
		if (s[0] == '{') {
			doBlockLevel(map);
			continue;
		}
		int pos = s.find("=");
		char* nameVar = new char[pos+1];
		strncpy_s(nameVar, pos+1, s.c_str(), pos);
		char* val = new char[s.size() - pos];
		strncpy_s(val, s.size() - pos, s.c_str() + pos + 1, s.size() - pos - 1);
		if (isdigit(val[0]) || val[0] == '-') {
			map.erase(nameVar);
			map.insert({ nameVar, atoi(val) });
		}
		else {
			auto it = map.find(val);
			if (it != map.end()) {
				int value = it->second;
				map.erase(nameVar);
				map.insert({nameVar, value});
				cout << value << "\n";
			}
			else {
				map.erase(nameVar);
				map.insert({ nameVar, 0});
				cout << 0 << "\n";
			}
		}
	}
}

int main()
{
	unordered_map<char*, int, Hash_Func, cmp_str> map;
	doBlockLevel(map);
}