#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans; 
    for(int i = 0 ; i < n-2 ; i++){
        if(i==0 || (i>0 && arr[i]!=arr[i-1])){
            int low = i+1, high = n - 1; 
            int tgt=K - arr[i];

            while(low < high){
              if (arr[low] + arr[high] == tgt) {
                vector<int> t;
                t.push_back(arr[i]);
                t.push_back(arr[low]);
                t.push_back(arr[high]);
                ans.push_back(t);

                while(low < high  && arr[low]==arr[low+1]) low++;
                while(low < high && arr[high]==arr[high-1]) high--; 

                low++; high--;
              }
              else if(arr[low]+arr[high]>tgt){
                  high--;
              }
              else  low++;
            }   
        }
    }
    return ans;
}
