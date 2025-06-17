/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* a1, ListNode* b1){
        ListNode* a = a1;
        ListNode* b = b1;      
        ListNode* dis = new ListNode(0);
        ListNode* temp = dis;
        while(a != NULL && b != NULL){
            if(a->val < b->val){
                temp->next = a;
                temp = a;
                a = a->next;
            }
            else{
                temp->next = b;
                temp = b;
                b = b->next;
            }
            
        }
        if(a!=NULL){
            temp->next = a;
        }
        else temp->next = b;

        return dis->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* firstNode = head;
        ListNode* lastNode = mid->next;
        mid->next = NULL;
        firstNode = sortList( firstNode);
        lastNode = sortList( lastNode );

        return merge(firstNode, lastNode);

    }
};