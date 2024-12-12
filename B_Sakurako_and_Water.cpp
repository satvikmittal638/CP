#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > a(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        // traverse main diagonal wise 
        long long cnt=0;
        // traverse B.D + UTM diagonal wise
        for(int i=0;i<n;i++){
            // traverse diagonal starting from a[0][i]
            int mx=0;
            for(int j=i,k=0;j<n && k<n;j++,k++){
                // find most -ve number of the diagonal
                if(a[k][j]<0) mx=max(mx,abs(a[k][j]));
            }
            cnt+=mx;
        }

        // traverse LTM diagonal wise
        for(int i=1;i<n;i++){
            // traverse diagonal starting from a[i][0]
            int mx=0;
            for(int j=i,k=0;j<n && k<n;j++,k++){
                // find most -ve number of the diagonal
                if(a[j][k]<0) mx=max(mx,abs(a[j][k]));
            }
            cnt+=mx;
        }
        cout<<cnt<<"\n";

    }
    return 0;
}