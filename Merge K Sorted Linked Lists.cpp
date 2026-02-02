//Brute Force Solution
ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                ans.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* dumNxt=dummy;
        for(int i=0;i<ans.size();i++){
            dumNxt->next=new ListNode(ans[i]);
            dumNxt=dumNxt->next;
        }
        dumNxt->next=NULL;
        return dummy->next;
    }
};

//Better Solution
class Solution {
public:
    ListNode* merge(ListNode* temp1, ListNode* temp2){
        ListNode* dummy=new ListNode(-1);
        ListNode* dum=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                dum->next=temp1;
                dum=dum->next;
                temp1=temp1->next;
            }
            else if(temp2->val<temp1->val){
                dum->next=temp2;
                dum=dum->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            dum->next=temp1;
            dum=dum->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            dum->next=temp2;
            dum=dum->next;
            temp2=temp2->next;
        }
        dum->next=NULL;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};

//Optimal Solution
ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<pair<int,ListNode*>, 
        vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        ListNode* dummy=new ListNode(-1);
        ListNode* dum=dummy;
        for(int i=0;i<lists.size();i++){
            ListNode* node=lists[i];
            if(node!=NULL) pq.push({node->val, node});
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ListNode* nodes=top.second;
            dum->next=nodes;
            if(nodes->next!=NULL) pq.push({nodes->next->val,nodes->next});
            dum=dum->next;
        }
        return dummy->next;
    }
