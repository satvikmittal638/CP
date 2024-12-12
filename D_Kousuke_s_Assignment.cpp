#include<iostream>
#include<vector>
#include<set>
// #include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long> a(n+1),prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            prefix[i]=prefix[i-1]+a[i];
        }
        set<long long> st;
        int cnt=0;
        // st.insert(0);
        for(int i=0;i<=n;i++){
            if(st.count(prefix[i])>0){
                cnt++;
                st.clear();
                // st.insert(0);
            }
            st.insert(prefix[i]);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}