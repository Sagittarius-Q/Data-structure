#include <stdio.h>
#include <stdlib.h>

struct n {
  int data;                                            //   Box for store our DATA. Type is Integer  
  n * next;                                            //   Points next box ("node"), store memmory address  
};

typedef n node;                                        //   Define new type: struct n -> node 

void add_data(node *root, int data);                   //   Function prototype: add and print data . Body of functions in following code
void print_data(node *root);

int main() {
  node * root;                                         //   First node name's root, it's pointing next box ("node")  
  node * iter;
  root =  (node*)malloc(sizeof(node));
  root -> next = NULL;
  root -> data = 1;
  add_data(root, 30);
  int i;
  for( i=0; i<10; i++) {                               //   for loop for add new data in node, we use function "add_data(node*root , int data)
    add_data(root, i * 5);
  }
			
  print_data(root);                                    //   This function print all data of node (box)
 
}

void add_data(node *root, int data) {
  while(root -> next != NULL) {
    root = root -> next;
  }
  root -> next = (node*)malloc(sizeof(node));
  root -> next -> data = data;
  root -> next -> next = NULL;

}
void print_data(node *root) {
  while(root != NULL) {
    printf("%d ", root -> data);
    root = root -> next;
  }
}
