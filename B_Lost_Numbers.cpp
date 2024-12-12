#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    /*
    ask 4 queries, ai.ai+1 for 1<=i<=4 then compute ai.ai+1 for all of the 6! permutations of [4, 8, 15, 16, 23, 42] 
    and return the correct permutation if found
    */
    vector<int> query(4),v={4, 8, 15, 16, 23, 42};
    for(int i=0;i<4;i++){
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        cout.flush();
        cin>>query[i];
    }
    do{
        bool isGood=1;
        for(int i=0;i<4;i++){
            if(query[i]!=v[i]*v[i+1]){
                isGood=0;break;
            }
        }
        if(isGood){
            break;
        }
    }while(next_permutation(v.begin(),v.end()));

    cout<<"!";
    for(auto e:v){
        cout<<" "<<e;
    }
    cout<<endl;
    cout.flush();
    return 0;
}