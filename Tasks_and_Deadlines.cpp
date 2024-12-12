#include<iostream>
#include<algorithm>
#include<map>
using namespace std;


bool compare ( pair <int, int> &a, pair <int, int> &b ){
   return a.first < b.first;
}
int main()
{
    vector<pair<int,int> > v;
    int n;
    cin>>n;
    while(n--){
        // a-> duration
        // d-> deadline
        int a,d;
        cin>>a>>d;
        v.push_back(make_pair(a,d));
    }
    // sort by duration
    sort(v.begin(),v.end(),compare);

    long long int reward=0,time=0;
    for(auto p:v){
        time+=p.first;
        reward+=p.second-time;
        // cout<<reward<<" "<<time<<endl;
    }
    cout<<reward;
    return 0;
}