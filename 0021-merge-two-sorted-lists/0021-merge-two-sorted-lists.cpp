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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode head;
        ListNode *tail = &head;

        ListNode *mover1 = list1;
        ListNode *mover2 = list2;

        while (mover1 && mover2) {
            if (mover1->val == mover2->val) {
                tail->next = mover1;
                mover1 = mover1->next;
                tail = tail->next;

                tail->next = mover2;
                mover2 = mover2->next;
                tail = tail->next;
                
            }
            else if (mover1->val < mover2->val) {
                tail->next = mover1;
                mover1 = mover1->next;
                tail = tail->next;
            }
            else {
                tail->next = mover2;
                mover2 = mover2->next;
                tail = tail->next;
            }

            if (mover1) tail->next = mover1;
            if (mover2) tail->next = mover2; 
        }

        return head.next;
    }
};