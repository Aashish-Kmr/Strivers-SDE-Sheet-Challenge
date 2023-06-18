#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> ans;
	int l1=0, l2=0; 
	while(l1<m && l2<n){
		if(arr1[l1]<arr2[l2]){
			ans.push_back(arr1[l1++]);
		}
		else{
			ans.push_back(arr2[l2++]);
		}
	}
	while(l1<m){
		ans.push_back(arr1[l1++]);
	}
	while(l2<n){
		ans.push_back(arr2[l2++]);
	}
	return ans;
}