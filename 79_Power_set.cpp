#include <bits/stdc++.h> 
vector<vector<int>> ans;

void pws(vector<int> v, vector<int> v1) {
    if (v.size() == 0) {
        ans.push_back(v1);
        return;
    }

    int element = v[0];
    v.erase(v.begin());

    vector<int> v2 = v1;
    v1.push_back(element);

    pws(v, v1);
    pws(v, v2);
}

vector<vector<int>> pwset(vector<int> v) {
    vector<int> v1;
    pws(v, v1);
    vector<vector<int>> ans1 = ans;
    ans.clear();
    return ans1;
}
