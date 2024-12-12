#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

// order of elimination(by health) decided by %k-->0(write it as k),k-1,k-2...1
// for same %k, elimination by index(lowest first)
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first; // ascending according to index
    }
    return p1.second > p2.second; // descending according to index
    
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int> > healths(n);  // index->health
        for (int i = 0; i < n; i++)
        {
            int health;
            cin >> health;
            if(health%k!=0){
                healths[i] = make_pair(i,health%k);
            }
            else{
                healths[i] = make_pair(i,k);
            }
            
        }
        sort(healths.begin(),healths.end(),comp);
        for(auto p:healths){
            cout<<p.first+1<<" "; // 1 based indexing to be displayed
        }
        cout<<endl;
    }
    return 0;
}