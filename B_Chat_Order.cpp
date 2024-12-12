#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<string> names(n);
    for(auto &i:names) cin>>i;

    reverse(names.begin(),names.end());
    // the person at the last will be at the top
    set<string> seen;
    vector<string> seq;
    for(auto name:names) {
        if(seen.find(name)==seen.end()){
            seq.emplace_back(name);
            seen.insert(name);
        }
    }
    for(auto name:seq) cout<<name<<"\n";
    return 0;
}