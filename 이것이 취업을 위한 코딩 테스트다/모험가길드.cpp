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

	sort(v.begin(), v.end()); //�������� ����

	int group = 0;
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		count++;
		if (count == v[i]) { //������x�� �׷��ο��� ���� ���
			group++;
			count = 0;
		}
	}

	cout << group << "\n";

	return 0;
}
