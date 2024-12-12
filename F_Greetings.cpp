#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<long long,long long> p1,pair<long long,long long> p2){
    return p1.first<p2.first;
}
long long countInv(vector<pair<long long,long long> > &a,int st,int end){
    if(st>=end) return 0; // single elt-> no inversion possible
    int mid=(st+end)/2;
    long long totalInv=countInv(a,st,mid) + countInv(a,mid+1,end),additionalInv=0;
    vector<pair<long long,long long> > v(end-st+1); // dummy array
    int i=st,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(a[i].second<=a[j].second){
            v[k++]=a[i];
            i++;
        }else{
            v[k++]=a[j];
            // all elts at index>=i form valid inversions due to sorted arrays
            additionalInv += (mid - i + 1); // Count inversions
            j++;
        }
    }
    // append remaining elements
    while(i<=mid){
        v[k++]=a[i++];
    }
    while(j<=end){
        v[k++]=a[j++];
    }

    // reassign values to original array
    for(int i=0;i<v.size();i++){
        a[st+i]=v[i];
    }   
    totalInv+=additionalInv;
    return totalInv;

}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector< pair<long long,long long> > v(n);
        for(int i=0;i<n;i++){
            long long a,b;//start,end
            cin>>a>>b;
            v[i]=make_pair(a,b);
        }
        sort(v.begin(),v.end(),comp);
        // now just count inversions according to bi (bi>bj for i<j)
        cout<<countInv(v,0,n-1)<<"\n";
    }
    return 0;
}