#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
	int n,m;
	n = matrix.size();
	m = matrix[0].size();
	vector<int> x1;
	vector<int> y1;
	for(int i=0 ; i<n ; i++){
		for(int j =0 ; j < m ; j++){
			if(matrix[i][j]==0){
				x1.push_back(i);
				y1.push_back(j);
			}
		}
	}
	for(auto x: x1){
		for(int j=0; j<m ; j++){
			matrix[x][j]=0;
		}
	}
	for(auto y: y1){
		for(int i = 0 ; i< n ; i++){
			matrix[i][y]=0;
		}
	}
}