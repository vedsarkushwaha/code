#include<cstdio>

using namespace std:

struct node {
  node left;
  node right;
  int data;
}

int main() {
  struct rootNode = constructTree();
}

struct node* newNode(int data) {
  struct node* node = (struct node*) malloc(sizeof(strucy node));
  node->left = NULL;
  node->right = NULL;
  node->data = data;
}

// struct node* constructTree() {
//   struct node
// }
