/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution {
  public:
    Node* pairWiseSwap(Node* head) {
        if (!head || !head->next) return head;
        Node* newHead = head->next;
        
        head->next = pairWiseSwap(newHead->next);
        newHead->next = head;
        return newHead;
    }
};
