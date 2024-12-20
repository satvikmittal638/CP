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
        double d;cin>>d;
        if(d>=4 || d==0){
            double a=(d-sqrt(d*d-4*d))/2,b=d-a;
            if(a>=0){
                cout<<"Y ";
                cout<<fixed<<setprecision(9)<<a<<" "<<b<<"\n";
            }else{
                cout<<"N\n";
            }

        }else{
            cout<<"N\n";
        }
    }
    return 0;
}