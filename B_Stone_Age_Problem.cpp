#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;cin>>n>>q;
    vector<int> a(n);
    long long sum=0ll;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    while(q--){
        int t;cin>>t;
        int prevx=0;
        if(t==1){
            int i,x;
            cin>>i>>x;
            i--;// make 0-indexed
            sum+=x-a[i];
            a[i]=x;
        }
        else if(t==2){
            int x;
            cin>>x;
            sum=n*x;
            prevx=x;
            // set all elts to x in less than O(n)            
        }
        cout<<sum<<"\n";
    }
    return 0;
}