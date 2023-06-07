#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(n==0)
        return 0;
    sort(arr.begin(), arr.end());
    int count=1, max1=1;
    for(int i=0; i < n-1; i++){
      if (arr[i + 1] - arr[i] == 1) {
        count++;
        max1 = max(max1, count);
      }
      if(arr[i+1] - arr[i]>1){
          count=1;
      }
    }
    return max1;
}