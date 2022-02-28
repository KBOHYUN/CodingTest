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
int nowDirection = 0; //처음에 오른쪽으로 진행

int main() {
	cin >> N>>K;

	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		arr[a][b] = 1; //사과 위치 표시
	}

	char c;
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> a >> c;
		direction_time[a] = c; 
	}

	snake.push({ 1,1 }); //뱀 위치
	snakeCheck[1][1] = true;

	while (1) {
		resultTime++;

		int nx = snake.back().first + dy[nowDirection];
		int ny = snake.back().second + dx[nowDirection];

		if (nx<1 || ny<1 || nx>N || ny>N) { //범위 벗어나는경우
			break;
		}

		snake.push({ nx,ny });

		if (direction_time[resultTime] == 'D') { //오른쪽인 경우
			nowDirection += 1;
			if (nowDirection == 4) {
				nowDirection = 0;
			}
		}
		else if (direction_time[resultTime] == 'L') { //왼쪽인 경우
			nowDirection -= 1;
			if (nowDirection == -1) {
				nowDirection = 3;
			}
		}

		if (arr[nx][ny] == 1) { //사과가 있는 경우
			arr[nx][ny] = 0;
		}
		else { //사과 없는 경우 꼬리 줄어들기
			if (snakeCheck[nx][ny] == true) break;
			snakeCheck[snake.front().first][snake.front().second] = false;
			snake.pop();
		}
		
		//자기 자신과 겹치는 경우
		if (snakeCheck[nx][ny] == true) break;
		else snakeCheck[nx][ny] = true;
	}

	cout << resultTime << endl;

	return 0;
}