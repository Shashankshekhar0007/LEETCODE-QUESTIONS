  class compare{
    public:
           bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
           }   // For MIN Heap
  };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minheap;
        int k=lists.size();
        if(k==0)return NULL;
        for(ListNode* list:lists){
            if(list!=nullptr){
            minheap.push(list);
            }
        }
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        while(!minheap.empty()){
            ListNode*top=minheap.top();
            minheap.pop();
            if(top->next!=nullptr){
                minheap.push(top->next);
            }
            if(head==nullptr){
                head=top;
                tail=top;
            }
            else{
                  tail->next=top;
                  tail=tail->next;
            }
        }
        return head;
    }
};