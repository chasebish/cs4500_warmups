#include <string.h>
#include "object.h"

/**
 * String
 * An Object representing a String and its value
 * 
 * @author Chase <bishop.c@husky.neu.edu>
 */
class String : public Object {
  public:
    char* value;

    String(const char* str) {
      value = new char[strlen(str) + 1];
      strcpy(value, str);
    };

    // concatenate two String
    String* concat(String* str) {
      char concatStr[strlen(value) + 1];
      strcpy(concatStr, value);
      strcat(concatStr, str->value);
      return new String(concatStr);
    };

    // generate hash based on ASCII values
    size_t hash() {
      int hash = 0;
      for(int i = 0; i < strlen(value); i++) {
        hash += (int)value[i];
      }
      return hash;
    };

    // compare string equality
    bool equals(Object* o) {
      String* castedString = dynamic_cast<String*>(o);
      if (castedString == NULL) {
        printf("Cannot compare null");
        exit(-1);
      }
      return strcmp(value, castedString->value) == 0;
    };

    virtual ~String() {
      delete value;
    }
};
