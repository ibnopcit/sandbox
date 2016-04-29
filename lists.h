
template <class T> void LinkedList<T>::Clear() {
  while (head) {
    tmp = head;
    head = head->next;
    delete tmp;
  }
}

template <class T> T* LinkedList<T>::Remove() {
  T* res = NULL;
  if (head) {
    T elem = head->payload;
    tmp = head;
    head = head->next;
    delete tmp;
    res = &elem;
  }
  return res;
}

template <class T> void LinkedList<T>::Remove(const T& elem) {
  if (head) {
    if (head->payload == elem) {
      this->Remove();
    } else {
      Node *prev;
      for (prev = head, tmp = head->next; tmp != NULL;
          prev = prev->next, tmp = tmp->next) {
        if (tmp->payload == elem) {
          prev->next = tmp->next;
          delete tmp;
          return;
        }
      }
    }
  }
}

template <class T> T* LinkedList<T>::Find(const T& elem) const {
  T* res = NULL;

  for (tmp = head; tmp != NULL; tmp = tmp->next) {
    if (tmp->payload == elem) {
      res = &tmp->payload;
      break;
    }
  }
  return res;
}

template <class T> void LinkedList<T>::Add(T& elem) {
  head = new Node(elem, head);
}

template <class T> size_t LinkedList<T>::Length() {
  size_t len = 0;
  Node *ptr = Head();
  while (ptr) {
    ptr = ptr->next;
    len++;
  }
  return len;
}

template <class T> void LinkedList<T>::PrintAll(std::ostream& out) const {
  Node *tmp;
  for (tmp = head; tmp != NULL; tmp = tmp->next) {
    out << tmp->payload << " ";
  }
  //out << std::endl;
}


int f(int i) {
  return i+1;
}
