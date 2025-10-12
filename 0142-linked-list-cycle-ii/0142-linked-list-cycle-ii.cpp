/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Hashing - approach
        
        // if (head == nullptr) return NULL;

        // if (head->next == nullptr) return NULL;
        
        // unordered_map<ListNode *, int> mpp;

        // ListNode *temp = head;

        // while (temp != nullptr) {
        //     if (mpp.find(temp) != mpp.end()) {
        //         return temp;
        //     }

        //     mpp[temp] = 1;
            
        //     temp = temp->next;
        // }
        // return NULL;

        // slow and fast pointers

        ListNode *slow = head; ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};