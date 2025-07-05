#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void insertBetween(vector<int>& v, int a, int b, int x) {
    auto it_a = find(v.begin(), v.end(), a);
    auto it_b = find(v.begin(), v.end(), b);

    if (it_a == v.end() || it_b == v.end()) {
        return;
    }

    // insert after the earlier of a and before the later
    if (distance(v.begin(), it_a) < distance(v.begin(), it_b)) {
        v.insert(it_b, x);  // insert before b
    } else {
        v.insert(it_a, x);  // insert before a
    }
}


bool isOrdered(vector<int> a1, vector<int> a) {
    vector<int> v1, v2;
    for (int i = 0; i < a1.size(); i++) {
        if (a1[i] != a[0]) v1.push_back(a1[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != a1[0]) v2.push_back(a[i]);
    }
    return v1 == v2;
}
// function to check consistency
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       bool ok=1;
       vector<int> s1,s2,a1;
       for(int _=0;_<k;_++){
        vector<int> a(n);for(auto &i:a) cin>>i;
        if(_==0){
            a1.push_back(a[0]);
            for(int i=1;i<n;i++) {
                s1.push_back(a[i]);
                s2.push_back(a[i]);
                a1.push_back(a[i]);
            }
            
        }
        else if(_==1){
            // check for consistent relative ordering b/w a1 and a
            if(!isOrdered(a1,a)) {
                ok=0;
                continue;
            }
            
            int l_first=-1,r_first=-1;
            int l_second=-1,r_second=-1;
            // find neighbours of first(acc to 2nd ss)
            /*
            if l==-1 -> position of 'first' is 0 or 1
            if r==-1 -> position of 'first' is n-1 or n-2
            */
            for(int i=1;i<n;i++){
                if(a[i]==a1[0]){
                    if(i>1)l_first=a[i-1];
                    if(i<n-1)r_first=a[i+1];
                }
            }
            // find neighbours of 2nd (acc to 1st ss)
            for(int i=1;i<n;i++){
                if(a1[i]==a[0]){
                    if(i>1)l_second=a1[i-1];
                    if(i<n-1)r_second=a1[i+1];
                }
            }
            // both have same neighbours -> we have 2 possible sequences now
            if(l_first==l_second && r_first==r_second){
                insertBetween(s1,a[0],r_second,a1[0]);
                insertBetween(s2,l_second,a[0],a1[0]);
            }
            // both have different ngbrs -> a uniqe sequence is determined
            else{
                insertBetween(s1,l_first,r_first,a1[0]);
                s2.clear();
            }

        }
        
        // check for consistency with s1 and/or s2
        else{
            bool cur=1;
            bool ok1=1,ok2=1;
            if(s1.size()){
                vector<int> tmp(s1);
                tmp.erase(find(all(tmp),a[0]));
                a.erase(a.begin());
                for(int i=0;i<n-1;i++){
                    if(tmp[i]!=a[i]){
                        ok1=0;
                        break;
                    }
                }
            }
            if(s2.size()){
                vector<int> tmp(s2);
                tmp.erase(find(all(tmp),a[0]));
                a.erase(a.begin());
                for(int i=0;i<n-1;i++){
                    if(tmp[i]!=a[i]){
                        ok2=0;
                        break;
                    }
                }
            }
            if(!ok1) s1.clear();
            if(!ok2) s2.clear();
            cur=ok1|ok2;
            ok&=cur;
            if(!ok) break; 
        }
        cout<<(ok?"YES":"NO")<<"\n";
    
    }
    }
    return 0;
}