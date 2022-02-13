#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, scare;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> scare;
		v.push_back(scare);
	}

	sort(v.begin(), v.end()); //오름차순 정렬

	int group = 0;
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		count++;
		if (count == v[i]) { //공포심x와 그룹인원이 같은 경우
			group++;
			count = 0;
		}
	}

	cout << group << "\n";

	return 0;
}
