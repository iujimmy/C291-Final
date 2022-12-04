all:
	echo "Making Program..."
	gcc main.c MergeSort.c HelperFunctions.c MemoryGame
	./MemoryGame
