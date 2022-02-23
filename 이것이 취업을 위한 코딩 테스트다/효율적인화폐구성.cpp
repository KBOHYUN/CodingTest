#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 101
#define MAXM 10001

using namespace std;

int money[MAXM]; //������ִ� �ּ� ȭ�󰳼�
int bill[MAXN]; //ȭ�� ����


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(money, money + MAXN, MAXM); //�ִ밪���� �ʱ�ȭ

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