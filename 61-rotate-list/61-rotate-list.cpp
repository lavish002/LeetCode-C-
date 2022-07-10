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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
        int n=1;
        ListNode* end = head;
        
        while(end->next!=NULL){
            end=end->next;
            n++;
        }
        k=k%n;
        if(k==n) return head;
        ListNode* temp = head;
        for(int i=1;i<n-k;i++) {
            temp=temp->next;
        }
        end->next = head;
        head = temp->next;
        temp->next=NULL;
        
        return head;
    }
};