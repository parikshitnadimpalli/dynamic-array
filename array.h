#include <iostream>
#include <string>
#include <limits>
/*
NOTE: All the constructor/method definitions in the array.cpp file are in the same order as the function declarations here
*/
class Array {

	int *arr;
	int len;
	int capacity;
public:
	Array();     // 2 constructors to initialise different values
	Array(int);

	int size() { return len; } // One line declarations of methods can be done in the header file itself
	bool isEmpty() { return size() == 0; } // Checks if the array is empty or not
	bool outOfBounds(int); // Returns true if the given index is more than the size of the array

	int get(int); // Returns a value from the array
	void set(int, int); // Changes the value of an element of the array at the given index
	
	void clear(); // Deletes older array
	void add(int); // Appends a value to the array (adds a value to the end)
	int removeAt(int); // Removes a value at the provided index
	bool remove(int); // Checks if a value exists in the array. If does, it will remove it from the array and return true. Otherwise it will return false.
	int indexOf(int); // Returns the index of a given value in the array. Returns -1 if the value is not in the array.
	bool contains(int elem) { return indexOf(elem) != -1; } // Checking to see if the previous function has returned -1 or not.
	// TODO: Call the following 2 functions in a function containing a loop to use them for all the elements of the array
	bool hasNext(int index) { return index < len; } // Checks to see if the given index is at the end of the array or not
	int next(int index) { return arr[index++]; } // Returns the next element of the array

	std::string toString(); // Returns the entire array in a string format
};

int getInput(); // Function to only take integer values as input