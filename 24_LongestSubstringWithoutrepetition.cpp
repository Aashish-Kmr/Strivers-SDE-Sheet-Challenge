#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int max1=-1;
    int s= input.size();
    for(int i=0 ; i<s-1;i++){
        int count=1;
        set<char> s1;
        s1.insert(input[i]);
        for(int j = i+1; j<s ; j++ ){
          if (s1.find(input[j])==s1.end()) {
            s1.insert(input[j]);
            count++;
          }
        else
                break;
        }
        max1= max(max1, count);
        count=1;
    }
    return max1;
}