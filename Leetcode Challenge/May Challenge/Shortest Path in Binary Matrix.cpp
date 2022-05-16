/*
1091. Shortest Path in Binary Matrix
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/
class Solution {
public:
    bool isSafe(int i,int j,int n){
        if(i<0||j<0||i>=n||j>=n) return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int i,n=mat.size(),x,y,t,val=mat[0][0];
        if(val==1) return -1;
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        queue<vector<int>> q;
        q.push({0,0,0});
        while(q.size()){
            vector<int> v=q.front(); q.pop();
            t=v[0]; x=v[1]; y=v[2];
            if(x==n-1 && y==n-1) return t+1;
            if(isSafe(x+1,y,n) && mat[x+1][y]==0 && vis[x+1][y]!=1){
                q.push({t+1,x+1,y}); vis[x+1][y]=1;
            }
            if(isSafe(x-1,y,n) && mat[x-1][y]==0 && vis[x-1][y]!=1){
                q.push({t+1,x-1,y}); vis[x-1][y]=1;
            }
            if(isSafe(x+1,y+1,n) && mat[x+1][y+1]==0 && vis[x+1][y+1]!=1){
                q.push({t+1,x+1,y+1}); vis[x+1][y+1]=1;
            }
            if(isSafe(x,y+1,n) && mat[x][y+1]==0 && vis[x][y+1]!=1){
                q.push({t+1,x,y+1}); vis[x][y+1]=1;
            }
            if(isSafe(x-1,y+1,n) && mat[x-1][y+1]==0 && vis[x-1][y+1]!=1){
                q.push({t+1,x-1,y+1}); vis[x-1][y+1]=1;
            }
            if(isSafe(x,y-1,n) && mat[x][y-1]==0 && vis[x][y-1]!=1){
                q.push({t+1,x,y-1}); vis[x][y-1]=1;
            }
            if(isSafe(x+1,y-1,n) && mat[x+1][y-1]==0 && vis[x+1][y-1]!=1){
                q.push({t+1,x+1,y-1}); vis[x+1][y-1]=1;
            }
            if(isSafe(x-1,y-1,n) && mat[x-1][y-1]==0 && vis[x-1][y-1]!=1){
                q.push({t+1,x-1,y-1}); vis[x-1][y-1]=1;
            }
        }
        return -1;
    }
};