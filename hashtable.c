#include <stdio.h>
#include <stdlib.h> //malloc
#include <math.h>   //floor
#include <string.h> //strcmp

//implement a simple hash table 
//which stores Int values with a string key
#define HASHTABLESIZE 15
#define HASHCODECEILING 1000

/* linked List Bits */
struct snode {
  struct snode *next;
  char *key;
  int data;
};

struct snode *salloc(void){
  return (struct snode *) malloc(sizeof(struct snode));
}

struct snode *create_snode(int data, char *key){
  struct snode *new_snode = salloc();
  new_snode->data = data;
  new_snode->key = key;
  new_snode->next = NULL;
  return new_snode;
}

void appendsnode(struct snode *node, int data, char *key){
  if(node->next != NULL)
    appendsnode(node->next, data, key);
  else
    node->next = create_snode(data, key);
}

int snodefind(struct snode *node, char *key){
  if(strcmp(node->key, key) == 0)
    return node->data;
  else if(node->next != NULL)
    return(snodefind(node->next, key));
  else
    return 0; 
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

/* Hashing bits (very simplistic) */
int hashcode(char *key){
  char c;
  int hashcode = 0;
  while((c = *key++) != '\0'){
    hashcode += c;
  }
  return hashcode;
}

int map(int hashcode){
  float hc = (float)hashcode;
  float c = (float)HASHCODECEILING;
  if(hashcode > HASHCODECEILING)
    return HASHTABLESIZE - 1;
  else
    return (int)floor((hc/c) * HASHTABLESIZE);
}

/* Hashtable bits */
struct snode *hashtable[HASHTABLESIZE];

void put(int data, char *key){
  int i = map(hashcode(key));
  if(hashtable[i] == NULL){
    hashtable[i] = create_snode(data, key);
  } else {
    appendsnode(hashtable[i], data, key);
  }
}

int get(char *key){
  int i = map(hashcode(key));
  if(hashtable[i] == NULL){
    return 0; //TODO - I guess this should be an exception?
  } else {
    return snodefind(hashtable[i], key);
  }  
}

void hashtableprint(){
  for(int i = 0; i < HASHTABLESIZE; i++){
    printf("%d->", i);
    if(hashtable[i] == NULL){
      printf("\n");
    } else {
      snodeprint(hashtable[i], 1);
    }
  }
}

int main(){
  printf("%s -> %d -> %d\n", "a", hashcode("a"), map(hashcode("a")));
  printf("%s -> %d -> %d\n", "Abignail", hashcode("Abignail"), map(hashcode("Abignail")));
  printf("%s -> %d -> %d\n", "quitelongnameeee", hashcode("quitelongnameeee"), map(hashcode("quitelongnameeee")));
  printf("%s -> %d -> %d\n", "realyrealylongnamelonglong", hashcode("realyrealylongnamelonglong"), map(hashcode("realyrealylongnamelonglong")));

  put(356, "Bob");
  put(444, "quitelongnameeee");
  put(355556, "realyrealylongnamelonglong");
  hashtableprint();
  printf("find Bob = %d\n", get("Bob"));
}
