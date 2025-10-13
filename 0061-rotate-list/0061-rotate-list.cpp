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
    ListNode *FindNthNode(ListNode *head, int k) {
        int count = 1;

        ListNode *temp = head;
        while (temp != nullptr) {
            if (count == k) return temp;

            count++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        ListNode *tail = head; 
        int length = 1;

        while (tail->next != nullptr) {
            length++;
            tail = tail->next;
        }

        if (k % length == 0) return head;

        k = k % length;

        tail->next = head;

        ListNode *newLastNode = FindNthNode(head,length - k);

        head = newLastNode->next;

        newLastNode->next = nullptr;
        
        return head;

    }
};