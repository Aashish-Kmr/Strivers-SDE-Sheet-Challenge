#include <bits/stdc++.h> 

bool custom_cmp(vector<int> &a, vector<int> &b){
    return (a[1]>b[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    if(jobs.size()==0)
        return 0;
    if(jobs.size()==1)
        return jobs[0][1];
    sort(jobs.begin(), jobs.end(), custom_cmp);
    int maxded=INT_MIN;
    for(int i=0 ; i < jobs.size(); i++){
        maxded = max(jobs[i][0], maxded);
    }

    int arr[maxded];
    memset(arr,-1, sizeof(arr));
    int profmax = 0;

    for (int i = 0; i < jobs.size(); i++) {
        int index=jobs[i][0]-1;
        for(int j=index; j>=0 ; j--){
            if(arr[j]==-1){
                arr[j]=1; 
                profmax+=jobs[i][1];
                break;
            }
        }
    }

    return profmax;
}
