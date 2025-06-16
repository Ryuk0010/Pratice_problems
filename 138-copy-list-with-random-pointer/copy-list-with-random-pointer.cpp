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
        map<Node*, Node*> mpp;
        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        while(curr) {
            Node* temp = new Node(curr->val);
            mpp[curr] = temp;
            if(newHead == NULL) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;
        while(curr) {
                newCurr->random = mpp[curr->random];    

            
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};