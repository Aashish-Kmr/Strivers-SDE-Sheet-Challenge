double median(vector<int>& a, vector<int>& b) {
	// just learnt this topic : ) 
	int na = a.size();
	int nb =  b.size();
    if (na > nb) 
    	return median(b, a);
	int low =0 , high = na;
	while(low<=high){
		int mid1= (low+high) >> 1;
		int mid2= (na+nb+1)/2 - mid1;

 		int l1 = mid1==0 ? INT_MIN : a[mid1-1];
		int l2 = mid2==0 ? INT_MIN : b[mid2-1];
		
		int r1 = mid1==na ? INT_MAX : a[mid1];
		int r2 = mid2==na ? INT_MAX : b[mid2];

		if(l1<=r2 && l2<=r1){
			if((na+nb)%2==0){
				return (max(l1,l2) + min(r1,r2))/2.0;
			}
			if((na+nb)%2!=0){
				return max(l1,l2)/1.0;
			}
		}
		else if(l1>r2){
			high = mid1-1;
		}
		else{
			low = mid1+1;
		}
	}
	return 0.0;
    
		
}