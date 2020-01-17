#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

class StrList : public Object {
  public:
    // the total size of the array (increased in multiples of 8)
    size_t currentSize;
    // the current last index of the array
    size_t length;
    // the data stored in the array
    String** list;

    StrList() {
      currentSize = 8;
      length = 0;
      list = new String*[currentSize]; 
    };
    ~StrList() {
      delete list;
    };

    // increase the size of the array if we are at capacity
    void _increase_size(size_t newLength) {
      bool copyList = false;
      while (currentSize - 1 <= newLength) {
        currentSize = currentSize * 2;
        copyList = true;
      }
      if (copyList) {
        String** newList = new String*[currentSize];
        for (int i = 0; i < length; i++) {
          newList[i] = list[i];
        }
        delete [] list;
        list = newList;
      }
    };

    // Appends e to end
    void push_back(String* e) {
      if(e == NULL) {
        exit(-1);
      }
      _increase_size(length);
      list[length] = e;
      length++;
    };

    // Inserts e at i
    void add(size_t insert, String* e) {
      if(e == NULL) {
        exit(-1);
      }
      if(insert > length) {
        printf("Cannot be inserted at index greater than length.\n");
        exit(-1);
      }
      _increase_size(length);
      String** newList = new String*[currentSize];
      for (int i = 0; i < insert; i++) {
        newList[i] = list[i];
      }
      newList[insert] = e;
      length++; // increment length since we have added new String
      for (int i = insert + 1; i < length; i++) {
        newList[i] = list[i - 1];
      }
      delete [] list;
      list = newList;
    };

    // Inserts all of elements in c into this list at i
    void add_all(size_t insert, StrList* c) {
      if(c == NULL) {
        exit(-1);
      }
      if(insert > length) {
        printf("Cannot be inserted at index greater than length.\n");
        exit(-1);
      }
      _increase_size(length + c->length);
      String** newList = new String*[currentSize];
      for (int i = 0; i < insert; i++) {
        newList[i] = list[i];
      }
      for (int i = 0; i < c->length; i++) {
        newList[insert + i] = c->list[i];
      }
      length = length + c->length; // increment length since we have added new String
      for (int i = insert + c->length; i < length; i++) {
        newList[i] = list[i - c->length];
      }
      delete [] list;
      list = newList;
    };

    // Removes all of elements from this list
    void clear() {
      for (int i = 0; i < length; i++) {
        list[i] = 0;
      }
      length = 0;
    };

    // Compares o with this list for equality.
    bool equals(Object* o) {
      StrList* castedList = dynamic_cast<StrList*>(o);
      if (castedList == NULL) {
        printf("Cannot compare nullptr");
        exit(-1);
      }
      return castedList->hash() == hash();
    };

    // Returns the element at index
    String* get(size_t index) {
      return list[index];
    };

    // Returns the hash code value for this list.
    size_t hash() {
      size_t hash = 0;
      for (int i = 0; i < length; i++) {
        // multiply by a prime number for each hash added
        hash = hash * 31 + list[i]->hash();
      }
      return hash;
    };

    // Returns the index of the first occurrence of o, or >size() if not there
    size_t index_of(Object* o) {
      if(o == NULL) {
        exit(-1);
      }
      for (int i = 0; i < length; i++) {
        if (o->hash() == list[i]->hash()) {
          return i;
        }
      }
      // return range greater than size if not found
      return size() + 1;
    };

    //Removes the element at i
    String* remove(size_t rm) {
      if (rm >= length) {
        printf("Cannot be removed at index greater than or equal to length.\n");
        exit(-1);
      }
      String* toDelete = list[rm];
      String** newList = new String*[currentSize];
      for (int i = 0; i < rm; i++) {
        newList[i] = list[i];
      }
      length--; // decrement length for removed String
      for (int i = rm; i < length; i++) {
        newList[i] = list[i + 1];
      }
      delete [] list;
      list = newList;
      return toDelete;
    };

    // Replaces the element at i with e
    String* set(size_t insert, String* e) {
      if(e == NULL) {
        exit(-1);
      }
      if (insert >= length) {
        printf("Cannot be insert at index greater than or equal to length.\n");
        exit(-1);
      }
      String* toReplace = list[insert];
      list[insert] = e;
      return toReplace;
    };

    // Return the number of elements in the collection
    size_t size() {
      return length;
    };

    // helper to print out a list
    void print() {
      printf("\n**PRINTING LIST**\n");
      printf("List length: %lu\n", length);
      for (int i = 0; i < length; i++) {
        printf("%s\n", list[i]->value);
      }
      printf("\n");
    }
};
