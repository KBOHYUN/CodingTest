#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include<tuple>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	int ugly[1001];
	ugly[0] = 1;

	int i2 = 1, i3 = 1, i5 = 1;
	int two = 2, three = 3, five = 5;

	for(int i=1;i<N;i++){
		int minTemp = min(two, three);
		minTemp = min(minTemp, five);

		ugly[i] = minTemp;

		if (minTemp == two) {
			two=ugly[i2++]*2;
		}
		if (minTemp == three) {
			three = ugly[i3++] * 3;
		}
		if (minTemp == five) {
			five = ugly[i5++] * 5;
		}

	}
	cout << ugly[N-1];
	
	return 0;
}