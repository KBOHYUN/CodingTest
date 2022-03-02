#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

#define MAXN 51
int N, M, answer=1e9;
int graph[MAXN][MAXN];

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> cal;

bool chickenCheck[14];
int distanceCalculate()
{
	int sum = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int x = house[i].first;
		int y = house[i].second;
		int d = 1e9;

		for (int j = 0; j < cal.size(); j++)
		{
			int xx = cal[j].first;
			int yy = cal[j].second;
			int Dist = abs(xx - x) + abs(yy - y);

			d = min(d, Dist);
		}
		sum += d;
	}
	return sum;
}


void joinChicken(int index,int cnt) {
	
	if (cnt == M) {
		answer = min(answer, distanceCalculate());
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		if (chickenCheck[i] == true) continue;

		chickenCheck[i] = true;
		cal.push_back(chicken[i]);
		joinChicken(i, cnt +1);
		chickenCheck[i] = false;
		cal.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int input;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			graph[i][j] = input;

			if (input == 1) {
				house.push_back({ i,j });
			}
			else if (input == 2) {
				chicken.push_back({ i,j });
			}

		}
	}

	joinChicken(0, 0);
	cout << answer;

	return 0;
}