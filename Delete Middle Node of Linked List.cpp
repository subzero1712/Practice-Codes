class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        
        int cnt = 0;
        ListNode* temp = head;
        
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        temp = head;
        for (int i = 0; i < cnt / 2 - 1; i++) {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};
