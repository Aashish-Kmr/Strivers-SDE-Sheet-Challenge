#include<bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> p1;
    for(int i=0 ; i < start.size(); i++ ){
        p1.push_back(make_pair(finish[i], start[i]));
    }
    sort(p1.begin(), p1.end());
    if(p1.size()==1)
        return 1;
    else{
        int cnt=1;
        int d=p1[0].first;
        for(int i = 1; i < p1.size() ; i++){
            if(p1[i].second>=d){
                d=p1[i].first;
                cnt++;
            }
        }
        return cnt;
    }
}