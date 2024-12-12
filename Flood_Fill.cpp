#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oriCol=image[sr][sc];
        queue<int> qr,qc;
        qr.push(sr);qc.push(sc);
        set<pair<int,int>> visited;

        vector<int> drow={-1,0,1,0},
                    dcol={0,-1,0,1};

        while(!qr.empty()){
            int row=qr.front(),col=qc.front();
            qr.pop();qc.pop();
            visited.insert({row,col});
            image[row][col]=color;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i],ncol=col+dcol[i];
                if(
                    0<=nrow && nrow<image.size() &&
                    0<=ncol && ncol<=image[0].size() &&
                    image[nrow][ncol]==oriCol &&
                    visited.find({nrow,ncol})!=visited.end()
                    )
                    {
                        qr.push(nrow);
                        qc.push(ncol);
                    }
                
            }
        }

        return image;
    }


int main()
{
    
    return 0;
}