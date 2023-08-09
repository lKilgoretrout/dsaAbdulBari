#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* head;
    int   num;    // number of Nodes in LL
} LinkedList;

void Display(LinkedList linkedlist)
{
    Node* curr = linkedlist.head;
    printf("\nYour linked list: ");
    while(curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

LinkedList* CreateLinkedList()
{
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));
    Node* head = (Node*) malloc(sizeof(Node));
    ll->head   = head;
    
    Node* last = head;
    Node *tail, *current, *next;
    int num;      // num of nodes in LL

    printf("\nhow many links you want in that list, amigo? ");
    scanf("%d", &num);

    // create first Node:
    printf("\nlink 1 value: ");
    int num1;
    scanf("%d", &num1);
    head->data = num1;


    int val;
    for (int i=1; i<num; i++)
    {
        current    = (Node*) malloc(sizeof(Node));
        tail       = current;
        last->next = current;       // assign next pointer for last Node created
        last       = current;
        current->next = '\0';

        printf("\nlink %d value: ", i+1);
        scanf("%d", &val);
        current->data = val;
    }

    return ll;
}

int main()
{
    printf("Welcome to RJ's LinkedList program!\n");
    LinkedList* linkedlist = CreateLinkedList();
    Display(*linkedlist);

    return 1;
}
