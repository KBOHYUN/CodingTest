//
//  main.cpp
//  bj11404
//
//  Created by 김보현 on 2022/02/10.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXN 2001
int N;

vector<int> arr;
int main(){
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    
    reverse(arr.begin(),arr.end());
    
    int dp[2000];
    fill(dp,dp+2000,1);
    
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    
    int maxCnt=0;
    
    for(int i=0;i<N;i++){
        maxCnt=max(maxCnt,dp[i]);
    }
    
    cout<<N-maxCnt<<"\n";
    

    
    return 0;
}
