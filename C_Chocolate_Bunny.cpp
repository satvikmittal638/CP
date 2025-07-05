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
    vector<int> p(n+1,0);
    set<int> undet_ind;
    for(int i=1;i<=n;i++) undet_ind.insert(i);
    for(int i=1;i<=n-1;i+=2){
        int x1,x2;
        cout<<"? "<<i<<" "<<i+1<<endl;cin>>x1;
        cout<<"? "<<i+1<<" "<<i<<endl;cin>>x2;
        if(x1>x2){
            p[i]=x1;
            undet_ind.erase(i);
        }
        else{
            p[i+1]=x2;
            undet_ind.erase(i+1);
        }
    }
    // O(n)
    while(undet_ind.size()>1){
        int i=*undet_ind.begin(),j=*undet_ind.rbegin();
        int x1,x2;
        cout<<"? "<<i<<" "<<j<<endl;cin>>x1;
        cout<<"? "<<j<<" "<<i<<endl;cin>>x2;
        if(x1>x2){
            p[i]=x1;
            undet_ind.erase(i);
        }
        else{
            p[j]=x2;
            undet_ind.erase(j);
        }
    }
    vector<bool> used(n+1,0);
    int pos=-1;
    for(int i=1;i<=n;i++) {
        used[p[i]]=1;
        if(p[i]==0) pos=i; 
    }
    // find single unused element
    for(int i=1;i<=n;i++){
        if(!used[i]) {
            p[pos]=i;
            break;
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}