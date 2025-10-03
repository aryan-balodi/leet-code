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
        if (head == nullptr) return false;
        if (head->next == nullptr) return true;

        vector<int> LL; int count;

        ListNode *temp = head; ListNode *First = head;
        while(temp != nullptr) {
            count++;
            LL.push_back(temp->val);

            temp = temp->next;
        }
        
        int low = 0; int high = LL.size() - 1;

        while (low <= high) {
            if (LL[low] == LL[high]) {
                low++;
                high--;
            }
            else return false;
        }

        return true;

    }
};