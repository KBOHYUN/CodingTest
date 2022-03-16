//프로그래머스 주차 요금 계산

#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<set>
#include<cmath>
using namespace std;

struct Car{
    int outCheck=false;
    int start=0;
    int end=1439; //23:59
};

int carTime[10000]={0,};
Car cars[10000];

vector<string> split(string input, char deli){
    vector<string> ans;
    stringstream ss(input);
    string temp;
    while(getline(ss,temp,deli)){
        ans.push_back(temp);
    }
    
    return ans;

}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    set<int> carset;
    
    for(int i=0;i<records.size();i++){
        vector<string> sp=split(records[i],' ');
        int h=stoi(sp[0].substr(0,2))*60;
        int m=stoi(sp[0].substr(3,5));
        
        int num=stoi(sp[1]);
        
        if(sp[2]=="IN"){
            carset.insert(num);
            cars[num].outCheck=false;
            cars[num].start=h+m;
            
        }else if(sp[2]=="OUT"){
            int outTime=h+m;
            cars[num].outCheck=true;
            carTime[num]+=(outTime-cars[num].start);
        }
    }

    for(set<int>::iterator iter=carset.begin();iter!=carset.end();iter++){
        if(cars[*iter].outCheck==false){
            carTime[*iter]+=(cars[*iter].end-cars[*iter].start);
        }
        double t=carTime[*iter];
        cout<<t<<endl;
        if(t>fees[0]){
            cout<<ceil((t-fees[0])/fees[2]);
            answer.push_back(fees[1]+(ceil((t-fees[0])/fees[2])*fees[3]));
        }else{
            answer.push_back(fees[1]);
        }
    }
    return answer;
}
