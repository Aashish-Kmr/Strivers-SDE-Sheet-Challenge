#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	map<int, int> m1;
	for(int i = 0 ; i<n ; i++){
		m1[arr[i]]++;
		if(m1[arr[i]]>1)
			return arr[i];
	}
}
