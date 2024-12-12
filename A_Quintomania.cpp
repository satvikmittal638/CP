#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &i:a) cin>>i;
        bool isPerfect=1;
        for(int i=0;i<n-1;i++){
            if(abs(a[i+1]-a[i])!=5 && abs(a[i+1]-a[i])!=7){
                isPerfect=0;
            }
        }
        if(isPerfect) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}