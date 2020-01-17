#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "list.h"

/**
 * SortedStrList
 * Maintains a sorted list of Strings
 * 
 * @author Chase <bishop.c@husky.neu.edu>
 */
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

    // take in a string of characters and separate them
    // only accepts valid characters a -> z
    void _order_words(const char* words) {
      for (int i = 0; i < strlen(words); i++) {
        char * str = new char[256];
        size_t strLen = 0;
        while (isalpha(words[i])) {
          str[strLen] = tolower(words[i]);
          i++;
          strLen++;
        }
        str[strLen] = '\0';
        if (strLen > 0) {
          String * newStr = new String(str);
          _normal_add(newStr);
        }
        for (int i = 0; i < strLen; i++) {
          str[i] = '\0';
        }
        delete [] str;
      }
    };

    // filter words with length <= 3
    void _filter_words(const char* words) {
      _order_words(words);
      int i = 0;
      while (i < length) {
        if (strlen(list[i]->value) <= 3) {
          remove(i);
        } else {
          i++;
        }
      }
    }

    /**
     * Count all the words in a string with a length greater than 3
     * Print out the result in descending order by number of appearances
     */
    void count_words(const char* words) {
      _filter_words(words);
      _sort();
      String * last;
      StrList * tempList = new StrList();
      int counter[length];
      int count = 0;

      for (int i = 0; i < length; i++) {
        if (i == 0) {
          last = list[i];
          count = 1;
        } else if (last->equals(list[i])) {
          count++;
        } else {
          counter[tempList->length] = count;
          tempList->push_back(new String(last->value));
          last = list[i];
          count = 1;
        }
      }
      if (length > 0) {
        counter[tempList->length] = count;
        tempList->push_back(new String(last->value));

        for (int i = 0; i < tempList->length - 1; i++) {
          int minIndex = i;
          for (int j = i + 1; j < tempList->length; j++) {
            // sort descending
            int compared = counter[j] - counter[minIndex];
            if (compared >= 1) {
              minIndex = j;
            }
          }
          String * tempStr = tempList->get(i);
          int tempCount = counter[i];
          tempList->set(i, tempList->get(minIndex));
          counter[i] = counter[minIndex];
          tempList->set(minIndex, tempStr);
          counter[minIndex] = tempCount;
        }
      }

      // now sort counter and tempList at the same time
      for (int i = 0; i < tempList->length; i++) {
        printf("%s %d\n", tempList->get(i)->value, counter[i]);
      }

      // clear temp list
      for (int i = 0; i < tempList->length; i++) {
        delete tempList->list[i];
      }
      delete tempList;
    }

    // if order_words is called, this should be called as well to delete any new Strings created
    void clear_created_words() {
      for (int i = 0; i < length; i++) {
        delete list[i];
        list[i] = NULL;
      }
      length = 0;
    }

    // push_back call without sorting
    void _normal_add(String* e) {
      if (e == NULL) {
        exit(-1);
      }
      StrList::push_back(e);
    }

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