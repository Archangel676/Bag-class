#ifndef BAG_H
#define BAG_H

template<typename T>

class Bag {
private:
  int capacity;
  int sizeInUse;
  T* bagArray = nullptr;

  void grow()
  {
    int newCapacity = capacity + 10;
    T* tempArray = new T[newCapacity];

    for (int i = 0; i < capacity; i++) {
      tempArray[i] = bagArray[i];
    }

    capacity = newCapacity;

    delete[] bagArray;

    bagArray = tempArray;
  }

public:
  Bag()
  {
    sizeInUse = 0;
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

  T& operator=(const T& other)
  {
    if (this != other) {
      capacity = other.capacity;

      delete[] bagArray;

      bagArray = new T[capacity];

      for (int i = 0; i < capacity; i++) {
        bagArray[i] = other.bagArray[i];
      }
    }
    return *this;
  }

  void addItem(T item)
  {
    if (sizeInUse == capacity)
      grow();

    bagArray[sizeInUse] = item;

    sizeInUse++;
  }

  bool contains(T item)
  {
    bool contains = false;
    int count = 0;

    for (int i = 0; i < sizeInUse; i++) {
      if (bagArray[i] == item)
        count++;
    }
    if (count > 0)
      contains = true;

    return contains;
  }
};

#endif