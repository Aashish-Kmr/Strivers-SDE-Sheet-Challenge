#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top=0, bottom =n-1 , left= 0, right = m-1;
    while(top<bottom && left <right){
        int prev=mat[top+1][left];
        for(int j=left; j<=right;j++){
            int cur=mat[top][j];
            mat[top][j]=prev;
            prev=cur;
        }
        top++;
        if(top<bottom){
            for(int i=top ;i<=bottom; i++){
                int cur = mat[i][right];
                mat[i][right]=prev;
                prev=cur;
            }
        }
        right--;
        if(right>left){
            for(int j=right; j>=left; j--){
                int cur= mat[bottom][j];
                mat[bottom][j]=prev;
                prev=cur;
            }
        }
        bottom--;
        if(bottom>=top){
            for(int i=bottom; i>=top; i--){
                int cur=mat[i][left];
                mat[i][left]=prev;
                prev=cur;
            }
        }
        left++;
    }
    return ;
}