#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

string hexToBin(char h) {
    int val = (h >= '0' && h <= '9') ? h - '0'
            : (h >= 'A' && h <= 'F') ? h - 'A' + 10
            : (h >= 'a' && h <= 'f') ? h - 'a' + 10 : 0;
    string bin;
    for(int i=3;i>=0;i--) bin.push_back((val>>i & 1) + '0');
    return bin;
}
int main()
{
fastio;
    int n;cin>>n;
    // 2-D prefix sum to count no. of 1s in any submatrix
    vector<vector<int>> cnt(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        char c;
        string row;
        for(int j=1;j<=n/4;j++){
            cin>>c;
            row+=hexToBin(c);
        }
        row=' '+row;
        for(int j=1;j<=n;j++){
            int num=row[j]-'0';
           cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+num;
        }
    }
    // checks if matrix is x-compressible
    auto check=[&](int x){
        for(int u=1;u<=n/x;u++){
            for(int v=1;v<=n/x;v++){
                int cur_cnt=cnt[x*u][x*v]-cnt[x*u][x*(v-1)]-cnt[x*(u-1)][x*v]+cnt[x*(u-1)][x*(v-1)];
                // all elts are not equal in the specified submatrix
                if(cur_cnt!=x*x && cur_cnt!=0){
                    return 0;
                }
            }
        }
        return 1;
    };
    // O(root(n)log^2(n))
    int maxX=1;
    for(int x=1;x*x<=n;x++){
        if(n%x==0){
            if(check(x)) maxX=max(maxX,x);
            if(check(n/x)) maxX=max(maxX,n/x);
        }
    }
    cout<<maxX;
    return 0;
}