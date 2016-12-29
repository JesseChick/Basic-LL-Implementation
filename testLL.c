#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

int main() {
  // create list of 8 elements in ascending order
  struct Link* l = buildLink(8, 0, 0);
  printLL(l, "Original list");

  l = appendLink(l, 9);
  printLL(l, "9 appended");

  l = reverseList(l);
  printLL(l, "Reversed iteratively");

  l = listInsertionSort(l);
  printLL(l, "Insertion sort perfomed");

  l = reverseListRecursive(l);
  printLL(l, "Reversed recursively");

  l = removeLink(l, 4);
  printLL(l, "4 removed");

  freeLink(l);
}
