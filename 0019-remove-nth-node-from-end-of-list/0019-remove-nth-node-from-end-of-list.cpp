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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;

        if (head->next == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(0,head);
        ListNode *Fast = &dummy; 
        ListNode *Slow = &dummy; 
        

        for (int i = 0; i <= n; i++) {
            if (Fast) Fast = Fast->next;
        }

        while (Fast != nullptr) {
            Fast = Fast->next;
            Slow = Slow->next;
        }

        ListNode *DelNode = Slow->next;
        Slow->next = DelNode->next;
        delete DelNode;
        
        return dummy.next;
    }
};