#include<bits/stdc++.h>
using namespace std;

bool solve(){
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    long long sum=0ll;
    // check if any prefix has non-positive sum
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum<=0) return 0;
    }
    // check if any suffix has non-positive sum
    sum=0ll;
    for(int i=n-1;i>=0;i--){
        sum+=a[i];
        if(sum<=0) return 0;
    }
    return 1;
}


int main()
{
    int tt;cin>>tt;
    while(tt--){
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    return 0;
}