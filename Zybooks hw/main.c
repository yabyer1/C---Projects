/******************************************************************************
Create a linked list node struct to hold an integer value
Name the struct Node
Name the integer num
Name the node pointer next
Create a bubble sort function that will sort the values in a linked list using the bubble sort algorithm
You can swap contents of the nodes rather than swapping the order of the nodes
After each pass of the bubble sort, print the list to the console
Print a space between each integer and a new line after the last integer
Create a selection sort function that will sort the values in a linked list using the selection sort algorithm
You can swap contents of the nodes rather than swapping the order of the nodes
After each swap of the selection sort, print the list to the console
Print a space between each integer and a new line after the last integer
Create  a driver to test the functions
Create two linked lists
The linked lists will hold the same data as entered from the user
Prompt the user to enter 8 integers.
Store each of the values in both linked lists
Display the contents of the first linked list
Print a space between each integer and a new line after the last integer
Call the bubble sort function with the first linked list
Display the contents of the second linked list
Print a space between each integer and a new line after the last integer
Call the selection sort function with the second linked list


*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
struct Node{
    int num;
    struct Node * next;
};
void printList(struct Node ** head)
{
    struct Node *temp;
    temp = *head;

    
    while(temp!=NULL)
    {
        printf("%d ", temp -> num);
        
        temp= temp->next;
    }
    printf("\n");
  
}
void BubbleSort(struct Node **head1){
  struct  Node *i = *head1;
  int temp;
  int sorted = 0;
 for (int x = 0; x < 7; x++){
    // printList(head1);
    sorted = 0;
     for (int y = 0; y < 8 - x - 1; y++ ){
          if (i->num > i-> next ->num) {
                temp = i -> num;
                i -> num = i ->next -> num;
                i ->next -> num = temp;
                sorted = 1;
         }
         i = i -> next;
     }
     if (sorted == 0){
         return;
     }
     i = *head1;
     printList(head1);
 }
 printList(head1);
 
 //printList(head1);
}
void SelectionSort(struct Node ** head2){
    struct Node * i = *head2;
    struct Node * lowest = NULL;
    int value;
    while ( i  != NULL){
        lowest = i;
        struct Node * j = i -> next;
        while( j != NULL){
            if (j -> num < lowest -> num){
                lowest = j;
            
            }
            j = j -> next;
        }
       value = i -> num;
       i -> num = lowest -> num;
       lowest -> num = value;
       i = i -> next;
        printList(head2);
    }
}

void SelectionSort1(struct Node ** head2){
    struct Node * i = *head2;
    struct Node * j = NULL;
    struct Node * lowest = NULL;
    int temp = 0;
    for(int x = 0; x < 7; x++){
        j = i;
        lowest = i;
        for(int y = x; y < 8; y++){
            if (j -> num < lowest -> num ){
                lowest = j;
            }
            j = j -> next;
        }
        temp = i -> num;
        i -> num = lowest -> num;
        lowest -> num = temp;
        i = i -> next;
        printList(head2);
    }
}

int main()
{
    int value;
    struct Node * head1 = NULL;
    struct Node * second = NULL;
    struct Node * third = NULL;
    struct Node * fourth = NULL;
    struct Node * fifth = NULL;
    struct Node * sixth = NULL;
    struct Node * seventh = NULL;
    struct Node * eight = NULL;
   head1 = (struct Node *) malloc (sizeof(struct Node));
   second = (struct Node *) malloc (sizeof(struct Node));
   third = (struct Node *) malloc (sizeof(struct Node));
   fourth = (struct Node *) malloc (sizeof(struct Node));
   fifth = (struct Node *) malloc (sizeof(struct Node));
   sixth = (struct Node *) malloc (sizeof(struct Node));
   seventh = (struct Node *) malloc (sizeof(struct Node));
   eight = (struct Node *) malloc (sizeof(struct Node));
   head1 -> next = second;
   second -> next = third;
   third -> next = fourth;
   fourth -> next = fifth;
   fifth -> next = sixth;
   sixth -> next = seventh;
   seventh -> next = eight;
   eight -> next = NULL;
    //FIRST SET OF NODES
    struct Node * head2 = NULL;
    struct Node * second2 = NULL;
    struct Node * third2 = NULL;
    struct Node * fourth2 = NULL;
    struct Node * fifth2 = NULL;
    struct Node * sixth2 = NULL;
    struct Node * seventh2 = NULL;
    struct Node * eight2 = NULL;
    head2 = (struct Node *) malloc (sizeof(struct Node));
    second2 = (struct Node *) malloc (sizeof(struct Node));
   third2 = (struct Node *) malloc (sizeof(struct Node));
   fourth2 = (struct Node *) malloc (sizeof(struct Node));
   fifth2 = (struct Node *) malloc (sizeof(struct Node));
   sixth2 = (struct Node *) malloc (sizeof(struct Node));
   seventh2 = (struct Node *) malloc (sizeof(struct Node));
   eight2 = (struct Node *) malloc (sizeof(struct Node));
    head2 -> next = second2;
   second2 -> next = third2;
   third2 -> next = fourth2;
   fourth2 -> next = fifth2;
   fifth2 -> next = sixth2;
   sixth2 -> next = seventh2;
   seventh2 -> next = eight2;
   eight2 -> next = NULL;
    //SECOND SET OF NODES
    struct Node * runner1 = head1;
    struct Node * runner2 = head2;
       puts("Enter 8 integers: \n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &value);
        runner1 -> num = value;
        runner2 -> num = value;
        runner1 = runner1 -> next;
        runner2 = runner2 -> next;
        //printf("%d\n", arr[i]);
    }
    // puts("First LL");
    //bubbleSort1(head1);
    //puts("Second LL");
      //SelectionSort(&head1);
   //printList(&head1);
  // BubbleSort(&head1);
   //printList(&head2);
   puts("\n FIRST LIST: \n");
   printList(&head1);
   BubbleSort(&head1);
   printList(&head1);
   puts("\n SECOND LIST: \n");
   printList(&head2);
   SelectionSort1(&head2);
  // puts("OTHER ONE\n");
   //SelectionSort1(&head1);
   // return 0;
}
