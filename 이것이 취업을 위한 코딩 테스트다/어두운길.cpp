//어두운 길

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N,M;
int parent[200001];

vector<pair<int,int>> cost;
vector<pair<int,int>> road;

int findParent(int x){
    if(parent[x]==x) return x;
    
    return parent[x]=findParent(parent[x]);
}
void UnionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b){
        parent[b]=a;
    }else{
        parent[a]=b;
    }
}
int main(){
    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    
    int a,b,c;
    int roadTotal=0;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        road.push_back({a,b});
        cost.push_back({c,i});
        roadTotal+=c;
    }
    
    sort(cost.begin(),cost.end());
    int total=0;
    for(int i=0;i<M;i++){
        int h1=road[cost[i].second].first;
        int h2=road[cost[i].second].second;
        if(findParent(h1)!=findParent(h2)){
            UnionParent(h1,h2);
            total+=cost[i].first;
        }else{
            continue;
        }
    }
    cout<<roadTotal-total<<"\n";
    
    return 0;
}
