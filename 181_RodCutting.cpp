#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
	int s = price.size(); 
	int t[s+1][n+1];
	memset(t, 0, sizeof(t));
	for(int i= 1; i < s+1 ;i++){
		for(int j = 0 ; j < n+1 ; j++){
			if(i<= j ){
				t[i][j] = max(t[i-1][j] , price[i-1]+ t[i][j-i]);
			}
			else
				t[i][j]= t[i-1][j];
		}
	}
	return t[s][n];
}
