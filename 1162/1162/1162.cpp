#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int n, m, s;
	double v;
	vector<int> visit(103, 0);
	vector<int> index(103, 0);
	vector<double> money(103, 0);
	vector<vector<pair<double, double>>> currency(103, vector<pair<double, double>>(103));

	cin >> n >> m >> s >> v;

	for (int i = 0; i < m; i++)
	{
		int s, e;
		double r1, c1, r2, c2;
		cin >> s >> e >> r1 >> c1 >> r2 >> c2;
		currency[s][e].first = r1;
		currency[s][e].second = c1;
		currency[e][s].first = r2;
		currency[e][s].second = c2;
	}
	
	money[s] = v;
	visit[s] = 1;
	index[s] = 1;
	queue<int> q;
	q.push(s);
	int in;
	while (!q.empty())
	{
		in = q.front();
		q.pop();
		visit[in] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (money[i] < ((money[in] - currency[in][i].second)*currency[in][i].first))
			{
				money[i] = ((money[in] - currency[in][i].second)*currency[in][i].first);
				if (!visit[i])
				{
					visit[i] = 1;
					q.push(i);
					index[i]++;
					if (index[i] > n)
					{
						cout << "YES";
						return 0;
					}
				}
			}
		}

	}

	cout << "NO";
	return 0;
}