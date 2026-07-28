class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node pointing to head to handle edge cases where head itself is deleted
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if current node is the start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Connect prev node to the node after the duplicates
                prev->next = head->next;
            } else {
                // No duplicate for head->val, move prev forward
                prev = prev->next;
            }
            // Move head forward to process the next segment
            head = head->next;
        }

        return dummy.next;
    }
};