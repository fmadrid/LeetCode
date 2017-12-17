class Solution {
public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* rootNode = new ListNode(0);
        
		ListNode* currentNode = rootNode;
        int carry = 0;
		while(l1  || l2){
            
			ListNode* tempNode = new ListNode(carry);
            
			int& val = tempNode->val;
			val += (l1) ? l1->val : 0;
			val += (l2) ? l2->val : 0;
            
			carry = val / 10;
			val %= 10;
			
			currentNode->next = tempNode;
			currentNode = tempNode;
			if(l1) l1 = l1->next;
			if(l2) l2 = l2->next;
			
		}
        
		  if(carry) currentNode->next = new ListNode(carry);
        return rootNode->next;
            
    }
};
