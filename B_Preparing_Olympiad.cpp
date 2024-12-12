#include<iostream>
#include<vector>
using namespace std;

bool isValidPS(int ps,int n,int l, int r, int x,vector<int> &c){
    if(__builtin_popcount(ps)<2) return 0; // a PS must have atleast 2 probs
    
    int td=0,maxD=0,minD=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // if ith problem is chosen
        if((1<<i)&ps){
            int d=c[i];
            td+=d; // find total difficulty
            maxD=max(maxD,d);
            minD=min(minD,d);
        }
    }
    return (td>=l && td<=r) && (maxD-minD>=x);
}

int main()
{
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    vector<int> c(n);
    for(auto &i:c) cin>>i;
    // traverse all the subsets of c
    // each value of 'i' represents a valid subset
    int ways=0;
    for(int i=0;i<(1<<n);i++){
        ways+=isValidPS(i,n,l,r,x,c); // 1 if true, 0 otherwise
    }
    cout<<ways;
    return 0;
}