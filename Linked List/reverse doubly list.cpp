DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
if(llist==NULL || llist->next==NULL)
    return llist;
    
    DoublyLinkedListNode* newhead = reverse(llist->next);
    
    llist->next->next = llist;
    llist->next->prev = llist->next;
    llist->next=NULL;
    
    return newhead;
}