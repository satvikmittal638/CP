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
    vector<int> c(2*n);for(auto &i:c) cin>>i;
    vector<int> a,b;
    int pmax=0;
    int i=0;
    // size(a)>=size(b) is guaranteed at each step according to our construction
    for(;i<2*n;i++){
        // no constraint on inserting at b, so insert something in a to add a constraint to b
        if(pmax==0){
            if(a.size()<n) {
                a.push_back(c[i]);
                pmax=c[i];
            }
        }
        else if(c[i]>pmax){
            b.push_back(c[i]);
            pmax=0;// move to next position in b with no constraints
        }
        // there are constraints on posn of b but they ain't satisfied till now
        else if(a.size()<n) a.push_back(c[i]);
        else break;

        // cout<<a.size()<<' '<<b.size()<<'\n';
        // for(auto e:a) cout<<e<<' ';
        // cout<<"\n";
        // for(auto e:b) cout<<e<<' ';
        // cout<<"\n\n";
    }
    // now put leftovers in b
    for(;i<2*n;i++) b.push_back(c[i]);

    // now try merging both a and b
    vector<int> merged;
    i=0;
    int j=0;
    while(i<n && j<n){
        if(a[i]<b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
    }

    // while(i<n) merged.push_back(a[i++]);
    // while(j<n) merged.push_back(b[j++]);

    for(auto e:merged) cout<<e<<' ';
    cout<<'\n';
    if(merged==c){
        for(auto e:a) cout<<e<<' ';
        cout<<'\n';
        for(auto e:b) cout<<e<<' ';
    }
    else{
        cout<<-1;
    }
    return 0;
}