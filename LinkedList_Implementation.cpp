#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL, *temp = NULL;

void nodeCreation(){
  int choice = 1;
  while(choice == 1){
    
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    
    if(head == NULL){
      head = temp = newNode;
    }
    else{
      temp->next = newNode;
      temp = newNode;
    }
    newNode->next = NULL;

    printf("Do you want to Continue (1/0)");
    scanf("%d",&choice);
  }
}

void displayList()
{
  temp = head;
  while (temp != NULL)
  {
    printf("%d",temp->data);
    temp = temp->next;
  }
}


//Insertion

void insertAtBeginning()
{
  
}

int main()
{
    nodeCreation();
} 

