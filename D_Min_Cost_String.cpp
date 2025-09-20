#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    set<string> st;
    string ans;
    ans+='a';
    // construct a string of 0 cost
    // atmost k*k distinct xy pairs can be formed
    for(int i=0;i<k*k;i++){
        for(char c='a'; c<'a'+k;c++){
            string tmp;
            tmp+=ans.back();
            tmp+=c;
            if(st.count(tmp)==0){
                ans+=c;
                st.insert(tmp);
            }
        }
    }
    if(ans.size()>=n){
        ans=ans.substr(0,n);// trim to reqd length
    }
    // rpt this unit to cover the entire length
    else{
        string tmp=ans;
        int z=ans.size(); // length of rpting unit
        while(ans.size()+z<n){
            ans+=ans;
        }
        // add trimmed portion
        int i=0;
        while(ans.size()<n){
            ans+=tmp[i++];
        }
    }
    cout<<ans;
    return 0;
}