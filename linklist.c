#include <stdio.h> /* NULL */
#include <stdlib.h> /* malloc */

struct node {
  struct node *next;
  int data;
};

struct node *nalloc(void){
  return (struct node *) malloc(sizeof(struct node));
}

void nodeprint(struct node *p, int top){
  if(p != NULL) {
    if(top==0)
      printf("->");
    printf("%d", p->data);
    nodeprint(p->next, 0);
  }
  if(top!=0)
    printf("\n");
}

int main()
{
  struct node n;
  n.data = 42;
  struct node c;
  c.data = 69;
  n.next = &c;
  nodeprint(&n, 1);

  struct node *testnext = nalloc();  
  testnext->data = 69;
  testnext->next = NULL;
  struct node *testnode = nalloc();
  testnode->data = 42;
  testnode->next = testnext;
  nodeprint(testnode, 1);
}