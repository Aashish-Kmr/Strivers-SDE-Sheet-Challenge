#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
	int count=0;
	if(n==1)
		return 1; 
	count=1;
        for (int i = 1; i < n;) {
        	if (arr[i] != arr[i - 1]) {
            count++;
			i++;
          	}
        	if(arr[i]==arr[i-1]){
				while(arr[i]==arr[i-1])
						i++;
				}
        }
		return count;
}