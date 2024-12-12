#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(n+1),prefix(n+1);
    a[0]=prefix[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    long long count=0;
    map<long long,int> mp; // prefix sum->frequency

    /*
    sum[i,j]=pref[j]-pref[i-1]
    x=sum-(sum-x)
    for each sum, search for a (sum-x) --> TC=O(nlogn)
    */
    for(long long sum:prefix){
        count+=mp[sum-x]; // if other prefix sum(i.e. x-sum) exists, then a valid subarray is formed
        mp[sum]++; // increment the count of the prefix sum found
    }
    cout<<count;
    return 0;
}