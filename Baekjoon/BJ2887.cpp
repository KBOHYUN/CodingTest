#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 30001

using namespace std;

int count[MAXN] = { 0, };


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		count[i] = count[i - 1] + 1;

		if (i % 2 == 0) {
			count[i] = min(count[i], count[i / 2] + 1);
		}
		if (i % 3 == 0) {
			count[i] = min(count[i], count[i / 3] + 1);
		}
		if (i % 5 == 0) {
			count[i] = min(count[i], count[i / 5] + 1);
		}
	}

	cout << count[i];


	
	return 0;
}