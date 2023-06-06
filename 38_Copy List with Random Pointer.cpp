/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m1;
        if(!head)
            return NULL;
        Node* nn=new Node(head->val);
        m1[head] = nn;
        Node* curr = head;
        while (curr) {
            if (curr->next) {
                if (!m1[curr->next])
                    m1[curr->next] = new Node(curr->next->val);
                m1[curr]->next = m1[curr->next];
            }

            if (curr->random) {
                if (!m1[curr->random])
                    m1[curr->random] = new Node(curr->random->val);
                m1[curr]->random = m1[curr->random];
            }

            curr = curr->next;
        }

        return nn;
        }
};