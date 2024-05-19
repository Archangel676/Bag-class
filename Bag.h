#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <string>
using std::string;
using std::to_string;

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

    for (int i = 0; i < sizeInUse; i++) {
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
    sizeInUse = other.sizeInUse;
    bagArray = new T[capacity];

    for (int i = 0; i < sizeInUse; i++) {
      bagArray[i] = other.bagArray[i];
    }
  }

  Bag& operator=(const Bag& other)
  {
    if (this != &other) {
      capacity = other.capacity;
      sizeInUse = other.sizeInUse;

      delete[] bagArray;

      bagArray = new T[capacity];

      for (int i = 0; i < sizeInUse; i++) {
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
    for (int i = 0; i < sizeInUse; i++) {
      if (bagArray[i] == item)
        return true;
    }
    return false;
  }

  string toString() const
  {
    string s = "";
    s += "{";
    cout << s;
    for (int i = 0; i < sizeInUse - 1; i++) {
      s += to_string(bagArray[i]);
    }
    cout << s;
    s += to_string(bagArray[sizeInUse]);
    s += "}";
    cout << s;
    return s;
  }
};

#endif