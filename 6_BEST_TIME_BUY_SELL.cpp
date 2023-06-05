class Solution {
public:
    
    int maxProfit(vector<int>& arr) {
        int n= arr.size();
        int max1=0;
        int min1=INT_MAX; 

        for(int i=0 ; i < n; i++){
            min1=min(arr[i], min1);
            max1=max(max1, arr[i]-min1);
        }
        return max1;
    }
};