#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string s;cin>>s;
    int n=s.length();
    int last=s[n-1]-'0';
    bool done=0;
    int lastEvePos=-1;
    for(int i=0;i<n-1;i++){
        int d=(s[i]-'0');
        if(d%2==0){
            if(last>d){
                swap(s[i],s[n-1]);
                done=1;
                break;
            }
            lastEvePos=i;
        }
    }
    if(!done && lastEvePos==-1){
        cout<<-1;
    }
    else{
        if(!done)swap(s[n-1],s[lastEvePos]);
        cout<<s;

    }

    return 0;
}