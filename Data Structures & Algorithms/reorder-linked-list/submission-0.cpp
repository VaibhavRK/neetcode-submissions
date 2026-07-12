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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        int mid = n/2;

        temp = head;

        while(mid--){
            temp = temp->next;
        }

        ListNode* curr = temp->next;
        ListNode* prev = temp;
        ListNode* nextptr;

        while(curr != NULL){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        temp = head;
        int flg = 1;
        while(temp != prev){
            if(flg){
                nextptr = temp->next;
                temp->next = prev;
                temp = nextptr;
                flg = 0;
            }
            else{
                nextptr = prev->next;
                prev->next = temp;
                prev = nextptr;
                flg = 1;
            }
        }

        temp->next = NULL;
    }
};
