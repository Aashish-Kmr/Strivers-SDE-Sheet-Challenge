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

bool isPalindrome(LinkedListNode<int> *head) {
    stack<LinkedListNode<int> *> s1;
    LinkedListNode<int> *ptr=head;
    while(ptr){
        s1.push(ptr);
        ptr=ptr->next;
    }

    while(!s1.empty()){
        if (head->data!=s1.top()->data)
            return false;
        head=head->next;
        s1.pop();
    }
    return true;
}