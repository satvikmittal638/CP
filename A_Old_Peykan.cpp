#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,k;cin>>m>>k;
    vector<int> d(m),s(m);
    for(auto &i:d) cin>>i;
    for(auto &i:s) cin>>i;
    int maxSoFar=INT_MIN,fuel=0,t=0;
    for(int i=0;i<m;i++){
        fuel+=s[i];//instantly take current stations fuel
        maxSoFar=max(maxSoFar,s[i]);
        // need additional wait time since the fuel we have currently isn't enough to cover the gap
        if(d[i]>fuel){
            int no_of_times=(d[i]-fuel+maxSoFar-1)/maxSoFar; // ceil((required-current)/max)
            t+=k*no_of_times; 
            fuel+=maxSoFar*no_of_times;
        }
        // cover d[i] now
        fuel-=d[i];
        t+=d[i];
    }
    cout<<t;
    return 0;
}