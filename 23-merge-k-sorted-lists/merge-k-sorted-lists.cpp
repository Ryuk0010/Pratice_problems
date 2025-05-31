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
    ListNode* merge(ListNode* n1, ListNode* n2){
        if(!n1) return n2;
        if(!n2) return n1;

        if(n1->val < n2->val){
            n1->next = merge(n1->next, n2);
            return n1;
        }
        else{
            n2->next = merge(n1, n2->next);
            return n2;
        }

    }
    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high){
        if(low >= high) return lists[low];

        int mid = (low+high)/2;
        ListNode* node1 = mergeSort(lists, low, mid);
        ListNode* node2 = mergeSort(lists, mid+1, high);
        return merge(node1, node2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return mergeSort(lists, 0, lists.size()-1);
    }
};