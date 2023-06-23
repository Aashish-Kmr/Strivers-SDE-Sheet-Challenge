#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	int t[n+1][w+1];
	memset(t, -1 , sizeof(t));

	for(int i = 0 ;  i<=n; i++)
		for(int j = 0 ; j <=w; j++){
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=0;
		}

	for(int i=1 ; i<= n ; i++){
		for(int j = 1 ; j<= w; j++){
			if(weights[i-1]<=j){
				t[i][j]=max(t[i-1][j] , values[i-1] + t[i-1][j - weights[i-1]]);
			}
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][w];

}