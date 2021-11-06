#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canSafelyComeToCage(string s, vector<int> &pairs, int offset) {
	int size = s.size();
	int start = 0, end = size;
	int i = size - 1;
	while (i < end){
		if (i == size - 1) {
			if (tolower(s[i]) != tolower(s[0]) || s[i] == s[0]) {
				++i;
				continue;
			}
			if (s[i] == tolower(s[i])) {
				pairs[offset] = pairs[(i + offset) % size];
			}
			else {
				pairs[(i + offset) % size] = pairs[offset];
			}
		}
		else {
			if (tolower(s[i]) != tolower(s[i + 1]) || s[i] == s[i + 1]) {
				++i;
				continue;
			}
			if (s[i] == tolower(s[i])) {
				pairs[(i + 1 + offset) % size] = pairs[(i + offset) % size];
			}
			else {
				pairs[(i + offset) % size] = pairs[(i + 1 + offset) % size];
			}
		}
		
		int j = i - 1;
		int k = (i + 2) % size;
		while (tolower(s[j]) == tolower(s[k]) && s[j] != s[k]  && j + 1 != k && j >= start && k <= end) {
			if (s[j] == tolower(s[j])) {
				pairs[(k + offset) % size] = pairs[(j + offset) % size];
			}
			else {
				pairs[(j + offset) % size] = pairs[(k + offset) % size];
			}
			--j;
			++k;
			if (j < 0) j = s.size() - 1;
			if (k >= s.size()) k = 0;
		}
		if (start == 0) {
			end = j;
			start = k;
		}
		else {
			if (j > start) return false;
			start = k;
		}
		
		i = start;
	}
	return start > end;
}

int main()
{
	string s, q;
	cin >> s;
	q = s;
	vector<int> pairs(s.size(), 0);
	int id = 1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == tolower(s[i])) {
			pairs[i] = id;
			++id;
		}
	}
	int offset = 0;
	if (tolower(s[s.size() - 1]) != tolower(s[0]) || s[s.size() - 1] == s[0]) {
		for (int i = 0; i < s.size() - 1; ++i) {
			if (tolower(s[i]) == tolower(s[i + 1]) && s[i] != s[i + 1]) {
				offset = i + 1;
				q = s.substr(i + 1, s.size()) + s.substr(0, i + 1);
				break;
			}
		}
		if (!offset) {
			cout << "Impossible";
			return 0;
		}
	}
	
	bool isPossible = canSafelyComeToCage(q, pairs, offset);
	if (!isPossible) {
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for (int i = 0; i < s.size(); ++i) {
		if (toupper(s[i]) == s[i]) {
			cout << pairs[i] << " ";
		}
	}
}