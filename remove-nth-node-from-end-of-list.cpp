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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* aux = head;

        while(aux) {
            count++;
            aux = aux->next;
        }

        if(n > count)
            return NULL;
        if(count - n == 0) {
            head = head->next;
            return head;
        }

        int target = count - n - 1;
        aux = head;

        while(target) {
            target--;
            aux = aux->next;
        }

        aux->next = aux->next->next;

        return head;
    }
};