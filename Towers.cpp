#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> k(n);
    map<long long,int> mp; // elt->index
    for(int i=0;i<n;i++){
        cin>>k[i];
        mp[k[i]]=i;
    }
    long long count=0;
    for(int i=0;i<n-1;i++){

        //if block size of a prvs elt is larger than the subsequent element
        if(k[i]>k[i+1] && mp[k[i]]<mp[k[i+1]]){
            // do nothing since now k[i+1] sits on top of k[i]
        }else{
            count++;
        }
    }
    cout<<count;
    return 0;
}