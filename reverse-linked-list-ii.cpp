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
        if(!head || left == right)
            return head;

        ListNode aux(0);
        aux.next = head;
        ListNode* pr = &aux;

        for(int i = 0; i < left - 1; i++)
            pr = pr->next;

        ListNode* curr = pr->next;

        for(int i = 0; i < right - left; i++) {
            ListNode* node = curr->next;
            curr->next = node->next;
            node->next = pr->next;
            pr->next = node;
        }

        return aux.next;
    }
};