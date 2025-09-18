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
    bool isPalindrome(ListNode* head) {
        vector<int> copy;
        ListNode *temp = head;
        int count = 0;

        while (temp != nullptr) {
            copy.push_back(temp->val);

            temp = temp->next;
            count++;
        }

        int i = 0; int j = copy.size() - 1;
        while(i <= j) {
            if (copy[i] != copy[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};