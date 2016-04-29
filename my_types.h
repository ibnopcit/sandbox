#include <cstddef>
#include <iostream>
#include <vector>

int f(int);

template <class T> class LinkedList {
public:
  struct Node {
    T payload;
    Node *next;
    Node() {}
    Node(T elem, Node *ptr = NULL) {
      payload = elem;
      next = ptr;
    }
  };

  LinkedList() { head = NULL; }
  ~LinkedList() { Clear(); }
  void Clear();
  T* Find(const T&) const;
  void Add(T& elem);
  T* Remove();       // Remove head
  void Remove(const T&);   // Remove specified
  bool IsEmpty() { return head == NULL; }
  T* First() { return &head->payload; }
  Node *Head() { return head; }
  void PrintAll(std::ostream& out) const;
  size_t Length();

private:
  Node *head, *tmp;
};


// Queue implemented with ring buffer
template <class T, int size = 128> class Queue {
  T q[size];
  int lindex, rindex;

public:
  Queue() { lindex = rindex = -1; }
  T Dequeue();
  void Enqueue(T elem);
  // Circular buffer
  bool IsFull() { return lindex == 0 && rindex == size - 1 ||
    lindex == rindex + 1; }
  bool IsEmpty() { /*std::cout << lindex; */return lindex == -1; }
};


// Stack implemented with array
template <class T, int size = 128> class Stack {
  T s[size];
  int top;  // Highest existing element, not insertion point

public:
  Stack() { top = -1; }
  void Push(const T elem);
  T Pop();
  T Peek();
  bool IsFull() { return top == size - 1; }
  bool IsEmpty() { return top == -1; }
};

template <typename...> class TreeNode;
// Could be struct
template <typename K, typename V> class TreeNode<K, V> {
public:
  K key;
  V value;
  TreeNode *up, *left, *right;

  TreeNode() { up = left = right = NULL; }
  TreeNode(K k, V v) { key = k; value = v; TreeNode(); }
  TreeNode(K k, V v, TreeNode *l, TreeNode *r,
    TreeNode *u = NULL) {
    key = k; value = v; left = l; right = r; up = u;
  }
};


template <typename...> class BSTree;
template <typename K, typename V> class BSTree<K, V> {
public:
  BSTree() { root = NULL; }
  BSTree(TreeNode<K, V> *r) { root = r; }
  ~BSTree() {}
  bool IsEmpty() { return root == NULL; }
  TreeNode<K, V>* Insert(TreeNode<K, V> *n);
  TreeNode<K, V>* Delete(TreeNode<K, V> *n) { return Delete(n->key); }
  TreeNode<K, V>* Delete(K);
  TreeNode<K, V>* Search(K k) { return Search(root, k); }
  TreeNode<K, V>* Search(TreeNode<K, V>* n) { return Search(root, n->key); }
  TreeNode<K, V>* Search(TreeNode<K, V>*, K);
  std::vector<TreeNode<K, V>*> PreOrder() { return PreOrder(root); }
  std::vector<TreeNode<K, V>*> PreOrder(TreeNode<K, V> *n);
  std::vector<TreeNode<K, V>*> InOrder() { return InOrder(root); }
  std::vector<TreeNode<K, V>*> InOrder(TreeNode<K, V> *n);
  std::vector<TreeNode<K, V>*> PostOrder() { return PostOrder(root); }
  std::vector<TreeNode<K, V>*> PostOrder(TreeNode<K, V> *n);
  std::vector<TreeNode<K, V>*> LevelOrder() { return LevelOrder(root); }
  std::vector<TreeNode<K, V>*> LevelOrder(TreeNode<K, V> *n);
  TreeNode<K, V>* Root() { return root; }

protected:
  TreeNode<K, V> *root;
  void preOrder(TreeNode<K, V> *n, std::vector<TreeNode<K, V> *>& v);
  void inOrder(TreeNode<K, V> *n, std::vector<TreeNode<K, V> *>& v);
  void postOrder(TreeNode<K, V> *n, std::vector<TreeNode<K, V> *>& v);
  void levelOrder(TreeNode<K, V> *n, std::vector<TreeNode<K, V> *>& v);
};

// Linker doesn't recognize non-specialized template functions in cpp files
#include "lists.h"
#include "queues.h"
#include "stacks.h"
#include "trees.h"
