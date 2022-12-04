#include "Defs.h"
#include "MergeSort.h"

// Function to search for a word in the DoublyLinkedList
bool searchWordInMemory(char * targetWord)
{
  int found = 0;
  // uses the temporary DoublyLinkedList link to check for a word without
  // disturbing the main DoublyLinkedList head.
  link = head;
  // loop through the DoublyLinkedList to check for word
  while(link != NULL)
  {
    if(strcmp(link->word, targetWord) == 0)
    {
      // returns 1 if true and forces the loop to stop
      found = 1;
      break;
    }
    else
    {
      // continues until the targetWord is found or end of the DoublyLinkedList
      link = link->next;
    }
  }
  if(found == 1)
  {
    return true;
  }
  if(found == 0)
  {
    return false;
  }
  return 0;
}

// It splits the DoublyLinkedList into two seperate list which can also be split // further (used for mergesort)
void split(struct DoublyLinkedList* head, struct DoublyLinkedList** a, struct DoublyLinkedList** b)
{
    struct DoublyLinkedList* slow = head;
    struct DoublyLinkedList* fast = head->next;

    // advance DoublyLinkedList fast by two lists, and advance DoublyLinkedList       // slow by a single list
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *b = slow->next;
    slow->next = NULL;
}


void addWordToMemory(char * word, int mode)
{
  // if statement for when mode = 1
  if(mode == 1)
  {
    // allocates memory using malloc
    struct DoublyLinkedList * newList = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    // creates the newList
    newList->word = word;
    newList->frequency = 0;

    // if statement for what happens when head is NULL
    if(head == NULL)
    {
      head = newList;
      return;
    }

    // declares the head and next
    head->prev = newList;
    newList->next = head;
    head = newList;
    return;
  }
  if(mode == 2)
  {
    // allocates memory using malloc
    struct DoublyLinkedList * newList = (struct       DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    // if statement for if word exist in DoublyLinkedList already
    if(searchWordInMemory(word) == true)
    {
      // printf("Found the word");
      link->frequency = link->frequency + 1;
      mergesort(&head);
    }
    // if statement for word that doesn't exit which means it will create a new
    // DoublyLinkedList for it
    if(searchWordInMemory(word) == false)
    {
      newList->word = word;
      newList->frequency = 0;

      if(head == NULL)
      {
        head = newList;
        return;
      }

      head->prev = newList;
      newList->next = head;
      head = newList;
      return;
    }
  }
}

void printMemoryQueue()
{
  // allocates memory for a new current DoublyLinkedList
    struct DoublyLinkedList* current = 0;
    current = head;

  // counter for MEMORY macro
    int counter = 0;
    printf("Your current memory stream: \n" );
    printf("[");
  // printing out each list
    while(current != NULL && counter < MEMORY)
    {
      printf(" \"%s\"", current->word);
      current = current->next;
      counter++;
    }
    printf(" ]");
    printf("\n");
}
