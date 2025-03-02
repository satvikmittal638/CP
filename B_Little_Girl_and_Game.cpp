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
    vector<int> cnt(26,0);
    vector<int> f;
    for(auto c:s) cnt[c-'a']++;
    for(auto e:cnt){
        if(e>0) f.push_back(e);
    }
    auto canMakePalin=[&](){
        if(n==0) return true;
        int cntO=0;
        for(auto e:f){
            cntO+=(e%2!=0);
        }
        if(n%2==0){
            return cntO==0;
        }
        else{
            return cntO==1;
        }
    };
    int chance=0;
    do{
        chance++;
        int i;
        for(i=0;i<f.size() && f[i]%2!=0;i++);
        if(i<f.size()) {
            f[i]--;
            if(f[i]==0) f.erase(f.begin()+i);
            // cout<<"Done ";
        }
        // all frequencies are odd, remove at random
        else{
            f[0]--;
            if(f[0]==0) f.erase(f.begin());
            // cout<<"Majburi ";
        }
        n--;
    }while(!canMakePalin());
    // cout<<chance<<"\n";
    cout<<(chance%2==0?"First":"Second")<<"\n";
    return 0;
}