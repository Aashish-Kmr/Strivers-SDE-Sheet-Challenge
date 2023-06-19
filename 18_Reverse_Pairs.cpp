#include <bits/stdc++.h> 

int mergecnt(vector<int> &arr, int low, int mid, int high){
    int cnt=0; 
    int right= mid+1;
    for(int i=low; i<=mid; i++){
        while(right<=high && arr[i]>2*arr[right]){
            right++; 
        }
        cnt+=right-(mid+1);
    }
    return cnt;
}
void merge(vector<int> &arr, int low, int mid ,int high){
    vector<int> ans;
    int i=low, j = mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j])
            ans.push_back(arr[i++]);
        else 
            ans.push_back(arr[j++]);
    }
    while (i <= mid) {
      ans.push_back(arr[i++]);
    }
    while (j <= high) {
      ans.push_back(arr[j++]);
    }

    for(int i=low; i<=high; i++){
        arr[i]=ans[i-low];
    }
}

int mergesort(vector<int> &arr, int left,int right){
    if(left>=right)
        return 0;
    int count=0;
    int mid=(left+right)/2;  
    count+=mergesort(arr,left,mid);
    count+=mergesort(arr,mid+1, right);
    count+=mergecnt(arr, left, mid, right);
    merge(arr, left , mid, right);

    return count;
}


int reversePairs(vector<int> &arr, int n){
	return mergesort(arr,0, n-1);
}