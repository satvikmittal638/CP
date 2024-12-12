#include<iostream>
#include<vector>
using namespace std;

long long countInv(vector<int> &a,int st,int end){
    if(st>=end) return 0; // single elt-> no inversion possible
    int mid=(st+end)/2;
    long long totalInv=countInv(a,st,mid) + countInv(a,mid+1,end),additionalInv=0;
    vector<int> v(end-st+1); // dummy array
    int i=st,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            v[k++]=a[i];
            i++;
        }else{
            v[k++]=a[j];
            // all elts at index>=i form valid inversions due to sorted arrays
            additionalInv += (mid - i+1); // Count inversions
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
        vector<int> a(n);
        for(auto &i:a) cin>>i;
        cout<<countInv(a,0,n-1)<<"\n";
    }   
    return 0;
}