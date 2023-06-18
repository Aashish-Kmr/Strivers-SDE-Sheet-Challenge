#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 1) {
        return intervals;
    }
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> ans;
    
    for (int i = 0; i < n; i++) {
        if(ans.empty()){
            ans.push_back(intervals[i]);
        }
        else{
            vector<int> &v = ans.back();
            if(intervals[i][0]<=v[1])
                v[1] = max(v[1], intervals[i][1]);
            else  
                ans.push_back(intervals[i]);
        }
    }
        
    return ans;
}
