#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// Global MACROS
#define MEMORY 5
#define MAX_WORD_LENGTH 15

// Global variables
int numberOfWords = 0;
int mode = 0;

// Global DoublyLinkedLists
struct DoublyLinkedList* head = NULL;
struct DoublyLinkedList* link = 0;

// struct for DoublyLinkedList
struct DoublyLinkedList
{
  char * word; // word to memorize
  int frequency; // frequency of a given word (used for mode 2)
  struct DoublyLinkedList* next;
  struct DoublyLinkedList* prev;
};
