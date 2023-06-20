#include <bits/stdc++.h>
int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int maxv(int amount){
    int dif=INT_MAX;
    for(int i=0 ; i< 9; i++){
        if(amount<arr[i])
            break;
        else{
            dif= min(dif,amount-arr[i]);
        }
    }
    return dif;
}

int findMinimumCoins(int amount) 
{
    // Write your code here
    if(amount==0)
        return 0;
    else
        return 1+findMinimumCoins(maxv(amount));
}
