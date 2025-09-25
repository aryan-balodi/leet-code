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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *mover = &dummy;

        while (mover->next != nullptr && mover->next->next != nullptr) {
            ListNode *backward = mover->next;
            ListNode *forward = mover->next->next;

            backward->next = forward->next;
            forward->next = backward;
            mover->next = forward;

            mover = backward;
        }

        return dummy.next;
  
    }
};