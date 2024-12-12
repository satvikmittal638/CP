#include<iostream>
#include<vector>
#include <climits>
using namespace std;


bool isSuffice(vector<int> &shed_register){
    for(auto shed:shed_register){
        if(shed>0) return 0; // some requirements still left to be fulfilled
    }
    return 1;
}

/*
returns the minimum amount of needed by FJ
traverse all the subsets of ACs
*/
int solve(vector<int> &s,vector<int> &t,vector<int> &c,
vector<int> &a,vector<int> &b,vector<int> &p,vector<int> &m,int k,int cost,bool toInclude,vector<int> shed_register)
{
    // a subset is formed
    if(k==m.size()){
        if(isSuffice(shed_register)) return cost;
        else return INT_MAX; // to reject out this possiblity when using the minimum function
    } 
    //Updating the register when kth AC is included
    if(toInclude){
        for(int i=a[k];i<=b[k];i++){
            shed_register[i]-=p[k];
        }
        cost+=m[k];
    }

    // include kth AC or not
    return min(solve(s,t,c,a,b,p,m,k+1,cost,1,shed_register),
                solve(s,t,c,a,b,p,m,k+1,cost,0,shed_register));
}

int main()
{
    int N,M; //M=10 can be assumed
    cin>>N>>M;
    /*
    cow lives in stalls [si,ti]
    needs temp lowered by atleast ci amount
    */
    vector<int> s(N),t(N),c(N); // describe cows
    for(int i=0;i<N;i++){
        cin>>s[i]>>t[i]>>c[i];
    }
    /*
    ith AC cools down stalls in [ai,bi]
    cost incurred by ith AC is mi
    temp is reduced by amount pi
    */
    vector<int> a(M),b(M),p(M),m(M); // describe ACs
    for(int i=0;i<M;i++){
        cin>>a[i]>>b[i]>>p[i]>>m[i];
    }
    vector<int> shed_register(101,0); // keeps tracks of needs of cows
    //initialise the register with initial cow requirements(
    //put 0 if no cow +nt at that location(s))
    for(int i=0;i<N;i++){
        for(int j=s[i];j<=t[i];j++){
            shed_register[j]=c[i];
        }
    }
    // include the 0th AC or not
    cout<<min(solve(s,t,c,a,b,p,m,0,0,0,shed_register),
        solve(s,t,c,a,b,p,m,0,0,1,shed_register));

    return 0;
}