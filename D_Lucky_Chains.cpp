#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

vector<int> minD;
vector<int> getPrimes(int v) {
	vector<int> ps;
	while (v > 1) {
		if (ps.empty() || ps.back() != minD[v])
			ps.push_back(minD[v]);
		v /= minD[v];
	}
	return ps;
}
int main()
{
fastio;
    // Precompute minD upto 1e7
    int MAX=1e7+2;
    minD.assign(MAX,0);
    minD[1]=1;
    for(int i=2;i<MAX;i++){
        // prime found, cross out its multiples
        if(minD[i]==0){
            for(int j=i;j<MAX;j+=i){
               if(minD[j]==0) minD[j]=i;
            }
        }
    }
    int n;cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        // Prime factorize y-x
        int r=INT_MAX;
        if((y-x)==1){
            cout<<"-1\n";
            continue;
        }
        for(auto p:getPrimes(y-x)){
            r=min(r,((x+p-1)/p)*p);
        }
        cout<<r-x<<"\n";

    }

    return 0;
}