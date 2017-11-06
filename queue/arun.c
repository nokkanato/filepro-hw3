/* Name:
 * ID:
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
  if((*q)==NULL){
    (*q) = (Queue *)malloc(sizeof(Queue));
  }
  Node *new_node = (Node *)malloc(sizeof(Node));
  char *copyOfWord = (char *)malloc(strlen(word)+1);
  strcpy(copyOfWord,word);
  new_node->data = copyOfWord;
  new_node->next = NULL;
  if((*q)->head == NULL){ //check if there's only one
    (*q)->head = new_node;
    (*q)->tail = new_node;
  } else {
    (*q)->tail->next = new_node ; //old tail points to head
    (*q)->tail = new_node; //retrieve new tail
  }
    // IMPLEMENT
}

char *pop(Queue *q) {
    // IMPLEMENT
    char* c;
    Node* new_node;
    if(q->head == NULL){
    	return NULL;
    }
    new_node = q->head;
    q->head = q->head->next;
    c = new_node->data;
    free(new_node);
    return c;
}

void print(Queue *q) {
  if(q == NULL || q->head == NULL){
    printf("No items\n");
  }
  Node * curr;
  for(curr=q->head; curr!=NULL; curr=curr->next){
    printf("%s\n", curr->data);
  }
    // IMPLEMENT
}

int isEmpty(Queue *q) {
  if(q == NULL || q->head == NULL){
    return 1;
  }else{
    return 0;
  }
    // IMPLEMENT
}

void delete(Queue *q) {
    // IMPLEMENT
    while(isEmpty(q)!=1){
    	free(pop(q));
    }
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;

    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    // print(q);

    // // pop items
    // while (!isEmpty(q)) {
    //     char *item = pop(q);
    //     printf("%s\n", item);
    //     free(item);
    // }
    //
    // char *item = pop(q);
    // assert(item == NULL);
    //
    // // // push again
    // push(&q, "d");
    // push(&q, "e");
    // push(&q, "f");
    // print(q);
    //
    // // destroy the queue
    // delete(q);
    //
    // // // print again
    // print(q);
    //
    // // // check copy
    // char *s = (char *)malloc(10);
    // strcpy(s, "Hello");
    // push(&q, s);
    // strcpy(s, "World");
    // char *t = pop(q);
    // printf("s = %s\n", s);
    // printf("t = %s\n", t);
    // free(t);
    // free(s);
    //
    // // // free the queue
    // free(q);
}
