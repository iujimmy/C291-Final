// Header Files
#include "MergeSort.h"
#include "HelperFunctions.h"
#include "Defs.h"

int main(){
  // scanf the mode which is a global variable
  printf("Please enter mode: ");
  scanf("%d%*c", &mode);

  // scanf for numberOfWords
  printf("Please enter number of words to be stored: ");
  scanf("%d%*c", &numberOfWords);

  // 2d char array that uses numberOfWords as total words and MAX_WORD_LENGTH as
  // word length for each individual word
  char words[numberOfWords][MAX_WORD_LENGTH];

  // for loop that fgets the words and adds it to the memory
  for(int i = 0; i < numberOfWords; i++)
  {
    printf("Please enter word %d: ", i+1);
    // fgets doesn't stops at space character unlike scanf
    fgets(words[i], 15, stdin);
    words[i][strcspn(words[i], "\r\n")] = 0; // removes newline character
    addWordToMemory(words[i], mode);

    // last moment mergesort to make sure the DoublyLinkedList is updated.
    if(i == numberOfWords - 1)
    {
      mergesort(&head);
    }
    // prints out each updated DoublyLinkedList
    printMemoryQueue();

  }

}
