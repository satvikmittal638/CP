#include<iostream>
#include<vector>
using namespace std;

bool isSuffice(long long r,vector<long long> a,vector<long long> b){
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(abs(a[i]-b[j])<=r) i++;
        else j++;
    }
    return i==a.size(); // all towers received the network succesfully
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long> a(n),b(m); // non dec arrays
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    // fathest tower and nearest city(wrt to O)
    //farthest city and nearest tower(wrt to O)
    long long lo=0,hi=max(abs(a[n-1] - b[0]), abs(a[0] - b[m-1])); 
    while(lo<hi){
        long long mid=lo+(hi-lo)/2;
        if(isSuffice(mid,a,b)){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo;
    return 0;
}