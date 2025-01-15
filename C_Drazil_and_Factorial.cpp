#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> dig;
    for(int i=0;i<n;i++) {
        char dc;cin>>dc;
        int d=dc-'0';
        if(d==4){
            dig.insert(dig.end(),{2,2,3});
        }
        else if(d==6){
            dig.insert(dig.end(),{3,5});
        }
        else if(d==8){
            dig.insert(dig.end(),{2,2,2,7});
        }
        else if(d==9){
            dig.insert(dig.end(),{2,3,3,7});
        }
        else{
            if(d!=0 && d!=1){
                dig.push_back(d);
            }
        }
    }
    sort(rall(dig));
    for(auto e:dig) cout<<e;
    return 0;
}