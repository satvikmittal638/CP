#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

vector<int> deleteTwoOccurrences(vector<int>& arr, int element) {
    vector<int> result;
    int count = 0; 
    for (int x : arr) {
        if (x == element && count < 2) {
            count++; 
        } else {
            result.push_back(x);
        }
    }
    return result;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);
       map<int,int> f;
       for(auto &i:a) {
        cin>>i;
        f[i]++;
       }

    //    int cnt2,cnt4;
    //    cnt2=cnt4=0;
    //    for(auto &p:f){
    //     cnt2+=(3>=p.second && p.second>=2);
    //     cnt4+=(p.second>=4);
    //    }
    //    // all distinct elements
    //    if(cnt2==0 && cnt4==0){
    //     cout<<"-1\n";
    //     continue;
    //    }

        int x=-1,y=-1,z=-1,w=-1;
        // make a rectangle
    //    if(cnt2>=2){
    //     for(auto e:a){
    //         if(f[e]>=2){
    //             if(x==-1) x=e;
    //             else if(y==-1) y=e;
    //             else if(z==-1) z=e;
    //             else if(w==-1) w=e;
    //             else break;
    //         }
    //     }
    //    }
       // make a square
    //     if(cnt4>=1){
    //     for(auto e:a){ 
    //         if(f[e]>=4){
    //             x=y=z=w=e;
    //             break;
    //         }
    //     }
    //    }
    //    // only 1 element with freq 2 or 3
    //    else{
        for(auto e:a){
            if(f[e]>=2) {
                x=y=e;
                break;
            }
        }
        a=deleteTwoOccurrences(a,x); // remove the repetitive element
        f[x]-=2;
        
        // now search for 2 elements z and w s.t. |z-w|<2x-->z<=w+2x+1
        sort(all(a));
        bool ok=0;
        // fix a w and search for z
        for(int i=0;i<a.size()-1;i++){
            auto loBound=lower_bound(a.begin()+i+1,a.end(),a[i]+2*x);
            if(loBound>a.begin()+i+1){
                loBound--;
                w=a[i];
                z=*loBound;
                ok=1;
                break;
            }
        }
        if(!ok) {
            cout<<"-1\n";
            continue;
        }
    //    }
       cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n";
    }
    return 0;
}