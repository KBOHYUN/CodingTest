#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAXN 300001
using namespace std;

int N, M, K, X;
vector<int> v[MAXN];
long dist[MAXN];
bool visited[MAXN];
vector<int> result;

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;

	while (!q.empty()) {
		int s = q.front();
		q.pop();

		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i];

			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[s] + 1;

				if (dist[next] == K) {
					result.push_back(next);
				}
			}
		}

	}
	return;
}
int main() {
	cin >> N >> M >> K >> X;

	int a,b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	BFS(X);
	
	if (result.size() > 0) {
		sort(result.begin(), result.end());

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}