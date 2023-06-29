#include <bits/stdc++.h> 

void solve(int x, int y, vector<vector<int>>& arr, int n, vector<vector<int>>& ans, vector<vector<bool>>& vis, vector<int>& temp) {
  if (x == n - 1 && y == n - 1) {
    ans.push_back(temp);
    return;
  }
  vis[x][y] = true;
  int vex[] = {1, 0, 0, -1};
  int vey[] = {0, -1, 1, 0};
  for (int i = 0; i < 4; i++) {
    int X_n = x + vex[i];
    int Y_n = y + vey[i];
    if ((X_n >= 0 && X_n < n) && (Y_n >= 0 && Y_n < n) && vis[X_n][Y_n] == false && arr[X_n][Y_n] == 1) {
      temp[n * X_n + Y_n] = 1;
      solve(X_n, Y_n, arr, n, ans, vis, temp);
      temp[n * X_n + Y_n] = 0;
    }
  }
  vis[x][y] = false;
}

vector<vector<int>> ratInAMaze(vector<vector<int>>& arr, int n) {
  vector<vector<int>> ans;
  vector<vector<bool>> vis(n, vector<bool>(n, false));

  if (arr[0][0] == 0)
    return ans;

  vector<int> temp(n * n, 0);
  temp[0]=1;
  solve(0, 0, arr, n, ans, vis, temp);

  return ans;
}
