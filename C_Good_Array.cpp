#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;
    long long sum=0ll;
    vector<long long> a(n);
    multiset<long long> ms; // to store duplicate values as well
    for(auto &i:a) {
        cin>>i;
        ms.insert(i);
        sum+=i;
    }

    vector<long long> ans;
    for(long long i=0;i<n;i++){
        long long newSum=sum-a[i];
        ms.erase(ms.find(a[i]));
        if(newSum%2==0 && ms.count(newSum/2)){
            ans.emplace_back(i);
        }
        // roll back the changes
        ms.insert(a[i]);
    }
    cout<<ans.size()<<"\n";
    for(auto j:ans) cout<<j+1<<" ";
    return 0;
}