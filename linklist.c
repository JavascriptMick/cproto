#include <stdio.h> /* NULL */
#include <stdlib.h> /* malloc */

struct inode {
  struct inode *next;
  int data;
};

struct snode {
  struct snode *next;
  char *key;
  int data;
};

struct inode *nalloc(void){
  return (struct inode *) malloc(sizeof(struct inode));
}

struct snode *salloc(void){
  return (struct snode *) malloc(sizeof(struct snode));
}

struct inode *create_inode(int data){
  struct inode *new_inode = nalloc();
  new_inode->data = data;
  new_inode->next = NULL;
  return new_inode;
}

struct snode *create_snode(int data, char *key){
  struct snode *new_snode = salloc();
  new_snode->data = data;
  new_snode->key = key;
  new_snode->next = NULL;
  return new_snode;
}

void append(struct snode *node, int data, char *key){
  if(node->next != NULL)
    append(node->next, data, key);
  else
    node->next = create_snode(data, key);
}


void inodeprint(struct inode *p, int top){
  if(p != NULL) {
    if(top==0)
      printf("->");
    printf("%d", p->data);
    inodeprint(p->next, 0);
  }
  if(top!=0)
    printf("\n");
}

void snodeprint(struct snode *p, int top){
  if(p != NULL) {
    if(top==0)
      printf("->");
    printf("%s:%d", p->key, p->data);
    snodeprint(p->next, 0);
  }
  if(top!=0)
    printf("\n");
}

int main()
{
  struct inode n;
  n.data = 42;
  struct inode c;
  c.data = 69;
  n.next = &c;
  inodeprint(&n, 1);

  struct inode *testnext = nalloc();  
  testnext->data = 69;
  testnext->next = NULL;
  struct inode *testinode = nalloc();
  testinode->data = 42;
  testinode->next = testnext;
  inodeprint(testinode, 1);

  struct snode *new_snode = create_snode(42, "life");
  append(new_snode, 69, "death");
  snodeprint(new_snode, 1);
}