template <class T, int size> void Stack<T, size>::Push(T elem) {
  if (IsFull()) {
    throw "Stack overflow";
  } else {
    s[++top] = elem;
  }
}

template <class T, int size> T Stack<T, size>::Pop() {
  T res;
  if (IsEmpty()) {
    throw "Empty stack";
  } else {
    res = s[top--];
  }
  return res;
}

template <class T, int size> T Stack<T, size>::Peek() {
  T res;
  if (IsEmpty()) {
    throw "Empty stack";
  } else {
    res = s[top];
  }
  return res;
}
