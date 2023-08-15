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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(0);
        ListNode* smaller_aux = smaller;
        ListNode* greater = new ListNode(0);
        ListNode* greater_aux = greater;
        ListNode* head_aux = head;

        while(head_aux) {
            if(head_aux->val < x) {
                smaller_aux->next = head_aux;
                smaller_aux = smaller_aux->next;
            }
            else {
                greater_aux->next = head_aux;
                greater_aux = greater_aux->next;
            }
            head_aux = head_aux->next;
        }

        greater_aux->next = NULL;
        smaller_aux->next = greater->next;

        return smaller->next;
    }
};