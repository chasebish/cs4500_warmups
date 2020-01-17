#include <stdlib.h>
#include <stdio.h>
#include "sorted.h"

void FAIL(const char* m) {
  fprintf(stderr, "test %s failed\n", m);
  exit(1);
}
void OK(const char* m) { printf("test %s passed\n", m); }
void t_true(bool p, const char* m) { if (!p) FAIL(m); }
void t_false(bool p, const char* m) { if (p) FAIL(m); }

void test1() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  t_true(s->equals(s), "1a");
  t_false(s->equals(t), "1b");
  t_false(s->equals(u), "1c");
  t_true(s->hash() == s->hash(), "1d");
  t_true(strcmp(u->value, "HelloWorld") == 0, "1e");
  delete u;
  delete t;
  delete s;
  OK("1");
}

void test2() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  t_true(l->get(0)->equals(s), "2a");
  delete l;
  delete u;
  delete t;
  delete s;
  OK("2");
}

void test3() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  SortedStrList * l2 = new SortedStrList();
  l2->sorted_add(s);
  l2->sorted_add(t);
  l2->sorted_add(u);
  t_true(l->equals(l2), "3a");
  t_true(l2->equals(l), "3b");
  t_true(l->hash() == l2->hash(), "3c");
  delete l2;
  delete l;
  delete t;
  delete u;
  delete s;
  OK("3");
}

void test4() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  SortedStrList * l2 = new SortedStrList();
  l2->add_all(0, l);
  t_true(l->size() == l2->size(), "4a");
  delete l2;
  delete l;
  delete u;
  delete t;
  delete s;
  OK("4");
}

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}