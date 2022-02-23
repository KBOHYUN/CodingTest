#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 101
#define MAXM 10001

using namespace std;

int money[MAXM]; //만들수있는 최소 화폐개수
int bill[MAXN]; //화폐 종류


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(money, money + MAXN, MAXM); //최대값으로 초기화

	int N, M;
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		cin >> bill[i];
	}

	money[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = bill[i]; j <= M; j++) {
			money[j] = min(money[j], money[j - bill[i]] + 1);
		}
	}

	if (money[M] == MAXM) {
		cout << -1;
	}
	else {
		cout << money[M];
	}



	return 0;
}