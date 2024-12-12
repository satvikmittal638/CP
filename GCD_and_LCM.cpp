// #include <bits/stdc++.h>
#include<iostream>
#include<numeric>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int x,y,k,sum;
	    cin>>x>>y>>k;
	    // numbers becomes equal after atleast 2 opn
	    if(k>=2){
	        sum=2*gcd(x,y);
	    }else{
	        sum=gcd(x,y)+min(x,y);
	    }
	    cout<<sum<<endl;
	}
    return 0;
}
