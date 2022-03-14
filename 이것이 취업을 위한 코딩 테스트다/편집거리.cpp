//편집거리

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;
int main(){
    int test, n,m;
    cin>>test;
    
    for(int t=0;t<test;t++){
        cin>>n>>m;
        int arr[401]={0, };
        for(int i=0;i<n*m;i++){
            cin>>arr[i];
        }
        int v[21][21];
        int index=0;
        //int maxResult=0;
        
        for(int i=0;i<n;i++){ //2차원 배열로 재배열
            for(int j=0;j<m;j++){
                v[i][j]=arr[index++];
            }
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                if(i==0){ //맨 윗줄인 경우 -> 오른쪽, 오른쪽아래방향
                    v[i][j]+=max(v[i][j-1],v[i+1][j-1]);
                }
                else if(i==n-1){//맨 밑줄 경우 -> 오른쪽, 오른쪽윗방향
                    v[i][j]+=max(v[i][j-1],v[i-1][j-1]);
                }else{ //가운데 -> 3방향으로 갈 수 있는 경우
                    int temp=max(v[i][j-1],v[i+1][j-1]);
                    temp=max(temp,v[i-1][j-1]);
                    v[i][j]+=temp;
                }
            }
        }
        
        int maxResult=0;
        for(int i=0;i<n;i++){
            maxResult=max(maxResult, v[i][m-1]);
        }
        cout<<maxResult<<"\n";
    }
}
