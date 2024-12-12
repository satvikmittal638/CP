#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// need to work in atmax O(n)
bool canAccomodate(int minDist,vector<int> v,int c){
    // simulate cow placing
    int cowsPlaced=1,lastPos=v[0]; // 1 cow is always placed at v[0]
    for(int i=1;i<v.size();i++){
        if(v[i]-lastPos>=minDist){
            cowsPlaced++;
            lastPos=v[i];
        }
        if(cowsPlaced==c){
            return 1;
        }
    }
    return cowsPlaced>=c;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> v(n);
        for(auto &i:v){cin>>i;}
        sort(v.begin(),v.end());
        int lo=v[1]-v[0],hi=v[n-1]-v[0];
        while(lo<hi){
            int mid=lo+(hi-lo+1)/2;
            if(canAccomodate(mid,v,c)){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        cout<<lo<<endl;
    }
    return 0;
}