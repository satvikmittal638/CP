#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    long long s;
    cin>>n>>s;
    vector<long long>c(n),w(n);
    for(auto &i:w) cin>>i;
    for(auto &i:c) cin>>i;
    int i=0,j=0;
    long long wt=0,cost=0,maxCost=0;
    while(j<n && i<=j){
        wt+=w[j];cost+=c[j];
        // make a suitable combo
        while(wt>s){
            wt-=w[i];cost-=c[i];
            i++;
        }
        maxCost=max(maxCost,cost);
        j++;
    }
    cout<<maxCost;
    return 0;
}