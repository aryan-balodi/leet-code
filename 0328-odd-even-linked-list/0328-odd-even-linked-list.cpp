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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return NULL;

        if (head->next == nullptr) return head;
        
        ListNode *temp = head; 
        ListNode *EvenHead = head->next; 
        ListNode *EvenMover = head->next;

        while (EvenMover != nullptr && EvenMover->next != nullptr) {
            temp->next = EvenMover->next;
            temp = temp->next;

            EvenMover->next = temp->next;
            EvenMover = temp->next;
        }

        temp->next = EvenHead;
        
        return head;
    }
};