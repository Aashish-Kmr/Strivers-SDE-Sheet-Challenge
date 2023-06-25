#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{   
    vector<int> ans;
    set<int> s1; 
    unordered_map<int, int> m1;
    for(int i=0; i < arr.size(); i++){
        m1[arr[i]]++;
        if(m1[arr[i]] > arr.size()/3)
            s1.insert(arr[i]);
    }
    for(auto x : s1){
        ans.push_back(x);
    }
    return ans;
}