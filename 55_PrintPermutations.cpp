#include <bits/stdc++.h>
void solve(int i, string &s , vector<string> &ans, int freq[], int n, string str ) {
    if(i==n){
        ans.push_back(str);
        return;
    }

    for(int k=0 ; k< n ; k++){
        if(freq[k]!=1){
            str+=s[k];
            freq[k]++;
            solve(i+1, s ,ans, freq, n , str);
            str.pop_back();
            freq[k]--;
        }
    }
    return; 
}
vector<string> findPermutations(string &s) {
    vector<string> ans; 
    int n= s.size();
    if(n==0)
        return ans;
    int freq[n]={0};
    string str="";
    solve(0, s, ans, freq, n, str);

    return ans;
}