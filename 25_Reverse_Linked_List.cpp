#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{ 
    LinkedListNode<int> *new1 = nullptr;
    LinkedListNode<int> *cur = head;
    
    while (cur != nullptr) {
        head = head->next;
        cur->next = new1;
        new1 = cur;
        cur = head;
    }
    
    return new1;
}