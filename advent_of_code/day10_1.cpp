#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

vector<int> toInts(const string &s) {
    vector<int> v;
    string cur;
    for (char ch : s) {
        if (isdigit(ch) || ch == '-') cur += ch;
        else if (!cur.empty()) {
            v.push_back(stoi(cur));
            cur.clear();
        }
    }
    if (!cur.empty()) v.push_back(stoi(cur));
    return v;
}
int main()
{
fastio;
    vector<string> lights;
    vector<vector<int>> jolts;
    vector<vector<vector<int>>> buttons;
    string line;
    int machineNo=0;
    while (getline(cin, line)) {
        string insideSquare;
        vector<string> insideParen;
        vector<string> insideBrace;

        for (int i = 0; i < (int)line.size(); i++) {
            if (line[i] == '[') {
                int j = line.find(']', i);
                insideSquare = line.substr(i + 1, j - i - 1);
                i = j;
            }
            else if (line[i] == '(') {
                int j = line.find(')', i);
                insideParen.push_back(line.substr(i + 1, j - i - 1));
                i = j;
            }
            else if (line[i] == '{') {
                int j = line.find('}', i);
                insideBrace.push_back(line.substr(i + 1, j - i - 1));
                i = j;
            }
        }
        lights.push_back(insideSquare);

        vector<vector<int>> machineButtons;
        for (auto &s : insideParen) {
            machineButtons.push_back(toInts(s));
        }
        buttons.push_back(machineButtons);

        vector<int> machineJolts;
        for (auto &s : insideBrace) {
            for (int x : toInts(s)) machineJolts.push_back(x);
        }
        jolts.push_back(machineJolts);
    }
    // cout<<"machines "<<lights.size()<<'\n';
    // int mx=0;
    // for(auto s:lights) mx=max(mx,(int)s.size());
    // cout<<"Max buttons "<<mx;
    int n=lights.size();
    ll ans=0ll;
    for(int i=0;i<n;i++){
        // try all subsets of buttons for each machine
        int mn=INT_MAX;
        for(int j=1;j<(1<<buttons[i].size());j++){
            string cur(lights[i].size(),'.');
            int sz = 0;
            for(int k = 0; k < (int)buttons[i].size(); k++){
                if(j & (1 << k)){
                    sz++;
                    for(int pos : buttons[i][k]){
                        cur[pos] ^= ('.' ^ '#'); // toggle
                    }
                }
            }
            if(cur==lights[i]) mn = min(mn, sz);
        }
        ans+=mn;
    }
    cout<<ans;
    
    return 0;
}