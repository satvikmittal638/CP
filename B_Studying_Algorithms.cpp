#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long n,x;
    cin>>n>>x;
    vector<long long> a(n);
    for(auto &i:a) cin>>i;
    sort(a.begin(),a.end());
    long long i=0;
    while (i < n && x >= a[i]) {
        x -= a[i++];
    }
    cout<<i; // loop terminates at required index+1
    return 0;
}