#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int count=0;
    int i=0,j=0;
    while(i<n && j<m){
        // b[j] apartment is below aukaat for a[i] person 
        //so it is also below aukaat for a[i+1] and others ahead and hence useless
        if(a[i]-b[j]>k){
            j++;
        }
        // b[j] apartment is above aukaat for a[i] person so maybe in aukaat for a[i+1]
        else if(a[i]-b[j]<-k){
            i++;
        }
        // aukaat matched, lets move to a[i+1]th person and b[j+1]th apartment
        else{
            i++;j++;
            count++;
        }
    }
    cout<<count;
    return 0;
}