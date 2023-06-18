#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* head= new Node<int>(2);
    Node<int>* cur = head;
    while(first && second){
        if(first->data < second->data){
            head->next = first;
            head= head->next;
            first = first->next;
        }
        else{
            head->next = second;
            head= head->next;
            second = second->next; 
        }
    }
    while(first){
        head->next = first;
        head=head->next;
        first= first->next;
    }
    while(second){
        head->next= second;
        head= head->next;
        second= second->next ;
    }
    cur= cur-> next; 
    return cur;
}
