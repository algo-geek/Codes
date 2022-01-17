DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    
    DoublyLinkedListNode* n= new DoublyLinkedListNode(data);
    DoublyLinkedListNode* temp = head;
    
    if(temp==NULL)//no element in list initially
    {
        head = n;
    }
   else if(temp->data > data){
        n->next = temp;
        temp->prev = n;
        head = n;
    }
    else{
        while((temp->next!=NULL)&&(temp->next->data < data)){
             temp=temp->next;
        }
        n->prev = temp;
        if (temp->next!=NULL){
            n->next = temp->next;
            temp->next->prev = n;
        }
        temp->next = n;
    }
    
    return head;
}