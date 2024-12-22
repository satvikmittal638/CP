#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

long long fibonacci(long long n, long long F1, long long F2) {
    if (n == 1) return F1;
    if (n == 2) return F2;

    const long long MOD = 998244353;

    vector<vector<long long>> matrix = {
        {1, 1},
        {1, 0}
    };

    vector<vector<long long>> result = {
        {1, 0},
        {0, 1}
    };

    // Matrix exponentiation(binary way :)
    long long power = n - 2;
    while (power > 0) {
        if (power % 2 == 1) {
            vector<vector<long long>> temp = {
                {
                    (result[0][0] * matrix[0][0] + result[0][1] * matrix[1][0]) % MOD,
                    (result[0][0] * matrix[0][1] + result[0][1] * matrix[1][1]) % MOD
                },
                {
                    (result[1][0] * matrix[0][0] + result[1][1] * matrix[1][0]) % MOD,
                    (result[1][0] * matrix[0][1] + result[1][1] * matrix[1][1]) % MOD
                }
            };
            result = temp;
        }
        vector<vector<long long>> temp = {
            {
                (matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0]) % MOD,
                (matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1]) % MOD
            },
            {
                (matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0]) % MOD,
                (matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1]) % MOD
            }
        };
        matrix = temp;
        power /= 2;
    }

    return (result[0][0] * F2 + result[0][1] * F1) % MOD;
}


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
        cout<<fibonacci(n,1,2)<<"\n";
    }
    return 0;
}