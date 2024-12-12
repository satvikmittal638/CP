#include<bits/stdc++.h>
using namespace std;

bool cyclic_compare(string s1,string s2){
     string orientations[] = {
        s1,
        s1.substr(3, 1) + s1.substr(0, 3),
        s1.substr(2, 2) + s1.substr(0, 2),
        s1.substr(1, 3) + s1.substr(0, 1)
    };

    for(auto o:orientations){
        if(o==s2) return 1;
    }
    return 0;
}

int main()
{
    int n;cin>>n;
    vector<string> amulets(n);
    for(int i=0;i<n;i++){
        string s1,s2;cin>>s1>>s2;
        reverse(s2.begin(),s2.end());
        amulets[i]=s1+s2;
        if(i<n-1) {string tmp;cin>>tmp;} // skip **
    }
    vector<int> pile(n,-1);
    int pileType=0;
    for(int i=0;i<n;i++){
        if(pile[i]==-1){
            for(int j=i+1;j<n;j++){
                if(pile[j]==-1 && cyclic_compare(amulets[i],amulets[j])){
                    pile[j]=pileType;
                }
            }
            pileType++;
        }
    }
    cout<<pileType;
    return 0;
}