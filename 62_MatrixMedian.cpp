vector<int> merge1(vector<int>ans, vector<int> vec){

    // Just another brute force approach
    
    int l1=0 , l2=0, h1=ans.size() , h2=vec.size();
    vector<int> ans1;
    while(l1< h1 && l2 < h2){
        if(ans[l1]<vec[l2])
            ans1.push_back(ans[l1++]);
        else  
            ans1.push_back(vec[l2++]);
    }
    while(l1< h1)
        ans1.push_back(ans[l1++]);
    while(l2<h2)
        ans1.push_back(vec[l2++]);
    
    return ans1;
}


int getMedian(vector<vector<int>> &matrix)
{
    vector<int> ans;
    // we need to add all elements to the ans_array ->kind of merge sort lagega isme 
    ans=matrix[0];
    for(int i=1 ; i < matrix.size(); i++){
        ans=merge1(ans, matrix[i]);
    }

    int s=ans.size()/2;

    return ans[s];
}   