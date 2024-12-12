#include<iostream>
#include<vector>
using namespace std;

void printAr(vector<int> v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n][n];
    int inp;
    vector<int> rowS(n,0),colS(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    // find row and col sum
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rowS[i]+=a[i][j];
        }
    }

    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            colS[j]+=a[i][j];
        }
    }
            
    // printAr(rowS,n);
    // cout<<endl;
    // printAr(colS,n);
    // cout<<endl<<endl;
    // calculate number of winning squares
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(colS[j]>rowS[i]){
                count++;
            }
        }
    }
    cout<<count;
    

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    // }
    return 0;
}