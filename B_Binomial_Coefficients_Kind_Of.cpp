#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n[t],k[t];
    for(int i=0;i<t;i++){
        cin>>n[i];
    }
    for(int i=0;i<t;i++){
        cin>>k[i];
    }
    int N=1e5,MOD=1e9+7;
    vector<vector<int> > C(N+1,vector<int>(N+1));
    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1])%MOD;
    }
    for(int i=0;i<t;i++){
        cout<<C[n[i]][k[i]]<<endl;
    }
    return 0;
}