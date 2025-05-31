#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       string s1,s2;cin>>s1>>s2;
       int n=s1.length();
       set<int> uneq_active;
       queue<pair<int,int>> uneq_inactive;
       for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            uneq_active.insert(i);
        }
       }
       int t,q;cin>>t>>q;
       int curT=0;
       while(q--){
        // update the blocked character list
        if(uneq_inactive.size()){
            auto [pos,time]=uneq_inactive.front();
            if(curT-time==t){
                uneq_inactive.pop();
                uneq_active.insert(pos);
            }
        }

        int type;cin>>type;
        if(type==1){
            int pos;cin>>pos;pos--;
            uneq_inactive.push({pos,curT});
            uneq_active.erase(pos);
        }
        else if(type==2){
            int c1,pos1,c2,pos2;cin>>c1>>pos1>>c2>>pos2;
            pos1--;pos2--;
            // make the swaps
            if(c1==1 && c2==1){
                swap(s1[pos1],s1[pos2]);
            }
            else if(c1==2 && c2==2){
                swap(s2[pos1],s2[pos2]);
            }
            else if(c1==1 && c2==2){
                swap(s1[pos1],s2[pos2]);
            }
            else{
                swap(s2[pos1],s1[pos2]);
            }
            // check the equality
            if(s1[pos1]!=s2[pos1]){
                uneq_active.insert(pos1);
            }
            else{
                uneq_active.erase(pos1);
            }
            if(s1[pos2]!=s2[pos2]){
                uneq_active.insert(pos2);
            }
            else{
                uneq_active.erase(pos2);
            }
        }
        else{
            cout<<(uneq_active.empty()?"YES":"NO")<<"\n";
        }
        // cout<<s1<<" "<<s2<<" "<<uneq_active.size()<<"\n";
        curT++;
       }
    }
    return 0;
}