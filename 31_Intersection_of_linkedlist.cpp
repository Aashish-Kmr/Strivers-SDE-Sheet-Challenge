/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
   unordered_map<Node*, int> m1;
   while(firstHead){
       m1[firstHead]++;
       firstHead=firstHead->next;
   }
   while(secondHead){
        m1[secondHead]++;
        if(m1[secondHead]>1)
            return secondHead;
        secondHead=secondHead->next;
   }
   return nullptr; 
}

/*
Another approach using two stacks
#include <bits/stdc++.h>
Node* findIntersection(Node *h1, Node *h2)
{
   stack <Node*> s1;
   stack <Node*>s2;
   while(h1){
       s1.push(h1);
       h1= h1->next;
   }
   while(h2){
       s2.push(h2);
       h2=h2->next;
   }
   while(s1.top()==s2.top()){
       s1.pop();
       s2.pop();
   }
   return s1.top()->next;
}
*/

/*
3rd approach 
Node* findIntersection(Node *h1, Node *h2)
{
   Node *head1= h1;
    Node *head2= h2;

    while(head1!=head2){
        if(head1==NULL){
            head1=h2;
        }
        else{
            head1=head1->next;
        }
        if(head2==NULL){head2=h1;
        }
        else{
            head2=head2->next;
        }
    }
    return head1;
}
*/