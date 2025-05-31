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
        int n,m,k;cin>>n>>m>>k;
        vector<vector<char>> grid(n,vector<char>(m));
        vector<vector<bool>> isSafe(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                isSafe[i][j]=(grid[i][j]=='.');
            }
        }
        // since k>=1, we start from i=1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='*'){
                    int d=1;
                    // determine the maxm height of the tick with center at (i,j)
                    while(d<=min({i,j,m-1-j}) && grid[i-d][j-d]=='*' && grid[i-d][j+d]=='*'){
                        d++;
                    }
                    d--;
                    // cout<<i<<" "<<d<<"  ";
                    if(d>=k){
                        for(int h=0;h<=d;h++){
                            isSafe[i-h][j-h]=isSafe[i-h][j+h]=1;
                        }
                    }  
                }
            }
        }
        bool ok=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ok&=isSafe[i][j];
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";

        }
        return 0;
    }