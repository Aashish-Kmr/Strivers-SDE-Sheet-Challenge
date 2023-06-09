#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
  // good question to check the knowledge of heap
	vector<int> v1;
	priority_queue<int> max;
  	priority_queue<int, vector<int>, greater<int>> min;
  	for (int i = 0; i < k; i++){
    	max.push(arr[i]);
  		min.push(arr[i]);
	}
	for(int i=k ; i< n ; i++){
		if(arr[i]<max.top()){
			max.push(arr[i]);
			max.pop();
		}
		if(arr[i]>min.top()){
			min.push(arr[i]);
			min.pop();
		}
	}
	v1.push_back(max.top());
	v1.push_back(min.top());
	return v1;



}