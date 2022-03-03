#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include<tuple>

using namespace std;
vector<int> house;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		house.push_back(temp);
	}
	
	sort(house.begin(), house.end());

	if (house.size() % 2 == 0) {
		int f = house[house.size() / 2 - 1];
		int s = house[house.size() / 2];
		
		int ft = 0, st = 0;

		for (int i = 0; i < N; i++) {
			ft += abs(house[i] - f);
			st += abs(house[i] - s);
		}

		if (ft <= st) {
			cout << f << "\n";
		}
		else {
			cout << s << "\n";
		}
	}
	else {
		cout << house[house.size()/2] << "\n";
	}

	return 0;
}