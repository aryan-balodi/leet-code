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
    int ReturnLen(ListNode* head) {
        ListNode *temp = head;
        int count = 0;

        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *DelByk(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return NULL;

        if (k == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode *temp = head; 
        ListNode *prev = NULL; 
        int count = -1;

        while (temp != NULL) {
            count++;
            if (count == k) {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;

    }

    ListNode* deleteMiddle(ListNode* head) {
        int len = ReturnLen(head);
        int k = len / 2;

        head = DelByk(head, k);

        return head;
    }
};