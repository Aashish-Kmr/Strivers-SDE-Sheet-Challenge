#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	unordered_map<int, int> m1; 
	int max_=-1;
	int max_el=INT_MAX;
	for(int i=0; i<n; i++){
		m1[arr[i]]++;
		if(m1[arr[i]]>max_){
			max_= m1[arr[i]];
			max_el=arr[i];
		}
	}
	if(max_ > n/2)
		return max_el;
	else
		return -1;
	
}