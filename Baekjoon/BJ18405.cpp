#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

int N, M, X, Y, S;

#define MAXN 201
#define MAXM 1001

using namespace std;

int g[MAXN][MAXM];
vector<pair<int, int>> virus[MAXM];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void BFS() {

	queue<pair<int, int>> q; //바이러스 위치 저장 큐
	queue<int> indexq; // 각 바이러스의 번호 저장 큐

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < virus[i].size(); j++) {
			q.push(make_pair(virus[i][j].first, virus[i][j].second));
			indexq.push(i);
		}
	}

	for (int i = 0; i < S; i++) { //시간이 S초만큼 반복
		int qsize = q.size(); //각 초에서의 큐의 크기

		while (qsize) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int index = indexq.front();
			indexq.pop();

			//BFS 탐색
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
					continue;
				}
				if (g[nx][ny] == 0) {
					g[nx][ny] = index;
					q.push(make_pair(nx, ny));
					indexq.push(index);
				}
			}
			qsize--;
		}
	}

	return;

}

int main() {
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			g[i][j] = temp;
			if (temp > 0) {
				virus[temp].push_back(make_pair(i,j)); //1~K까지의 바이러스 위치 저장
			}
		}
	}

	cin >> S >> X >> Y;

	if (S == 0) { //초가 0인경우는 BFS 실행 X
		cout << g[X - 1][Y - 1];
	}
	else {
		BFS();
		cout << g[X - 1][Y - 1];
	}
	

	return 0;
}