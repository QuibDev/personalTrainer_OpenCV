// LabWork 2 
// WAP Single Linked List and then implement  
// AddFirst [done]
// Remove elements multiple of 4 or 6
// add element at index
// removeLast [done]
// displaylist [done]
// replace element all 'x' in list by 'y' where y is entered by user. [done]


#include <stdio.h>
#include <stdlib.h>

struct node {
    int x; 
    struct node *next;
};

struct node *head;
int n; // no. of nodes


void addFirst();
void disp();
void addAtIndex();
void removeFirst();
void removeLast();
void removeMultiples();
void removeAtIndex();
void replace();

void main() {
    int f =1, ch;
    
    while (f==1) {
        printf("\n\n");
        printf("\n\nMenu:");
        printf("\n1. AddFirst");
        printf("\n2. RemoveLast");
        printf("\n3. RemoveMultiples of 6 or 4");
        printf("\n4. Replace X with Y");
        printf("\n5. Display");
        printf("\n6. Quit ");
        printf("\nEnter Choice >> ");
        scanf("%d",&ch);
        printf("\n\n");
        
        
        switch(ch) {
            case 1: addFirst(); break;
            
            case 2: removeLast(); break;
            
            case 3: removeMultiples(); break;
            
            case 4: replace(); break;
            
            case 5: disp(); break;
            
            case 6: // quit
             printf("quitting!");
             f == 0;
             break;
        }
        
    }

}

void addFirst(){
    struct node *temp; 
    temp = (struct node*) malloc(sizeof(struct node*));
    
    if (temp == NULL) {
        printf("\nOverflow");
    }
    
    else {
        int y;
        printf("\nEnter Value: ");
        scanf("%d",&y);
        
        temp-> x = y;
        
        temp->next = head;
        
        head = temp;
        
        n++;
    }
}

void disp() {
    
    struct node *temp; 
    
    if (head == NULL)
        printf("\nEmpty List");
        
    else {
        temp = head; 
        
        while (temp != NULL) {
            printf("%d ",temp->x);
            temp = temp -> next;
        }
    }
}

void removeFirst(){
    
    struct node *p = head; 
    head = p->next;
    free(p);
    
    return;
    
}


void removeLast(){
    struct node *p, *q;
    
    if (head == NULL) 
        printf("empty List");
        
    else if (head->next == NULL){
        free(head);
        printf("\nList is now empty");
    }
    
    else {
        p=head;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        
        free(p);
        q->next = NULL;
        }
        
    return;
    }

void removeAtIndex(int index){ 

    if (index < 0 || index >= n)
        printf("\nInvalid arguement");
    else if (index == 0)
        removeFirst();
    else if (index == n - 1)
        removeLast();
    else {
        struct node *temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        n--;
    }
    
    return;

}

void replace(){
    struct node *temp; 
    int x, y;   
    printf("\nEnter value to replace (x): ");
    scanf("%d",&x);
    printf("\nEnter value to replace with (y): ");
    scanf("%d",&y);
    
    if (head == NULL)
        printf("\nEmpty List");
        
    else {
        temp = head; 
        
        while (temp != NULL) {
            if(temp->x == x)
                temp->x = y;
            
            temp = temp -> next;
        }
    }
}

void removeMultiples(){
    struct node *temp;
    int index = 0;
    
    if (head == NULL) 
        printf("empty List");

    else {
        temp=head;
        while(temp!=NULL){
            if (temp->x%4  == 0 || temp->x%6 == 0) {
                printf("\nDeleting %d at index %d ",temp->x, index);
                removeAtIndex(index);
            }
            temp=temp->next;
            index++;
        }
    }
}



    