#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int oper[4] = { 0, };

int N;

vector<int> nums;

int rmin = 1000000001;
int rmax = -1000000001;

void cal(int index, int result) {
	if (index >= N) {
		if (rmin > result) {
			rmin = result;
		}
		if (rmax < result) {
			rmax = result;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0) {
				cal(index+1, result+nums[index]);
			}
			else if (i == 1) {
				cal(index + 1, result-nums[index]);
			}
			else if (i == 2) {
				cal(index + 1, result * nums[index]);
			}
			else {
				cal(index + 1, result / nums[index]);
			}
			oper[i]++;
		}
	}
	return;

}

int main() {
	
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		cin >> temp;
		oper[i] = temp;
	}

	cal(1, nums[0]);

	cout << rmax << "\n";
	cout << rmin << "\n";
	return 0;
}