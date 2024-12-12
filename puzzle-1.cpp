#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& a){
    /*
    0-> asc
    1-> desc
    */
    bool nature=(a[1]-a[0])<0; 
    for(int i=0;i<a.size()-1;i++){
        int diff=a[i+1]-a[i];
        bool curNat=diff<0;
        if(1>abs(diff) || abs(diff)>3 || ()){

        }
    }
}

int main()
{
    long long a;
    vector<int> v;
    long long cnt=0;
    while(cin>>a){
        v.emplace_back(a);
        if(cin.peek() == '\n') {
            
        }
            v.clear();//clear for next list
    }
    cout<<cnt;
    
    return 0;
}