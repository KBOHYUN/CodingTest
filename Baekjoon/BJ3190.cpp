#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;
#define MAXN 101

int arr[MAXN][MAXN] = { 0, };
bool snakeCheck[MAXN][MAXN];

char direction_time[10001];

queue<pair<int, int>> snake;

int N, K, L;

int resultTime = 0;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int nowDirection = 0; //ó���� ���������� ����

int main() {
	cin >> N>>K;

	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		arr[a][b] = 1; //��� ��ġ ǥ��
	}

	char c;
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> a >> c;
		direction_time[a] = c; 
	}

	snake.push({ 1,1 }); //�� ��ġ
	snakeCheck[1][1] = true;

	while (1) {
		resultTime++;

		int nx = snake.back().first + dy[nowDirection];
		int ny = snake.back().second + dx[nowDirection];

		if (nx<1 || ny<1 || nx>N || ny>N) { //���� ����°��
			break;
		}

		snake.push({ nx,ny });

		if (direction_time[resultTime] == 'D') { //�������� ���
			nowDirection += 1;
			if (nowDirection == 4) {
				nowDirection = 0;
			}
		}
		else if (direction_time[resultTime] == 'L') { //������ ���
			nowDirection -= 1;
			if (nowDirection == -1) {
				nowDirection = 3;
			}
		}

		if (arr[nx][ny] == 1) { //����� �ִ� ���
			arr[nx][ny] = 0;
		}
		else { //��� ���� ��� ���� �پ���
			if (snakeCheck[nx][ny] == true) break;
			snakeCheck[snake.front().first][snake.front().second] = false;
			snake.pop();
		}
		
		//�ڱ� �ڽŰ� ��ġ�� ���
		if (snakeCheck[nx][ny] == true) break;
		else snakeCheck[nx][ny] = true;
	}

	cout << resultTime << endl;

	return 0;
}