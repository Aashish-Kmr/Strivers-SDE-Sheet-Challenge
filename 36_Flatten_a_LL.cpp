/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *mergeL(Node *h1, Node *h2){   
    Node *ans = new Node();
    Node *h = ans;
    while(h1 && h2){
        if(h1->data < h2->data){
            ans->child= h1;
            ans =ans->child;
            h1= h1->child;
        } else {
          ans->child = h2;
          ans = ans->child;
          h2 = h2->child;
        }
    }
    if(h1){
        ans->child = h1;
    }
    else    ans->child=h2; 

    return h->child;
}


Node* flattenLinkedList(Node* head) 
{
	if(!head->next)
        return head;

    Node *ch=head;
    Node *right=head->next;
    
    right=flattenLinkedList(right);
    ch->next=nullptr;
    ch = mergeL(ch, right);
    return ch;
}
// the Above solution takes O(n*n*m) 

// make another approach using priority queue;

/*
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<bits/stdc++.h>

struct mycomp {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
// bool mycomp(Node *a, Node *b){
//     return a->data < b->data;
// }

/*
Node* flattenLinkedList(Node* head) 
{
    priority_queue<Node*, vector<Node*>, mycomp> p1;
    Node *hh= head;
    while (head) {
        Node *temp= head->next;
        head->next=nullptr;
        p1.push(head);
        head= temp;
    }
    
    Node *ans= new Node();
    head=ans;
    while(!p1.empty()){
        Node *temp=p1.top();
        p1.pop();
        if(temp->child)
            p1.push(temp->child);
        ans->child=temp;
        ans=ans->child;
    }
    
    return head->child;
}

*/