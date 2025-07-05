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
       int n;cin>>n;
       string s;cin>>s;
       vector<int> cnt(26,0);
       for(auto e:s) cnt[e-'a']++;
       vector<pair<int,char>> cnt_to_char;
       for(int i=0;i<26;i++){
        cnt_to_char.emplace_back(cnt[i],'a'+i);
       }
       sort(rall(cnt_to_char));
       // gets the minm cost as well as the string for minm cost
       // to make cnt_char chars each have a frequency of f
       auto getMinCost=[&](int f,int cnt_char){
        string t(n,' ');
        // choose largest cnt_char chars acoording to their frequency
        // and pick any min(f,cnt[c]) positions in s and put them in corr positions in t 
        for(int i=0;i<cnt_char;i++){
            char c=cnt_to_char[i].second;
            int num_places=min(f,cnt[c-'a']);
            for(int i=0;i<n;i++){
                if(s[i]==c && num_places){
                    t[i]=c;
                    num_places--;
                }
            }
        }
        vector<int> placed(26, 0);
        for(int i=0;i<cnt_char;i++){
            placed[cnt_to_char[i].second - 'a'] = min(f, cnt[cnt_to_char[i].second - 'a']);
        }

    // Fill the rest with remaining needed chars
    for(int i=0;i<n;i++){
        if(t[i] == ' '){
            for(int j=0;j<cnt_char;j++){
                char c = cnt_to_char[j].second;
                int id = c - 'a';
                if(placed[id] < f){
                    t[i] = c;
                    placed[id]++;
                    break;
                }
            }
        }
    }

        // compute the cost
        int cost=0;
        for(int i=0;i<n;i++) cost+=(s[i]!=t[i]);
        return make_pair(cost,t);
       };

       string ans;
       int minCost=INT_MAX;
       // we can have atmost 26 distinct chars in a string
       for(int i=1;i<=26;i++){
        if(n%i==0){
            auto [cost,cur_ans]=getMinCost(n/i,i);
            if(cost<minCost){
                minCost=cost;
                ans=cur_ans;
            }
        }
       }
       cout<<minCost<<"\n"<<ans<<"\n";
       
    }
    return 0;
}