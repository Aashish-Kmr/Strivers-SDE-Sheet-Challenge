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

Node* mergeTwo(Node* head1, Node* head2) {
    Node* ans = nullptr;
    Node* head = nullptr;
    Node* prev = nullptr;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (!ans) {
                ans = head1;
                head = ans;
            } else {
                prev->child = head1;
            }
            prev = head1;
            head1 = head1->child;
        } else {
            if (!ans) {
                ans = head2;
                head = ans;
            } else {
                prev->child = head2;
            }
            prev = head2;
            head2 = head2->child;
        }
    }

    if (head1) {
        if (!ans) {
            ans = head1;
            head = ans;
        } else {
            prev->child = head1;
        }
    }

    if (head2) {
        if (!ans) {
            ans = head2;
            head = ans;
        } else {
            prev->child = head2;
        }
    }

    return head;
}


Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next)
		return head;

	// ek baar mai 2-2 merge krte chalo and ho jayega 
	Node *ans= head;
	while(head->next){
		ans=mergeTwo(ans, head->next);
		head = head->next;
	}
	ans->next=nullptr;
	return ans;	
}
