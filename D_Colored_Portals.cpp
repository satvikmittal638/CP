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
       int n,q;cin>>n>>q;
       vector<string> c(n);for(auto &i:c) cin>>i;
       map<string,int> lastInd; // stores running last index for each city type
       
       // for nearest left
       lastInd["BG"]=lastInd["BR"]=lastInd["BY"]=lastInd["GR"]=lastInd["GY"]=lastInd["RY"]=-1;
       vector<int> nearestLeft(n,-1);
       for(int i=0;i<n;i++){
        lastInd[c[i]]=i;
        if(c[i]=="BR" || c[i]=="GY"){
            nearestLeft[i]=max({lastInd["BG"],lastInd["BY"],lastInd["GR"],lastInd["RY"]});
        }
        else if(c[i]=="BG" || c[i]=="RY"){
            nearestLeft[i]=max({lastInd["BR"],lastInd["BY"],lastInd["GR"],lastInd["GY"]});
        }
        else if(c[i]=="BY" || c[i]=="GR"){
            nearestLeft[i]=max({lastInd["BR"],lastInd["BG"],lastInd["RY"],lastInd["GY"]});
        }
       }
       // for nearest right
        lastInd["BG"]=lastInd["BR"]=lastInd["BY"]=lastInd["GR"]=lastInd["GY"]=lastInd["RY"]=n;
       vector<int> nearestRight(n,n);
       for(int i=n-1;i>=0;i--){
        lastInd[c[i]]=i;
        if(c[i]=="BR" || c[i]=="GY"){
            nearestRight[i]=min({lastInd["BG"],lastInd["BY"],lastInd["GR"],lastInd["RY"]});
        }
        else if(c[i]=="BG" || c[i]=="RY"){
            nearestRight[i]=min({lastInd["BR"],lastInd["BY"],lastInd["GR"],lastInd["GY"]});
        }
        else if(c[i]=="BY" || c[i]=="GR"){
            nearestRight[i]=min({lastInd["BR"],lastInd["BG"],lastInd["RY"],lastInd["GY"]});
        }
       }

    //    for(auto e:nearestLeft) cout<<e<<" ";
    //    cout<<"\n";
    //    for(auto e:nearestRight) cout<<e<<" ";
    //    cout<<"\n";

       while(q--){
        int x,y;cin>>x>>y;x--;y--;
        if(x>y) swap(x,y);
        // edge case
        if(c[x]==c[y]){
            cout<<(y-x)<<"\n";
            continue;
        }
        // x<y now
        int ans=-1;
        int nearL=nearestLeft[x],nearR=nearestRight[x];
        int ans1=abs(nearR-x)+abs(nearR-y),ans2=abs(nearL-x)+abs(nearL-y);
        if(nearL==-1 && nearR!=n) ans=ans1;
        else if(nearL!=-1 && nearR==n) ans=ans2;
        else if(nearL!=-1 && nearR!=n) ans=min(ans1,ans2);
        cout<<ans<<"\n";
       }
    }
    return 0;
}