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
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    unordered_map<Node *, int> m1; 
    while(head){
        m1[head]++;
        if(m1[head]>1)
            {
                return head;
            }
        head=head->next;
    }
    return head;
}