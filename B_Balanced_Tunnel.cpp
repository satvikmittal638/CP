#include<bits/stdc++.h>
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
    int n;cin>>n;
    // use b as indices, a as values
    vector<int> a(n),b(n);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;

    vector<int> seq(n+1);
    for(int i=0;i<n;i++){
        seq[b[i]]=a[i];
    }
    // now just count number of inversions
    return 0;
}