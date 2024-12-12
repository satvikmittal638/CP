#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long h=((long long)sqrt(24ll*n+1ll)-1ll)/6ll;
        long long count=0;
        while(h>0){
            count++;
            n-=h*(3*h+1)/2;
            h=((long long)sqrt(24ll*n+1ll)-1ll)/6ll;
        }
        cout<<count<<"\n";
    }
    return 0;
}