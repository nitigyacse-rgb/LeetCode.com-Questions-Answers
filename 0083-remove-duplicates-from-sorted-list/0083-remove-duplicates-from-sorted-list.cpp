class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            // If the current node and next node have the same value, skip the next node
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory of the skipped node
            } else {
                // Otherwise, move to the next distinct node
                current = current->next;
            }
        }

        return head;
    }
};