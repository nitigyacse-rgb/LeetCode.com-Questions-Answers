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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        // Step 1: Move `prev` to the node right before position `left`
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // `curr` will be the first node of the sublist to be reversed
        ListNode* curr = prev->next;
        
        // Step 2: Reverse the sublist from `left` to `right`
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        
        ListNode* result = dummy->next;
        delete dummy; // Clean up allocated memory
        return result;
    }
};