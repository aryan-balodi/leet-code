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
    ListNode *GetKthNode(ListNode *temp, int k) {
        k -= 1;

        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *RevLL(ListNode *temp) {
        ListNode *cur = temp; ListNode *prev = nullptr;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head; ListNode *PrevLast = nullptr;

        while (temp != nullptr) {
            ListNode *KthNode = GetKthNode(temp,k);
            if (KthNode == nullptr) {
                PrevLast->next = temp;
                break;
            }

            ListNode *NextNode = KthNode->next;
            KthNode->next = nullptr;

            RevLL(temp);

            if (head == temp) {
                head = KthNode;
            }
            else {
                PrevLast->next = KthNode;
            }

            PrevLast = temp;
            temp = NextNode;

        }
        return head;
    }
};