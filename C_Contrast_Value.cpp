#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(auto &i:a) cin>>i;
        if(n==1) {
            cout<<1<<"\n";continue;
        }
        if(n==2){
            if(a[0]==a[1]) cout<<1<<"\n";
            else cout<<2<<"\n";
            continue;
        }
        int sz=n, prev=0,cur=1;
        
        cout<<sz<<"\n";
        
    }
    return 0;
}