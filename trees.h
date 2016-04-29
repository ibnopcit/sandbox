template <typename K, typename V>
TreeNode<K, V>* BSTree<K, V>::Insert(TreeNode<K, V> *n) {
  TreeNode<K, V> *p = NULL;
  if (root == NULL) {
    root = p = n;
  } else {
    p = root;
    TreeNode<K, V> *prev;
    while (p) {
      prev = p;
      if (n->key == p->key) {
        // throw "Key exists"
        return NULL;
      } else if (n->key < p->key) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
    if (n->key < prev->key) {
      // We went left
      prev->left = n;
    } else {
      prev->right = n;
    }
    n->up = prev;
  }
  return p;
}


template <typename K, typename V> TreeNode<K, V>* BSTree<K, V>::Delete(K k) {
  TreeNode<K, V> *p = root, *prev, *res = NULL;

  while (p) {
    if (k < p->key) {
      //std::cout << "left " << k << std::endl;
      prev = p;
      p = p->left;
    } else if (k > p->key) {
      //std::cout << "right " << k << std::endl;
      prev = p;
      p = p->right;
    } else {
      //std::cout << "equal " << k << std::endl;

      // Is this a leaf?
      if (p->left == NULL && p->right == NULL) {
        //std::cout << "leaf " << k << std::endl;
        // Null out the parent pointer
        if (p == root) {
          //std::cout << "nulling root" << std::endl;
          root = NULL;
        } else {
          if (p == prev->left) {
            //std::cout << "setting left on parent " << k << std::endl;
            prev->left = NULL;
          } else {
            //std::cout << "setting right on parent " << k << std::endl;
            prev->right = NULL;
          }
        }
        res = p;
        p = NULL;

      // One-child node?
      } else if (p->left == NULL || p->right == NULL) {
        //std::cout << "one-child " << k << std::endl;
        TreeNode<K, V> *ch = p->left == NULL ? p->right:p->left;
        if (p == root) {
          //std::cout << "nulling root (one-child)" << std::endl;
          ch->up = NULL;
          root = ch;
        } else {
          if (p == prev->left) {
            prev->left = ch;
          } else {
            prev->right = ch;
          }
          ch->up = prev;
        }
        res = p;
        p = NULL;

      // Complicated case:  two children, merge required
      } else {
        //std::cout << "complicated " << k << std::endl;
        // Move left, then all the way right
        TreeNode<K, V> *tmp = p->left;
        while (tmp->right)
          tmp = tmp->right;
        // Link with right subtree
        tmp->right = p->right;
        p->right->up = tmp;
        // Link left subtree to main tree
        if (p == root) {
          root = p->left;
        } else {
          if (p == prev->left) {
            prev->left = p->left;
          } else {
            prev->right = p->left;
          }
        }
        p->left->up = prev;    // NULL for root
        res = p;
        p = NULL;
      }
    }
  }
  return res;
}


template <typename K, typename V> TreeNode<K, V>*
BSTree<K, V>::Search(TreeNode<K, V> *start, K k) {
  TreeNode<K, V> *p = start;

  while (p) {
    if (k == p->key) {
      break;
    } else if (k < p->key) {
      p = p->left;
    } else {
      p = p->right;
    }
  }
  return p;
}

template <typename K, typename V>
std::vector<TreeNode<K, V> *> BSTree<K, V>::PreOrder(TreeNode<K, V> *start) {
  std::vector<TreeNode<K, V> *> v;// = new std::vector<TreeNode<K, V> *>();
  preOrder(start, v);
  return v;
}

template <typename K, typename V>
void BSTree<K, V>::preOrder(TreeNode<K, V> *start,
  std::vector<TreeNode<K, V>*>& v) {

  TreeNode<K, V> *p = start;
  if (p) {
    v.push_back(p);
    preOrder(p->left, v);
    preOrder(p->right, v);
  }
  return;
}

template <typename K, typename V>
std::vector<TreeNode<K, V> *> BSTree<K, V>::InOrder(TreeNode<K, V> *start) {
  std::vector<TreeNode<K, V> *> v;// = new std::vector<TreeNode<K, V> *>();
  inOrder(start, v);
  return v;
}

template <typename K, typename V>
void BSTree<K, V>::inOrder(TreeNode<K, V> *start,
  std::vector<TreeNode<K, V>*>& v) {

  TreeNode<K, V> *p = start;
  if (p) {
    inOrder(p->left, v);
    v.push_back(p);
    inOrder(p->right, v);
  }
  return;
}

template <typename K, typename V>
std::vector<TreeNode<K, V>*> BSTree<K, V>::PostOrder(TreeNode<K, V> *start) {
  std::vector<TreeNode<K, V> *> v;// = new std::vector<TreeNode<K, V> *>();
  postOrder(start, v);
  return v;
}

template <typename K, typename V>
void BSTree<K, V>::postOrder(TreeNode<K, V> *start,
  std::vector<TreeNode<K, V>*>& v) {

  TreeNode<K, V> *p = start;
  if (p) {
    postOrder(p->left, v);
    postOrder(p->right, v);
    v.push_back(p);
  }
  return;
}

// Breadth-first
template <typename K, typename V>
std::vector<TreeNode<K, V>*> BSTree<K, V>::LevelOrder(TreeNode<K, V> *start) {
  std::vector<TreeNode<K, V> *> v;// = new std::vector<TreeNode<K, V> *>();
  levelOrder(start, v);
  return v;
}

template <typename K, typename V>
void BSTree<K, V>::levelOrder(TreeNode<K, V> *start,
  std::vector<TreeNode<K, V>*>& v) {

  TreeNode<K, V> *n = start;
  Queue<TreeNode<K, V> *> q;
  if (n) {
    q.Enqueue(n);
    while (!q.IsEmpty()) {
      TreeNode<K, V> *d = q.Dequeue();
      v.push_back(d);
      if (d->left) { q.Enqueue(d->left); }
      if (d->right) { q.Enqueue(d->right); }
    }
  }
  return;
}
