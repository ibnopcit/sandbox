#include "my_types.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

void test_lists();
void test_queues();
void test_stacks();
void test_trees();

char *h = strdup("Hello");
char *c = strdup("cruel");
char *w = strdup("world");

int main() {
  //cout << f(1) << endl;
  // test_lists();
  //test_queues();
  //test_stacks();
  test_trees();

  cout << "(done)" << endl;
  return 1;
}


void test_trees() {
  char *r = strdup("root");
  char *c1 = strdup("lorem");
  char *c2 = strdup("ipsum");
  TreeNode<int, char*> *root = new TreeNode<int, char*>(0, r);
  BSTree<int, char*> tree = BSTree<int, char*>(root);

  assert(!tree.IsEmpty());
  tree.Insert(new TreeNode<int, char*>(-1, h));
  tree.Insert(new TreeNode<int, char*>(1, c));

  assert(tree.Search(2) == NULL);
  assert(tree.Search(1)->up == root);
  assert(tree.Search(0)->left->value == h);
  assert(tree.Delete(2) == NULL);
  assert(tree.Delete(1)->key == 1);
  assert(root->left->key == -1);
  assert(root->right == NULL);
  //cout << "deleting root ..." << endl;
  assert(tree.Delete(0) == root);
  assert(tree.Root()->key == -1);

  BSTree<int, char*> trav = BSTree<int, char*>();
  trav.Insert(new TreeNode<int, char*>(5, r));
  trav.Insert(new TreeNode<int, char*>(1, c1));
  trav.Insert(new TreeNode<int, char*>(8, c2));
  trav.Insert(new TreeNode<int, char*>(3, c1));
  trav.Insert(new TreeNode<int, char*>(2, c2));
  trav.Insert(new TreeNode<int, char*>(4, c1));
  trav.Insert(new TreeNode<int, char*>(7, c2));
  trav.Insert(new TreeNode<int, char*>(9, c1));
  trav.Insert(new TreeNode<int, char*>(6, c2));

  // cout << "populated" << endl;

  std::vector<TreeNode<int, char*> *> res;

  res = trav.PreOrder();
  cout << "pre-order:\t";
  for (TreeNode<int, char*> *n : res) {
    cout << n->key << " ";
  }
  cout << endl;

  res = trav.InOrder();
  cout << "in-order:\t";
  for (TreeNode<int, char*> *n : res) {
    cout << n->key << " ";
  }
  cout << endl;

  res = trav.PostOrder();
  cout << "post-order:\t";
  for (TreeNode<int, char*> *n : res) {
    cout << n->key << " ";
  }
  cout << endl;

  res = trav.LevelOrder();
  cout << "level-order:\t";
  for (TreeNode<int, char*> *n : res) {
    cout << n->key << " ";
  }
  cout << endl;

  trav.Delete(2);
  trav.Delete(4);
  trav.Delete(6);
  trav.Delete(8);

  res = trav.LevelOrder();
  cout << "level-order, evens deleted:\t";
  for (TreeNode<int, char*> *n : res) {
    cout << n->key << " ";
  }
  cout << endl;

  std::vector<int> expected = {3, 1, 9, 7, 5};
  std::vector<int> found;
  res = trav.PostOrder();
  cout << "post-order, evens deleted:\t";
  for (TreeNode<int, char*> *n : res) {
    cout << n->key << " ";
    found.push_back(n->key);
  }
  cout << endl;
  assert(found == expected);

  cout << endl;
}

void test_stacks() {
  Stack<char*> my_stack;
  char *p;

  cout << "Testing stacks ..." << endl;

  assert(my_stack.IsEmpty());
  my_stack.Push(c);
  my_stack.Push(h);
  p = my_stack.Pop();
  assert(p == h);
  p = my_stack.Pop();
  assert(p == c);
  assert(my_stack.IsEmpty());
  my_stack.Push(w);
  my_stack.Push(h);
  p = my_stack.Pop();

  cout << p << " " << my_stack.Pop() << endl;
  assert(my_stack.IsEmpty());

  cout << endl;

}

void test_queues() {
  Queue<char*> my_queue;
  char *d;

  cout << "Testing queues ..." << endl;

  assert(my_queue.IsEmpty());
  my_queue.Enqueue(h);
  my_queue.Enqueue(c);
  d = my_queue.Dequeue();
  //cout << d << endl;
  assert(d == h);
  d = my_queue.Dequeue();
  assert(d == c);
  my_queue.Enqueue(h);
  my_queue.Enqueue(w);
  d = my_queue.Dequeue();
  assert(d == h);
  //cout << d << endl;
  cout << d << " " << my_queue.Dequeue() << endl;
  assert(my_queue.IsEmpty());

  cout << endl;
}

void test_lists() {
  LinkedList<char*> my_list;

  cout << "Testing lists ..." << endl;

  assert(my_list.IsEmpty());

  my_list.Add(w);
  my_list.Add(c);
  my_list.Add(h);

  my_list.PrintAll(cout);
  cout << endl;

  my_list.Remove(c);
  my_list.PrintAll(cout);
  cout << endl;

  LinkedList<char*>::Node *n = my_list.Head();
  int len = 0;
  while (n) {
    n = n->next;
    len++;
  }
  cout << "List length is: " << len << ", or (object) " <<
    my_list.Length() << endl;

  cout << endl;
}
