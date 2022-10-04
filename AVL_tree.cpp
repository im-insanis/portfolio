struct node {
  int key;
  struct node *left, *right;
  int height;
};

int max(int a, int b) {
  return (a > b)? a : b;
}

struct node* newNode(int key) {
  struct node *temp = (struct *node)malloc(sizeof(struct node));

  temp->data = key;
  temp->left = NULL;
  temp->right = NULL;
  temp->height = 1;
  return temp;
}

struct node *leftRotate (struct node *z) {
  struct node *y = z->right;
  struct node *T2 = y->left;

// left 회전 수행
  y->left = z;
  z->right = T2;

// 노드 높이 갱신
  z->height = 1 + max(z->left->height, z->right->height);
  y->height = 1 + max(y->left->height, y->right->height);

// 새로운 루트 노드 y를 반환  
  return y;
}


struct node *rightRotate (struct node *z) {
  struct node *y = z->left;
  struct node *T2 = y->right;

// right 회전 수행
  y->right = z;
  z->left = T2;

// 노드 높이 갱신
  z->height = 1 + max(z->left->height, z->right->height);
  y->height = 1 + max(y->left->height, y->right->height);

// 새로운 루트 노드 y를 반환  
  return y;
}

// BF(BalanceFactor)값을 가져오는 함수.
int getBalanceFactor(struct node *n) {
  if (n == NULL)
    return 0;
  return n->left->height - n->right->height;
}

// 트리의 높이 균형을 유지하는 함수.
// 4가지 케이스를 가지고 rotate를 수행함.
struct node* rebalance(struct node* root) {
  
  int bFactor = getBalanceFactor(root);
  
  // LL Case
  if (bFactor > 1 && key < node->left->key)
    return rightRotate(root);
  // RR Case
  if (bFactor < -1 && key > node->right->key)
    return leftRotate(root);
  // LR Case
  if (bFactor > 1 && key > node->left->key){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // RL Case
  if (bFactor < -1 && key < node->right->key){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// 삽입 함수.
struct node* insert(struct node* root, int key) {

// 삽입 수행
  if (root == NULL)
    return newNode(key);
  if (key > root->data)
    root->right = insert(root->right, key);
  else if (key < root->data)
    root->left = insert(root->left, key);
  else
    return root;

// 노드 높이 갱신
  root->height = 1 + max(node->left->height, node->right->height);

// 노드 균형 유지  
  root = rebalance(root);
  
  return root;
}