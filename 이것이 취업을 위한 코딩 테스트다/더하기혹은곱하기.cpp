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

		//�� �� �� ���� ���ؼ� ���ϰų� ���ϱ�
		if (first == 0 || first == 1 || second == 0 || second == 1) {
			total += (first + second);
		}
		else {
			total += (first * second);
		}
		//3��° ���ں��ʹ� 0�̳� 1�� ��� ���ϱ�, �ƴ� ��� ���ϱ�
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
	else {//���ڰ� 1���� �ִ� ���
		total += first;
	}
	
	cout << total<<"\n";
	return 0;
}