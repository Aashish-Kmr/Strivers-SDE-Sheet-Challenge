#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;
    int size;
    public:
    Queue() {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
        size++;
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(s1.empty())
            return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        size--;
        return ans;

    }

    int peek() {
        // Implement the peek() function here.
        if(s1.empty())
            return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(size==0)
            return true;
        else return false;
    }
};