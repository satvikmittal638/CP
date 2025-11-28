#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=2*1e5;
int main()
{
fastio;
vector<int> spf(MAX + 5);
  // Set spf[i] = i
  iota(begin(spf), end(spf), 0);
  for (int i = 2; i * i <= MAX; i++) {
      if (spf[i] != i) continue;
      // if spf[i] = i then i must be a prime number.
      // Any multiple of i less than i * i (i.e., i * 2, i * 3, ... i * (i - 1)) has a smaller prime factor than i.
      // Any number >= i * i may have i as it's minimum prime factor
      for (int j = i * i; j <= MAX; j += i) spf[j] = min(spf[j], i);
  }

    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<int>> spf_to_nums(n+1,vector<int>()); // total size is n only
       for(int i=1;i<=n;i++){
        spf_to_nums[spf[i]].push_back(i);
       }
       vector<int> sizes_by_spf(n+1,0);
       //now flatten the array to align chains like (spfs with size>2)(spfs with size=1)
       deque<int> dq;
       for(int i=1;i<=n;i++){
        sizes_by_spf[i]=spf_to_nums[i].size();
    }
    // len>=2
    for(int i=1;i<=n;i++){
        if(spf_to_nums[i].size()==1) continue;
        for(auto e:spf_to_nums[i]) dq.push_back(e);
    }
    // len=1
    for(int i=1;i<=n;i++){
        if(spf_to_nums[i].size()!=1) continue;
        for(auto e:spf_to_nums[i]) dq.push_back(e);
    }

    //    for(auto e:dq) cout<<e<<' ';
    //    // now pair 2 elts from the left with 1 elts from the right
       vector<int> ans;

       ans.push_back(dq.back());// can start with a outlier(next 2 won't be coprime so no problem)
       sizes_by_spf[spf[dq.back()]]--;
       dq.pop_back();

       while(dq.size()){
        int e=dq.front();
        // if atleast 2 elts of this chain remain, the next elt must be just ahead of it
        if(sizes_by_spf[spf[e]]>=2){
            ans.push_back(dq.front());dq.pop_front();
            ans.push_back(dq.front());dq.pop_front();
            sizes_by_spf[spf[e]]-=2;
        }
        // no elt left to keep in pair
        else{
            dq.push_back(dq.front());dq.pop_front();
            sizes_by_spf[spf[e]]--;
        }
        // put one coprime elt(coprime in worst case, maybe be non-coprime as well)
        if(dq.size()){
            ans.push_back(dq.back());dq.pop_back();    
            sizes_by_spf[spf[dq.back()]]--; 
        }  
       }
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';

    }
    return 0;
}