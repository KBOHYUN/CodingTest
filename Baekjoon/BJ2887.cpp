#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cmath>

#define MAXN 100001

using namespace std;

int N;

vector<tuple<int, int, int> > cost;

vector<pair<int, int>> X, Y, Z;

int parents[MAXN];


int FindParent(int x) {
	if (parents[x] == x) {
		return x;
	}
	return parents[x] = FindParent(parents[x]);
}

void Union(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);

	parents[x] = y;

	FindParent(x);

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		parents[i] = i; //부모배열 자기자신으로 초기화
	}

	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		X.push_back({ a,i });
		Y.push_back({ b,i });
		Z.push_back({ c,i });
	}

	//X,Y,Z값 각각 오름차순 정렬
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		cost.push_back({ X[i + 1].first - X[i].first,X[i].second, X[i + 1].second });
		cost.push_back({ Y[i + 1].first - Y[i].first,Y[i].second,Y[i + 1].second });
		cost.push_back({ Z[i + 1].first - Z[i].first,Z[i].second, Z[i + 1].second });
	}
	sort(cost.begin(), cost.end()); //거리에 따라 오름차순 정렬

	long long result = 0;
	int count = 0; //N-1도로만큼 추가
	for (int i = 0; i < cost.size(); i++) {
		if (FindParent(get<1>(cost[i])) != FindParent(get<2>(cost[i]))) {
			result += get<0>(cost[i]);
			count++;
			Union(get<1>(cost[i]), get<2>(cost[i]));
		}
		
		if (count == N-1) {
			break;
		}
	}

	cout << result << "\n";
	return 0;
}