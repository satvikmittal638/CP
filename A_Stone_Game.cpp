#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &i:a) cin>>i;
        int minPos=min_element(a.begin(),a.end())-a.begin();
        int maxPos=max_element(a.begin(),a.end())-a.begin();
        /*
        4 ways-
        1) destroy min and max from left
        2) destroy min and max from right
        3) destroy min from left, max from right
        4) destroy max from left,min from right 
        */
       vector<int> choices={max(minPos,maxPos)+1,n-min(minPos,maxPos),
                            (minPos+1)+(n-maxPos),(maxPos+1)+(n-minPos)};
        int ans=*min_element(choices.begin(),choices.end());
        cout<<ans<<"\n";
    }       
    return 0;
}