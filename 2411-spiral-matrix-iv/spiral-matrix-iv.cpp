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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* temp = head;

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (temp != nullptr) {
            for (int j = left; j <= right && temp != nullptr; j++) {
                ans[top][j] = temp->val;
                temp = temp->next;
            }
            top++;

            for (int i = top; i <= bottom && temp != nullptr; i++) {
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            for (int j = right; j >= left && temp != nullptr; j--) {
                ans[bottom][j] = temp->val;
                temp = temp->next;
            }
            bottom--;

            for (int i = bottom; i >= top && temp != nullptr; i--) {
                ans[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }

        return ans;
    }
};
