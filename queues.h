template <class T, int size> void Queue<T, size>::Enqueue(T elem) {
  if (IsFull() == true) {
    //std::cout << "full queue " << lindex << ", " << rindex;
    throw "Full queue";
  } else {
    // End of normal buffer, or fresh?
    if (rindex == size - 1 || rindex == -1) {
      rindex = 0;
      lindex = lindex == -1 ? 0 : lindex;
    // Normalcy
    } else {
      ++rindex;
    }
    q[rindex] = elem;
  }
}

template <class T, int size> T Queue<T, size>::Dequeue() {
  T res;
  //std::cout << "size is " << size << std::endl;
  //std::cout << "lindex " << lindex << ", rindex " << rindex << std::endl;
  if (IsEmpty()) {
    throw "Empty queue";
  } else {
    res = q[lindex];
    // Emptied?
    if (lindex == rindex) {
      lindex = rindex = -1;
    // End of linear buffer?
    } else if (lindex == size - 1) {
      lindex = 0;
    // Normalcy
    } else {
      ++lindex;
      //std::cout << "lindex now " << lindex << std::endl;
    }
  }
  return res;
}
