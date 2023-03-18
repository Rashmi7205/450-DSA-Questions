class Solution {
public:
    int length(ListNode* head)
    {
        int c=0;
        while(head !=NULL)
        {
            c++;
            head = head->next;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next == NULL || k== 0)
            return head;
        int l= length(head);
        if(k%l ==0)
            return head;
        ListNode *temp = head;
        ListNode *lastNode = temp;
        while(temp!=NULL)
        {
            lastNode=temp;
            temp=temp->next;
        }      

        int c = l-(k%l);
        ListNode* newHead =head;
        ListNode* prev = NULL;
        while(c--)
        {
            prev = newHead;
            newHead = newHead->next;
        }
        prev->next =NULL;
        lastNode->next = head;
        return newHead;

    }
};