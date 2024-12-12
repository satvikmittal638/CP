#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int> > grid(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        grid[i][0]=0; // 1st col empty
        grid[i]=vector<int>(n+1,0); // 1st row empty
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='*') grid[i][j]=1;
            else grid[i][j]=0;
        }
    }
    //pre-processing
    vector<vector<int> > prefix(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j]=prefix[i][j-1]+prefix[i-1][j]+grid[i][j]-prefix[i-1][j-1];
        }
    }


    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        int cnt=prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1];
        cout<<cnt<<"\n";
    }
    return 0;
}