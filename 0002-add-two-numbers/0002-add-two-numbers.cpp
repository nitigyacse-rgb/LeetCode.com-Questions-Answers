/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to anchor our new list
        ListNode* curr = &dummy;
        int carry = 0;
        
        // Loop runs if elements remain in l1, l2, or if a carry needs its own final node
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move to the next node in l1
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move to the next node in l2
            }
            
            carry = sum / 10; // Calculate new carry (e.g., 14 / 10 = 1)
            
            // Create a new node with the digit value (e.g., 14 % 10 = 4)
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        
        return dummy.next; // The actual head of the result list starts after the dummy
    }
};