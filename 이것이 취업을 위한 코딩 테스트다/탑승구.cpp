//탑승구

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int G,P;

int gates[100001];

int findParent(int x){
    if(gates[x]==x) return x;
    
    return gates[x]=findParent(gates[x]);
}

void Union(int a, int b){
    a=findParent(a);
    b=findParent(b);
    
    if(a<b){
        gates[b]=a;
        
    }else{
        gates[a]=b;
    }
    return;
}

int main(){
    cin>>G;
    cin>>P;
    
    for(int i=1;i<=G;i++){ //게이트 부모 자기 자신으로 초기화
        gates[i]=i;
    }
    
    int plane,result=0;
    for(int i=0;i<P;i++){
        cin>>plane;
        
        if(findParent(plane)!=0){
            Union(plane-1,plane);
            result++;
        }else{
            break;
        }
    }
    
    for(int i=0;i<=G;i++){
        cout<<gates[i]<<" ";
    }
    cout<<endl;
    
    cout<<result<<"\n";
    return 0;
}
