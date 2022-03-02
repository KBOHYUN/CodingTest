#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include<tuple>

using namespace std;
#define MAXN 100001

int N;

struct score {
	string name;
	int korean, english, math;
};

bool comp(score a, score b) {
	if (a.korean == b.korean && a.english == b.english && a.math == b.math) return a.name < b.name;
	if (a.korean == b.korean && a.english == b.english) return a.math > b.math;
	if (a.korean == b.korean) return a.english < b.english;
	return a.korean > b.korean;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N;
	vector<score> students(N);

	for (int i = 0; i < N; i++) {
		cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
	}
	sort(students.begin(), students.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << students[i].name << "\n";
	}

	return 0;
}