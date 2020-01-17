#include <string.h>
#include <stdio.h>
#include "list.h"

class SortedStrList : public StrList {

  public:
    // selection sort implementation
    void _sort() {
      if (length <= 1) {
        return;
      }
      for (int i = 0; i < length; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
          int compared = _compare(list[minIndex], list[j]);
          if (compared >= 1) {
            minIndex = j;
          }
        }
        String* temp = list[i];
        list[i] = list[minIndex];
        list[minIndex] = temp;
      }
    };

    // comparator for ordering list
    int _compare(String* x, String* y) {
      return strcmp(x->value, y->value);
    };

    // adds a string in sorted order
    void sorted_add(String* e) {
      if(e == NULL) {
        exit(-1);
      }
      push_back(e);
      _sort();
    };

    // push String on and sort
    void push_back(String* e) {
      StrList::push_back(e);
      _sort();
    };

    // add String and sort
    void add(size_t insert, String* e) {
      StrList::add(insert, e);
      _sort();
    };

    // add all Strings and sort
    void add_all(size_t insert, StrList* c) {
      StrList::add_all(insert, c);
      _sort();
    };

    // set new value for String and sort
    String* set(size_t insert, String* e) {
      String* returnValue = StrList::set(insert, e);
      _sort();
      return returnValue;
    };

};