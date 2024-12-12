#include<iostream>
#include<vector>
using namespace std;

/*
1->+ve
-1->-ve
0->0
*/
int sign(vector<int> v,int x){
    int sign=1;
    for(auto e:v){
        if(e==x){
            return 0;
        }
        else if(e>x){
            sign*=-1;
        }
    }
    return sign;
}

int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<int> v(N);
    for(int &i:v){cin>>i;}
    while(Q--){
        int x;
        cin>>x;
        int res=sign(v,x);
        if(res==1){
            cout<<"POSITIVE";
        }
        else if(res==-1){
            cout<<"NEGATIVE";
        }
        else{
            cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}