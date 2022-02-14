#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int total = 0;
	int first = s[0] - '0';


	if (s.size() >= 2) {
		int second = s[1] - '0';

		//맨 앞 두 숫자 비교해서 더하거나 곱하기
		if (first == 0 || first == 1 || second == 0 || second == 1) {
			total += (first + second);
		}
		else {
			total += (first * second);
		}
		//3번째 숫자부터는 0이나 1인 경우 더하기, 아닌 경우 곱하기
		for (int i = 2; i < s.size(); i ++) {
			int next = (s[i] - '0');
			if (next == 1 || next == 0) {
				total += next;
			}
			else {
				total *= next;
			}
		}
	}
	else {//숫자가 1개만 있는 경우
		total += first;
	}
	
	cout << total<<"\n";
	return 0;
}