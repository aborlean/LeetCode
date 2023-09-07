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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *aux = head;
        vector<ListNode*> ans(k);

        int len = 0;
        while(aux) {
            len++;
            aux = aux->next;
        }

        int add = len % k, sz = len / k, n = 0;
        aux = head;

        while(aux) {
            ans[n++] = aux;
            int current = sz - 1;
            if(add-- > 0)
                current++;

            for(int i = 0; i < current; i++)
                aux = aux->next;

            ListNode *p = aux->next;
            aux->next = NULL;
            aux = p;
        }

        return ans;
    }
};