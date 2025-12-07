#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
bool hasDigit(const string &s) {
    for(char c : s)
        if(isdigit(c)) return 1;
    return 0;
}
int main()
{
fastio;
   vector<string> numericRows;
    vector<char> ops;
    string line;
    while (1) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        if (hasDigit(line)) {
            numericRows.push_back(line);
        } else {
            // Operator line detected: Extract operators
            for (char c : line) {
                if (c == '+' || c == '*')
                    ops.push_back(c);
            }
            break;
        }
    }
    int mxCol=0;
    for(int i=0;i<numericRows.size();i++) mxCol=max(mxCol,(int)numericRows[i].size());
    ll ans=0ll,cur=0ll;;
    for(int j=mxCol-1;j>=0;j--){
        if(ops.back()=='*') cur=1ll;
        ll num=0ll,cntSpace=0;
        for(int i=0;i<numericRows.size();i++){
            if(numericRows[i][j]==' ') {
                cntSpace++;
                continue;
            }
            num=num*10+(numericRows[i][j]-'0');
        }
        if(ops.back()=='*') cur*=num;
        else cur+=num;

        // next column is beginning
        if(cntSpace==numericRows.size() || j==0){
            ans+=cur;
            cur=0ll;
            ops.pop_back();
        }

    }
    cout<<ans<<'\n';
    return 0;
}