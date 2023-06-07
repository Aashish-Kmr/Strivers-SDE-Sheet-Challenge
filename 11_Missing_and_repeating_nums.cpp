#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int rept=0, mis=0;
	map<int, int> m1;
	for(int i=0; i < n ; i++){
		m1[arr[i]]++;
	}
	for(int i=1 ; i<n+1;i++){
		if(m1[i]>1)
			rept=i;
		if(m1[i]==0)
			mis=i;
	}
	return make_pair(mis, rept);

	
}
