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
        unordered_map<int,vector<int>> inds;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            inds[a[i]].push_back(i);
        }
        int ansl=-1,ansr=-1,ansa=-1,ansScore=INT_MIN;
        for(auto &[val,p]:inds){
            /*
            the optimal subarray ends and starts where a[i]=val

            so for a pair of chosen indices i<=j in p:
            wins=(j-i+1) // all ones from indices i to j

            losses=(p[j]-p[i]+1)-(j-i+1) // no. of elts !=val = total-(no. of elts=val)

            score=wins-losses=2(j-i+1)-(p[j]-p[i]+1)
            =(2j-p[j])-(2i-p[i])+1

            Define f(m)=2m-p[m]
            then we need to maximize (f(j)-f(i)) over all i<=j

            This can be done by traversing over p by updating:  f(j)-(minm f(i) so far)
            */
           int minSoFar=INT_MAX,minInd=-1;
            for(int i=0;i<p.size();i++){
                if(minSoFar>=(2*i-p[i])){
                    minSoFar=2*i-p[i];
                    minInd=p[i];
                }
                int curScore=(2*i-p[i])-minSoFar+1;
                if(curScore>=ansScore){
                    ansScore=curScore;
                    ansa=val;
                    ansl=minInd;
                    ansr=p[i];
                }
            }
        }
        cout<<ansa<<" "<<ansl+1<<" "<<ansr+1<<"\n";
    }
    return 0;
}