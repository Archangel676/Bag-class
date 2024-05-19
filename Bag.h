#ifndef BAG_H
#define BAG_H

template<typename T>

class Bag {
private:
  int capacity;
  T* bagArray = nullptr;

public:
  Bag()
  {
    capacity = 10;
    bagArray = new T[capacity];
  }

  ~Bag()
  {
    delete[] bagArray;
  }

  Bag(const Bag& other)
  {
    capacity = other.capacity;
    bagArray = new T[capacity];

    for (int i = 0; i < capacity; i++) {
      bagArray[i] = other.bagArray[i];
    }
  }

  Copy constructor, Assignment Operator
};

#endif