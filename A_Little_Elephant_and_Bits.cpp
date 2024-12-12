#include<iostream>
using namespace std;
int main()
{
    string num; // in binary form
    cin>>num;
    // remove the leftmost clear bit
    bool isTrimmed=0;
    for(int i=0;i<num.size();i++){
        if(num[i]=='0'){
            num.erase(num.begin()+i);
            isTrimmed=1;
            break;
        }
    }
    // no trimming iff all bits are 1
    if(!isTrimmed){
        num.erase(num.begin());
    }
    cout<<num;
    return 0;
}