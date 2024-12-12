#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> brand_cost(k+1,0);
        while(k--){
            int b,c;cin>>b>>c;
            brand_cost[b]+=c;   
        }
        sort(brand_cost.begin(),brand_cost.end(),greater<int>());
        // now take first n elements
        long long maxCost=0,cnt=0;
        for(int cost:brand_cost){
            if(cnt<n && cost!=0){
                maxCost+=cost;
                cnt++;
            }else{
                break; // 
            }
        }
        cout<<maxCost<<"\n";

    }
    return 0;
}