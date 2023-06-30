#include<bits/stdc++.h>

bool isSafe(int node,vector<vector<int>> &mat , int color[], int n , int i){
    for(int k = 0  ; k < n ; k++){
        if(k!=node && mat[k][node]==1 && color[k]==i)
            return false;
    }
    return true;
}


bool solve(int node,vector<vector<int>> &mat , int n, int color[], int m){
    if(node == n)
        return true;
    
    for(int i = 1 ; i <=m ; i++){
        if(isSafe(node, mat, color, n, i)){
            color[node]=i;
            if(solve(node+1, mat, n , color, m)) return true;
            color[node]=0; 
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n= mat.size();
    int colors[n] = {0};
    if(solve(0 , mat, n, colors, m))    return "YES";
    else return "NO";
}