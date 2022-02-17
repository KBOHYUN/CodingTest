#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 6

using namespace std;

char g[MAXN][MAXN];
vector<pair<int, int>> t,b; //teacher,blank

int N;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool checkStudent(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;

		while (nx >= 0 && ny >= 0 && nx < N && ny < N) { //한방향으로 계속 이동하면서 체크하기
			if (g[nx][ny] == 'O') break;
			if (g[nx][ny] == 'S') return false;
			nx += dx[i];
			ny += dy[i];
		}
	}

	return true;
}

void DFS(int count, int idx) {

	if (count == 3) {
		for (int i = 0; i < t.size(); i++) {
			if (!checkStudent(t[i].first, t[i].second)) {
				return;
			}
		}
		cout << "YES";
		exit(0);
	}

	for (int i = idx; i < b.size(); i++) {
		g[b[i].first][b[i].second] = 'O';
		DFS(count + 1, i + 1);
		g[b[i].first][b[i].second] = 'X';
	}
	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >>g[i][j];
			if (g[i][j] == 'T') {
				t.push_back(make_pair(i, j));
			}
			else if (g[i][j] == 'X') {
				b.push_back(make_pair(i, j));
			}
		}
	}

	DFS(0, 0);

	cout << "NO";

	return 0;
}