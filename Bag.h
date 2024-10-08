#ifndef BAG_H
#define BAG_H

#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

template<typename T>

class Bag {
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

    for (int i = 0; i < sizeInUse; i++) {
      s += to_string(bagArray[i]);

      if (i < sizeInUse - 1)
        s += ", ";
    }
    s += "}";
    return s;
  }

  bool removeItem(T item)
  {
    if (contains(item)) {
      for (int i = 0; i < sizeInUse; i++) {
        if (bagArray[i] == item) {
          bagArray[i] = bagArray[sizeInUse - 1];
          sizeInUse--;
          return true;
        }
      }
    }
    return false;
  }

  bool isEmpty()
  {
    if (sizeInUse == 0)
      return true;
    return false;
  }

  void dump()
  {
    sizeInUse = 0;
  }

  int numberOf(T item)
  {
    int num = 0;

    if (contains(item)) {
      for (int i = 0; i < sizeInUse; i++) {
        if (bagArray[i] == item)
          num++;
      }
    }
    return num;
  }

  void removeAll(T item)
  {
    int numbOfTimes = numberOf(item);
    for (int i = 0; i < numbOfTimes; i++) {
      removeItem(item);
    }
  }

  T pickRandom()
  {
    assert(!isEmpty());
    int randNum = rand() % sizeInUse;
    T thing = bagArray[randNum];
    removeItem(thing);
    return thing;
  }

  void dumpInto(Bag<T>& other)
  {
    other.capacity = capacity;
    other.sizeInUse = sizeInUse;

    for (int i = 0; i < sizeInUse; i++) {
      other.addItem(bagArray[i]);
    }
    sizeInUse = 0;
  }

  Bag<T> extractAll(T item)
  {
    Bag newBag = Bag();
    int originalSize = sizeInUse;
    for (int i = 0; i < originalSize; i++) {
      if (bagArray[i] == item) {
        newBag.addItem(bagArray[i]);
        removeItem(bagArray[i]);
      }
    }
    return newBag;
  }

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
};

#endif