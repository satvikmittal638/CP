#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string s;cin>>s;
    int n=s.length();
    cout<<"4\n";

    cout<<"R 2\n";
    string op1=s.substr(1,n-2);
    reverse(all(op1));
    s+=op1;
    n=s.length();
    // cout<<s<<"\n";

    cout<<"L 2\n";
    s=s[1]+s;
    n=s.length();
    // cout<<s<<"\n";


    cout<<"R 2\n";
    string op3=s.substr(1,n-2);
    reverse(all(op3));
    s+=op3;
    n=s.length();
    // cout<<s<<"\n";


    cout<<"R "<<n-1<<"\n";
    s+=s[0];
    // cout<<s;
    return 0;
}