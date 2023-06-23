long countWaysToMakeChange(int *denominations, int n, int value)
{
long long t[n+1][value+1];
    for(int i=0; i <=n ; i ++){
        for(int j=0 ; j <=value; j++){
            if(i==0) t[i][j]= 0;
            if(j==0)
                t[i][j] =1;
        }
    }
    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j <= value; j++){
            if(j>=denominations[i-1])
                t[i][j] = t[i-1][j] + t[i][j-denominations[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][value];
}