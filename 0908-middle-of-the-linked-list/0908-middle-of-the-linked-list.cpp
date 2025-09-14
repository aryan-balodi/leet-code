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
    int lengthOfLL(ListNode *head) {
        int count = 0; ListNode *temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int count = lengthOfLL(head);
        if (count % 2 == 0) {
            count = (count / 2) + 1;
            
            ListNode *temp = head;
            int k = 0;

            while (temp) {
                k++;
                if (k == count) head = temp;
                temp = temp->next;
            }
        }
        else {
            count = (count / 2) + 1;
            
            ListNode *temp = head;
            int k = 0;

            while (temp) {
                k++;
                if (k == count) head = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};