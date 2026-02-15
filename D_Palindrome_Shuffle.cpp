#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       string s;cin>>s;
       int n=s.length();
       // the opn must atleast include either of ends of trimmed(s)
       auto getMinL=[&](){
           vector<int> cntP(26,0),cntS(26,0);
           for(int z=0;z<n;z++) cntS[s[z]-'a']++;
           // let s[0] be included for sure
           // find minm l>=n/2 which works
           int l;
           for(l=0;l<n/2;l++){
               // update cntl and cnty
               cntP[s[l]-'a']++;
               cntS[s[l]-'a']--;
            }
            for(;l<n;l++){
               bool ok=1;
            // check if msS is subset of msP
            for(int i=0;i<26;i++){
                // not a subset
                // or msP has odd frequency of remaining chars after removing msS
                if(cntP[i]<cntS[i] || (cntP[i]-cntS[i])%2!=0){
                    ok=0;
                    break;
                }
               
            }
            if(ok) break; // found minm l

            // update cntl and cnty
            cntP[s[l]-'a']++;
            cntS[s[l]-'a']--;
           }
           return l;
       };

       // trim equal prefix and suffix
       vector<bool> remove(n,0);
       for(int i=0;i<n/2;i++){
        if(s[i]==s[n-1-i]) remove[i]=remove[n-1-i]=1;
        else break;
       }
       string tmps;
       for(int i=0;i<n;i++){
        if(!remove[i]) tmps+=s[i];
       }
       s=tmps;
       n=s.length();
    //    cout<<s<<'\n';
       // try to find longest palin substr in middle
       int j=n/2,i=j-1;
       while(i>=0 && j<n && s[i]==s[j]){
        i--;
        j++;
       }
       int minL=INT_MAX;
       // now take s[0,i] to match with s[j,n-1] by some rgmt if some palindrome exists in middle
       // now check if prefix=suffix
       vector<int> cntP(26,0),cntS(26,0);
       for(int z=0;z<=i;z++){
        cntP[s[z]-'a']++;
       }
       for(int z=n-1;z>=j;z--){
        cntS[s[z]-'a']++;
       }
       if(cntP==cntS) minL=i+1;
       // O.W. choose l>=n/2
       minL=min(minL,getMinL());
       reverse(all(s));
       minL=min(minL,getMinL());
       cout<<minL<<'\n';

    }
    return 0;
}