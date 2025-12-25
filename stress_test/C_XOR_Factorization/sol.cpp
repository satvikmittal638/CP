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
        ll n,k;cin>>n>>k;
        if(k%2!=0){
            for(int i=0;i<k;i++) cout<<n<<' ';
        }
        else{
            multiset<ll> ms;
            for(int i=0;i<k;i++) ms.insert(0);
            ll i=30;
            while((n&(1<<i))==0) i--; // reach MSB
            for(;i>=0;i--){
                multiset<ll> tmp;
                ll mask=1<<i;
                // set bit-> need odd elts to have 1 here
                if(n&mask){
                    // choose smallest and set its bit
                    ll sml=*ms.begin();
                    if((sml|mask)<=n){
                        sml|=mask;
                        ms.erase(ms.begin());
                        tmp.insert(sml);
                        // now take smallest elements in pairs and try to set their bits to 1 
                        while(ms.size()>=2){
                            ll f1=*ms.begin();ms.erase(ms.begin());
                            ll f2=*ms.begin();ms.erase(ms.begin());
                            if((f1|mask)<=n && (f2|mask)<=n){
                                f1|=mask;
                                f2|=mask;
                                tmp.insert(f1);
                                tmp.insert(f2);
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                // cleared bit-> an even no. of elts have 1
                else{
                    // take elts in pairs
                    // now take smallest elements in pairs and try to set their bits to 1 
                    while(ms.size()>=2){
                        ll f1=*ms.begin();ms.erase(ms.begin());
                        ll f2=*ms.begin();ms.erase(ms.begin());
                        if((f1|mask)<=n && (f2|mask)<=n){
                            f1|=mask;
                            f2|=mask;
                            tmp.insert(f1);
                            tmp.insert(f2);
                        }
                        else{
                            // add back w/o changing
                            tmp.insert(f1);
                            tmp.insert(f2);
                            break;
                        }
                    }
                }
                // copy elts from tmp back to ms
                for(const auto &e:tmp){
                    ms.insert(e);
                }  
            }
            
            for(const auto &e:ms){
                cout<<e<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}