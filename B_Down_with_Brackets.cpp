#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

bool isBalanced(string s) {
    int count = 0;
    for (char ch : s) {
        if (ch == '(')
            count++;
        else if (ch == ')')
            count--;
        
        // More closing brackets than opening at any point
        if (count < 0)
            return false;
    }
    return count == 0;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       string s;cin>>s;
       int n=s.length();
       bool ok=0;
       ok=!isBalanced(s.substr(1,n-2));
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}