#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Link* buildLink(int n, int rev, int mod) {
  struct Link* head = (struct Link*)malloc(sizeof(struct Link));
  struct Link* cur = head;

  for (int i = 0; i < n; i++) {
    if (rev)
      cur->value = n - i - 1;
    else
      cur->value = i;

    if (mod)
      cur->value = cur->value % mod;

    if (i + 1 < n)
      cur->next = (struct Link*)malloc(sizeof(struct Link));
    else
      cur->next  = 0;
    cur = cur->next;
  }

  return head;
}
void printLL(struct Link* l,char* s) {
  printf("LL %s: ",s);
  while (l != 0) {
    printf("%d ", l->value);
    l = l->next;
  }
  printf("\n");
}

void freeLink(struct Link* l) {
  if (l == NULL) {
    return;
  }
  freeLink(l->next);
  free(l);
}

struct Link* appendLink(struct Link* l, TYPE data) {
  struct Link* cur = l;
  struct Link* new_link = (struct Link*)malloc(sizeof(struct Link));
  new_link->value = data;
  new_link->next = 0;

  if (cur == 0) {
    return new_link;
  }

  while (cur->next != 0) {
    cur = cur->next;
  }
  cur->next = new_link;
  return l;
}
struct Link* removeLink(struct Link* l, TYPE data) {
  struct Link* cur = l;
  struct Link* temp = NULL;

  if (cur == NULL) {
    return NULL;
  } else if (cur->value == data) {
    temp = cur->next;
    free(cur);
    return temp;
  }

  while (cur->next != NULL && cur->next->value != data) {
    cur = cur->next;
  }
  if (cur == NULL) {
    return l;
  }

  temp = cur->next;
  cur->next = cur->next->next;
  free(temp);

  return l;
}
struct Link* listInsertionSort(struct Link* head) {

  struct Link* temp;
  struct Link* cur;
  int sorted = !head || !head->next;

  // printf("%d\n", sorted);

  while (!sorted) {
    cur = head;

    while (cur->next && cur->value <= cur->next->value) {
      cur = cur->next;
    }

    if (!cur->next) {
      sorted = 1;
    } else {
      temp = cur->next;
      // printf("link to be moved: %d\n", temp->value);
      cur->next = cur->next->next;

      if (temp->value <= head->value) {
        // printf("is less than head (%d): switched\n", head->value);
        temp->next = head;
        head = temp;
      } else {
        cur = head;

        while (cur->next && temp->value > cur->next->value) {
          cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
      }
    }
  }

  return head;

}


struct Link* reverseList(struct Link* head) {
  struct Link* nextNode = NULL;
  struct Link* curNode = head;
  struct Link* prevNode = NULL;

  while (curNode) {
    nextNode = curNode->next;
    curNode->next = prevNode;
    prevNode = curNode;
    curNode = nextNode;
  }
  head = prevNode;

  /*
   * This function should iteratively reverse the list whose head is provided
   * as the function's argument.
   *
   * The reversal must be done totally in place, i.e. you may not allocate any
   * new Link structs or any other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
  return head;

}


struct Link* reverseListRecursive(struct Link* head) {

  struct Link* cur = head;

  if (cur && cur->next) {
    head = reverseListRecursive(cur->next);
    cur->next->next = cur;
    cur->next = NULL;
  }

  /*
   * Write this function for extra credit.  It should do the exact same thing
   * as reverseList() above, except it should do it recursively instead of
   * iteratively (i.e. no loops allowed).
   *
   * Again, you may not allocate any new Link structs or any other auxiliary
   * data structures.  You may, however, define an auxiliary function to help
   * you do the recursion.
   *
   * Return a pointer to the new head of the list.
   */

  return head;
}
