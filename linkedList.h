#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#define TYPE int

/* Single link structure */
struct Link {
  TYPE value;
  struct Link* next;
};

// Dr. Hess wrote these two
struct Link* buildLink(int n, int rev, int mod);
void printLL(struct Link* l,char* s);

// I wote these
void freeLink(struct Link* l);

struct Link* appendLink(struct Link* l, TYPE data);
struct Link* removeLink(struct Link* l, TYPE data);

struct Link* listInsertionSort(struct Link* head);
struct Link* reverseList(struct Link* head);
struct Link* reverseListRecursive(struct Link* head);

#endif
