#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> a(3);
    for(int i=1; i<=n; i++)
        if(!(i % 2))
            a[0].push_back(i);
        else if(!(i % 3))
            a[1].push_back(i);
        else
            a[2].push_back(i);
            
    // The original logic provided
    while(a[2].size() >= 1 && a[0].size() >= 2){
        cout << a[2].back() << ' ';
        a[2].pop_back();
        cout << a[0].back() << ' ';
        a[0].pop_back();
        cout << a[0].back() << ' ';
        a[0].pop_back();
    }
    while(a[2].size() >= 1 && a[1].size() >= 2){
        cout << a[2].back() << ' ';
        a[2].pop_back();
        cout << a[1].back() << ' ';
        a[1].pop_back();
        cout << a[1].back() << ' ';
        a[1].pop_back();
    }
    for(int i : a[0])
        cout << i << ' ';
    for(int i : a[1])
        cout << i << ' ';
    for(int i : a[2])
        cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) solve();
    }
}