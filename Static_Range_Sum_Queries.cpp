#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<long long> v(n+1),prefix(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    // pre-processing
    prefix[0]=0;prefix[1]=v[1];
    for(int i=2;i<=n;i++){
        prefix[i]=prefix[i-1]+v[i];
    }

    while(q--){
        int a,b; // 1 based-indexed
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<"\n";
    }
    return 0;
}