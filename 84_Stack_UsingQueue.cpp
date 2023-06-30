#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q1;
    queue<int>q2;
   public:
    Stack() {
        q1.push(-1);
        q2.push(-1);
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size()-1;
    }

    bool isEmpty() {
        if(q1.size()==1)    
            return true;
        else return false;
    }

    void push(int element) {
        q1.push(element);
    }

    int pop() {
        int prev= q1.front();
        q1.pop();
        while(!q1.empty()){
            prev=q1.front();
            q1.pop();
            if(!q1.empty())
            q2.push(prev);
        }
        q1.push(-1);        
        q2.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(-1);
        return prev;
    }

    int top() {
        // Implement the top() function.
        int prev= q1.front();
        q1.pop();
        while(!q1.empty()){
            prev=q1.front();
            q1.pop();
            q2.push(prev);
        }
        q1.push(-1);        
        q2.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(-1);
        return prev;
    }
};