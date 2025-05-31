#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    // fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n,res;
        cin >> n;
        cout<<"digit"<<endl;
        cin>>res;
        cout<<"digit"<<endl;
        cin>>res;
        cout<<"add -8"<<endl;
        cin>>res;
        cout<<"add -4"<<endl;
        cin>>res;
        cout<<"add -2"<<endl;
        cin>>res;
        cout<<"add -1"<<endl;
        cin>>res;
        cout<<"add "<<n-1<<endl;
        cin>>res;
        cout<<"!"<<endl;
        cin>>res;
    }

    return 0;
}