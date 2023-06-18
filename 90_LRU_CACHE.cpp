#include <bits/stdc++.h>
class LRUCache
{
public:
    
    class Node{
        public:
        int key,val;
        Node* prev, *next;
        Node(int _k, int _v){
            key=_k;
            val=_v;
        }
    };
    int cap;
    Node *head= new Node(-1,-1);
    Node *tail= new Node(-1,-1);
    unordered_map <int, Node*> m;
    LRUCache(int capacity)
    {
        cap= capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnew(int key , int val){
        Node *n= new Node(key,val);
        n->next=head->next;
        n->prev=head;
        head->next->prev=n;
        head->next=n;
    }
    void deletept(Node *n){
        n->prev->next= n->next;
        n->next->prev = n->prev;
        n=nullptr;
    }
    int get(int key)
    {
        // Write your code here
        // check if it exists,return the val in that particular key and update the lru;
        if(m.find(key)!=m.end()){
            int val = m[key]->val;
            deletept(m[key]);
            m.erase(key);
            addnew(key, val);
            m[key]=head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {   //check for existance -> if exits-> delete and make new ptrs
        //if not
        // check for capacity 
        // if more than capacity -> delete lru and place this
        // if less than capacity -> just add in the lru
        if(m.find(key)!=m.end()){
            deletept(m[key]);
            m.erase(key);
        }
        if (m.size() == cap) {
          m.erase(tail->prev->key);
          deletept(tail->prev);
        }
        addnew(key, value);
        m[key] = head->next;
        
    }
};
    