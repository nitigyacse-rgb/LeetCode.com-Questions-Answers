class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to form two separate lists
        ListNode lessHead(0);
        ListNode greaterHead(0);

        // Tail pointers for the two lists
        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Avoid cycle: terminate the greater list
        greater->next = nullptr;

        // Connect the 'less' list with the 'greater' list
        less->next = greaterHead.next;

        return lessHead.next;
    }
};