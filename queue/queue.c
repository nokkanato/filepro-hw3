/* Name: Kanokpatai Kanato
 * ID: 5680412å
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
  Node *newnode = (Node*) malloc(sizeof(Node));
  newnode->data= (char*) malloc(strlen(word));
  strcpy(newnode->data, word);
  newnode->next = NULL;

  if (*q == NULL){
    *q = (Queue*) malloc(sizeof(Queue)) ;
    (*q)->head = NULL;
    (*q)->tail = NULL;
  }

  if (isEmpty(*q)){

    (*q)->head = newnode;
    (*q)->tail = newnode;
    //newnode->next = NULL;
  }else{
    ((*q)->tail)->next = newnode;
    (*q)->tail = newnode;
    //newnode->next = NULL;

  }

    // IMPLEMENT
}

char *pop(Queue *q) {
  if (isEmpty(q)){
    return 0;
  }
  char *temp = (q->head)->data;

  Node *current = q->head;


  q->head = (q->head)->next;
  free(current);
  return temp;

    // IMPLEMENT
}

void print(Queue *q) {
  if (!isEmpty(q)){
  Node *current = q->head;
  while(current != NULL){
    printf("%s\n", current->data );
    current = current->next;
  }
    // IMPLEMENT
  }else{
    printf("%s\n","No items" );
  }
}

int isEmpty(Queue *q) {
  if (q == NULL || q->head == NULL ){
    return 1;
  }else{
    return 0;
  }
}

void delete(Queue *q) {
  while (!isEmpty(q)){
    char *temp = pop(q);
    free(temp);
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


    // print the NULL queue
    print(q);

    // push items

    push(&q, "b");
    push(&q, "c");
    // print(q);


    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        free(item);
    }
    //
    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(q);
    // print again
    print(q);
    printf("==============\n" );

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
