#pragma once
#include "Defs.h"
#include "MergeSort.h"

// Function to search for a word in the DoublyLinkedList
bool searchWordInMemory(char * targetWord);
void addWordToMemory(char * word, int mode);
void split(struct DoublyLinkedList* head, struct DoublyLinkedList** a, struct DoublyLinkedList** b);
void printMemoryQueue();
