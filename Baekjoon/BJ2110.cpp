#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, C;
vector<int> house;
bool chk(int mid) {
	int cnt = 1;
	int prev = house[0];

	for (int i = 0; i < N; i++) {
		if (house[i] - prev >= mid) {
			cnt++;
			prev = house[i];
		}
	}
	if (cnt >= C) {
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> N >> C;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		house.push_back(temp);
	}

	sort(house.begin(), house.end());

	int low = 1, high = house[N - 1] - house[0];
	int maxdistance = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (chk(mid)) {
			maxdistance = max(maxdistance, mid);
			low = mid + 1;

		}
		else {
			high = mid - 1;
		}
	}
	cout << maxdistance << "\n";
	return 0;
}