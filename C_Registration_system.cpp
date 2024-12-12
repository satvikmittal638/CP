#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    map<string,int> db;
    while(n--){
        string s;cin>>s;
        // unique name
        if(db[s]==0){
            db[s]++;
            cout<<"OK\n";
        }else{
            cout<<s<<db[s]<<"\n";
            db[s]++;
        }
    }
    return 0;
}