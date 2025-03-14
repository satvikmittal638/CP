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
       vector<int> a(n);for(auto &i:a) cin>>i;
       map<int,int> cnt;
       for(auto &i:a) cnt[i]++;
       sort(all(a));
       int x1,x2,y1,y2;
       x1=x2=y1=y2=INT_MAX;


       for(int i=0;i<n;i++){
        if(cnt[a[i]]>=2){
            x1=a[i];
            cnt[x1]-=2;
            break;
        }
       }
       for(int i=0;i<n;i++){
        if(cnt[a[i]]>=2){
            y1=a[i];
            cnt[y1]-=2;
            break;
        }
       }

       for(int i=n-1;i>=0;i--){
           if(cnt[a[i]]>=2){
               y2=a[i];
               cnt[y2]-=2;
               break;
            }
        }
        for(int i=n-1;i>=0;i--){
         if(cnt[a[i]]>=2){
             x2=a[i];
             cnt[x2]-=2;
             break;
         }
        }
       if(x1==INT_MAX || x2==INT_MAX || y1==INT_MAX || y2==INT_MAX){
        cout<<"NO\n";
        continue;
       }
       cout<<"YES\n";
       cout<<x1<<" "<<y1<<" "<<x2<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x1<<" "<<y2<<"\n";
    }
    return 0;
}