#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        // (i,j) for pairs
        long long winning=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // to find the winning
                for(int k=0;k<m;k++){
                    winning+=abs(v[i][k]-v[j][k]);
                }
            }
        }
        winning/=2; // each pair was counted twice
        cout<<winning<<"\n";
    }
    return 0;
}