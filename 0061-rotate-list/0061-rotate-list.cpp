class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Base cases: empty list, single node, or no rotations needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Find the length of the list and locate the tail node
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Reduce k using modulo to avoid unnecessary full rotations
        k = k % length;
        if (k == 0) {
            return head; // Rotations equal to multiple of length leave list unchanged
        }

        // 3. Form a circular linked list
        tail->next = head;

        // 4. Find the new tail: (length - k - 1) steps from head
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // 5. Break the circle and get the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};