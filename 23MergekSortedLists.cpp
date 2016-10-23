/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class comparison{
public:
    bool operator() (const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }  
};
 
class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;
	int k = lists.size(), i;
	ListNode init(0);
	ListNode *cur = &init;
	priority_queue<ListNode* ,vector<ListNode*>,comparison > store;
	for (i = 0; i < k; i++) {
	    if(lists[i]!=NULL) store.push(lists[i]);
	}
	if (store.empty()) return NULL;
	while(!store.empty()) {
		ListNode *minNode = store.top();
	    cur->next = minNode;
	    cur = cur->next;
		store.pop();
		if (minNode->next != NULL) {
			store.push(minNode->next);
		}
	}
	return init.next;
}
};