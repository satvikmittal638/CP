#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// gives sequence of operations (l,r) to convert s->0..0 in <=n operations
vector<pair<int,int>> make0(string s){
    vector<pair<int,int>> opn;
    int i=0,n=s.size();
    while(i<n){
        if(s[i]!='1'){
            i++;
            continue;
        }
        int st=i,end;
        while(i<n && s[i]=='1') i++;
        end=i-1;
        if(st>=end || end==n) continue; // skip isolated 1
        // O.W. convert whole block of 1s to 0
        for(int i=st;i<=end;i++) s[i]='0';
        opn.emplace_back(st,end);
    }
    // Now s only consists of isolated 1s(if any 1 exists)
    while(count(all(s),'1')>1){
        i=0;
        while(i<n){
            // searching for a 1
            if(s[i]=='0'){
                i++;
                continue;
            }
            int st=i,end;
            i++;// skip this 1
            // search for next 1
            while(i<n && s[i]=='0') i++;
            end=i;// this is a 1 or a dead end
            if(st>=end || end==n) continue; // skip single 1
            i++; // consume next 1
            // perform opn on 10..01
            s[st]='0';
            s[end]='0';
            opn.emplace_back(st,end);
            // except for 101, we can immediately reduce 10..01 to 0..0 in 2 opn
            if(end-st+1>3){
                opn.emplace_back(st+1,end-1);
                for(int i=st;i<=end;i++) s[i]='0';
            }
            else{
                s[st]=s[end]='0';
                s[st+1]='1';
            }
        }

    }
    
    // demolish the single 1(for it can't be paired)
    i=0;
    while(i<n && s[i]=='0') i++;
    if(i==n) return opn;//no 1 left
    if(i>=2){
        opn.emplace_back(i-2,i-1);
        opn.emplace_back(i-2,i);
    }
    else if(i<=n-3){
        opn.emplace_back(i+1,i+2);
        opn.emplace_back(i,i+2);
    }
    return opn;
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       string s,t;cin>>s>>t;
       auto sTo0=make0(s),tTo0=make0(t);
       reverse(all(tTo0));
       cout<<sTo0.size()+tTo0.size()<<'\n';
       for(auto [l,r]:sTo0){
        cout<<l+1<<' '<<r+1<<'\n';
       }
       for(auto [l,r]:tTo0){
        cout<<l+1<<' '<<r+1<<'\n';
       }
    }
    return 0;
}