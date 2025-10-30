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
    ListNode *Merge2LL(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *res = dummy;

        ListNode *t1 = head1; ListNode *t2 = head2;

        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val < t2->val) {
                res->next = t1;
                res = t1;
                t1 = t1->next;
            } else {
                res->next = t2;
                res = t2;
                t2 = t2->next;
            }
        }

        if (t1) res->next = t1;
        else res->next = t2;

        return dummy->next;
    }

    ListNode *FindMiddle(ListNode *head) {
        ListNode *slow = head; ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *middle = FindMiddle(head);

        ListNode *left = head; ListNode *right = middle->next;

        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return Merge2LL(left, right);

    }
};