#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    map<long long, pair<int, int>> m1; 
    for(int i= 0 ; i < n-1; i++){
        for(int j =i+1 ; j < n; j++){
            int sum = arr[i] + arr[j];
            int val=target-sum;
            if(m1.find(val)!=m1.end()){
                if(m1[val].first != i && m1[val].first != j && m1[val].second != i && m1[val].second != j ){
                    return "Yes";
                }
            }
            m1[sum]={i,j};
        }
    }
    return "No";
}
