#include<iostream>
#include<vector>
using namespace std;

void findDepth(vector<int>  a,int st,int end,vector<int> &d,int rootInd){ 
    if(st>end) return; // invalid calls terminated
    int maxInd,mx=INT_MIN;
    for(int i=st;i<=end;i++){
        if(a[i]>mx){
            mx=a[i];
            maxInd=i;
        }
    }
    d[maxInd]=d[rootInd]+1;
    // solve subproblems now
    findDepth(a,st,maxInd-1,d,maxInd); // left subtree
    findDepth(a,maxInd+1,end,d,maxInd); // right subtree
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),d(n,0);
        for(auto &i:a) cin>>i;
        // plant a seed
        int rootInd,mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]>mx){
                mx=a[i];
                rootInd=i;
            }
        }
        // grow the tree
        findDepth(a,0,rootInd-1,d,rootInd);
        findDepth(a,rootInd+1,n-1,d,rootInd);
        for(auto e:d) cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}