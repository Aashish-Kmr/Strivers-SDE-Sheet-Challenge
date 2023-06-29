int NthRoot(int n, int m) {
  int lo = 2, hi = m -1;

  while(lo<=hi){
    int mid = (lo+hi)/2;

    if(pow(mid, n)==m)
      return mid;
    else if(pow(mid,n)>m)
      hi = mid-1;

    else  
      lo = mid+1;
  }
  return -1;
}