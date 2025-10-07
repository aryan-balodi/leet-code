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
    // ListNode *Intersection(ListNode *SHead, ListNode *BHead, int diff) {
    //     ListNode *S = SHead; ListNode *B = BHead;

    //     while (diff--) {
    //         B = B->next;
    //     }

    //     while (S != nullptr && B != nullptr && S != B) {
    //         S = S->next;
    //         B = B->next;
    //     }
    //     return S;
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // hashing in set:
        // set<ListNode *> nodes;
        // ListNode *temp = headA;

        // while (temp != nullptr) {
        //     nodes.insert(temp);
        //     temp = temp->next;
        // }

        // temp = headB;

        // while (temp != nullptr) {
        //     if (nodes.find(temp) != nodes.end()) return temp;

        //     temp = temp->next;
        // }
        // return NULL;

        // Calculating length:

        // ListNode *tempA = headA; ListNode *tempB = headB;
        // int countA = 0; int countB = 0;

        // while (tempA != nullptr) {
        //     countA++; 
        //     tempA = tempA->next; 
        // }
        // while (tempB != nullptr) {
        //     countB++; 
        //     tempB = tempB->next;
        // }
    
        // if (countA > countB) {
        //     int diff = countA - countB;
        //     return Intersection(headB, headA, diff);
        // }
        // else {
        //     int diff = countB - countA;
        //     return Intersection(headA, headB, diff);
        // }

        ListNode *tempA = headA; ListNode *tempB = headB;

        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;

            if (tempA == tempB) return tempA;

            if (tempA == nullptr) tempA = headB;
            if (tempB == nullptr) tempB = headA;
        }
        return tempA;
    }
};