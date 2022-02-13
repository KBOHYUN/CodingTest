//BJ1647 ���� ���� ��ȹ

#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAXN 100001

using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> cost;

int parent[MAXN];

int findParent(int x) {

    if (parent[x] == x) return x;

    return parent[x] = findParent(parent[x]);

}

void Union(int x, int y) {

    x = findParent(x);
    y = findParent(y);

    parent[x] = y;

    findParent(x);
}



int main() {
    long long N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int a, b, c;

    for (long long i = 0; i < M; i++) {

        cin >> a >> b >> c;

        v.push_back(make_pair(a, b));
        cost.push_back(make_pair(c, i));

    }

    //����� ���� ������� ����
    sort(cost.begin(), cost.end());

    int maxCost = 0;

    long long result = 0;

    for (int i = 0; i < cost.size(); i++) {
        //����Ŭ�� ������ �ʴ� ���
        if (findParent(v[cost[i].second].first) != findParent(v[cost[i].second].second)) {

            Union(v[cost[i].second].first, v[cost[i].second].second);

            result += cost[i].first;

            maxCost = cost[i].first; //������ �̷�� �� �߿��� ���� ū ���

        }

    }


    cout << result - maxCost;

    return 0;

}