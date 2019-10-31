#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;


void push(int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	temp = head;
	if(temp==NULL)
	 {
	 	head = new_node;
	 	return;
	 }
	 else
	   {
	   	while(temp->next!=NULL)
	   	  temp = temp->next;
	   	temp->next = new_node;
	  }
}
void search(struct node* head, int val)
{
	temp = head;
	while(temp!=NULL && temp->data!=val)
	  temp = temp->next;

    if(temp==NULL)
     printf("Value not present in list\n");
}

struct node* truncate(struct node* head, int val, int pos)
{
		temp = head;
		if(pos == 0)
		{
			search(head,val);
            while(temp->next!=NULL && temp->data!=val)
              temp = temp->next;
            temp->next = NULL;
		   head = temp;
           return head;
           
		}
		else if(pos < 0)
		{
		search(head,val);
			while(temp->next!=NULL && temp->data!=val)
			  temp = temp->next;
			head = temp;
			return head;
		}
		else if(pos > 0)
		{
			struct node* p = head;
			search(head,val);
			while(temp->next!=NULL && temp->data!=val)
			   temp = temp->next;
			temp->next = NULL;
			return p;
		}
}


void printList()
{
	temp = head;
	while(temp!=NULL){
	  printf("%d-->",temp->data);
	  temp = temp->next;
     }
}

int main()
{
   int ch,i;
   do{
   	printf("-----------Main Menu-----------\n");
   	printf("\t1. Insert into list\n\t2. Truncate list at position 0\n\t3. Truncate list before value \n\t4. Truncate list after value\n\t5. Exit\n");
   	printf("Enter your choice : ");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   		case 1:
   			 printf("Enter the element to insert : ");
   			 scanf("%d",&i);
   			 push(i);
   			 printList();
   			 printf("\n");
   			 break;
   	    case 2:
   	    	 printf("Enter value to truncate : ");
   	    	 scanf("%d",&i);
		     head = truncate(head,i,0);
		     printList();
		     printf("\n");
   	         break;	  
	    case 3:
   	    	 printf("Enter value to truncate : ");
   	    	 scanf("%d",&i);
		     head  = truncate(head,i,-1);
   	         printList(); 
			break;	  
	    case 4:
   	    	 printf("Enter value to truncate : ");
   	    	 scanf("%d",&i);
		     head = truncate(head,i,3);
		     printList(); 
			 printf("\n");
   	         break;	  
	   
	   }
   }while(ch!=5);	
 return 0;
}

