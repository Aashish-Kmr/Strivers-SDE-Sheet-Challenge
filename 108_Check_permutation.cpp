#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    if(str1.size()!=str2.size())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    for(int i=0 ; i< str1.size(); i++){
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}