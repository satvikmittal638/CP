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
       int n,m,k;cin>>n>>m>>k;
       vector<int> inv_a(k);
       for(int i=0;i<k;i++){
        int x;cin>>x;x--;
        inv_a[x]=i;
       }

    //    for(auto e:inv_a) cout<<e<<" ";
       // leaving (1,1) and (n,m) there must always exist an empty cell 
       // which would allow us to move the desired card to (n,m)
       int max_active=n*m-3,mx_ind=-1,active_cards=0;
       bool ok=1;
       for(int i=k-1;i>=0;i--){
        // the card is made active
        if(inv_a[i]>mx_ind){
            active_cards+=inv_a[i]-mx_ind; // all cards from mx_ind+1 to inv_a[i] are made active to move 
            if(active_cards>max_active){
                ok=0;
                break;
            }
            mx_ind=inv_a[i];
            active_cards--; // successfully put the card i at (n,m)
        }
        // the card is already active
        else{
            active_cards--; // put the card at its location
        }
       }
       cout<<(ok?"YA":"TIDAK")<<"\n";
    }
    return 0;
}