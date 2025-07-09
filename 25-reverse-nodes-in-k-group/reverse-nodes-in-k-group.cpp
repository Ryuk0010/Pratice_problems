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
    ListNode* reverse(ListNode* curr, ListNode* end) {
        ListNode* prev = nullptr;
        while(curr != end){
            ListNode* next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* end = head;
        for (int i = 0; i < k; ++i) {
            if (!end) return head;
            end = end->next;
        }

        ListNode* ans = reverse(head, end);
        head->next = reverseKGroup(end, k);
        return ans;
    }
};