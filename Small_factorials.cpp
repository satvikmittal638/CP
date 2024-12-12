#include<iostream>
#include<vector>
using namespace std;

string multiply(string bigNum,int smallNum){
    string ans="";
    int carry=0;
    for(int i=bigNum.size()-1;i>=0;i--){
        int subAns=(bigNum[i]-'0')*smallNum + carry;
        ans=to_string(subAns%10)+ans; // append the digit to the left
        carry=subAns/10;
    }
    if(carry !=0) ans=to_string(carry)+ans;
    return ans;
}

int main()
{
    // preprocessing(find all 100 factorials)
    // store all factorials as strings to prevent overflow
    vector<string> v(101);
    v[0]="1";
    for(int i=1;i<=100;i++){
        v[i]=multiply(v[i-1],i);
    }

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<v[n]<<endl;
    }
    return 0;
}