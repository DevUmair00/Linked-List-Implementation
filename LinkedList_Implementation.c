#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void nodeCreation(){
  int choice = 1;
  
  struct Node * temp = NULL;

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
  struct Node * temp = NULL;
  temp = head;
  while (temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}


int getLength()
{
    int count = 0;
    struct Node *temp = head;

    while(temp != NULL)
    {
      count++;
      temp = temp->next;   
    }
    return count;
}


//Insertion

void insertAtBeginning(int data)
{
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;  
}

void insertAtEnd(int data){
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL){
    head = newNode;
    return;
  }
  
  struct Node * temp = NULL;
  temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}


void insertBetween(int data, int pos) {
    int i;
    int count = getLength();

    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Insert at the beginning
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the node just before the position
    struct Node* temp = head;
    for (i = 1; i < pos - 1; i++) {

        temp = temp->next;
    }

    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;
}



//Deletion

void deleteBeginning(){
  if(head == NULL)
  {
    printf("Failed To Delete Empty Node");
  }
    struct Node *temp = head;
    head = head->next;
    free(temp); 
  
}


void deleteEnd(){

  if(head == NULL){
    return;
  }

  if(head->next == NULL){
    free(head);
    head = NULL;
    return;
  }

  struct Node *temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}


void deleteValue(int key){
  struct Node* temp = head;
  struct Node* prev = NULL;

  while(temp != NULL && temp->data != key){
    prev = temp;
    temp = temp->next;
  }

  if(temp == NULL) return;

  prev->next = temp->next;
  free(temp);
}


void deleteSpecificPos(int pos){
  
  if(pos< 1 || pos > getLength()){
    printf("Failed to Access this Node.");
    return;
  }
  
  
  struct Node *temp = head;
  struct Node *nextNode = NULL;

  if(pos == 1)
  {
    head = head->next;
    free(temp);
    return;
  }

  int count = 1;
    while(count < pos-1){
      temp = temp->next;
      count++;
    }
  
  nextNode = temp->next;
  temp->next = nextNode->next;
  free(nextNode);
}


int main()
{
    nodeCreation();
    displayList();
    insertAtBeginning(5);
    displayList();
    insertAtEnd(6);
    displayList();
    insertBetween(2,1);
    displayList();

    int x = getLength();
    printf("Length is %d" , x);

} 

