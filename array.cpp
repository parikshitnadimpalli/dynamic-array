#include "array.h"
using namespace std;

Array::Array() {

	len = 0;
	capacity = 0;
}
Array::Array(int i) {

	if (i < 0) {

		cout << endl << "Invalid capacity! Please try again: ";
		cin >> i;
		Array(i);
	}
	else {

		arr = new int(i);
		capacity = i;
	}	
}
bool Array::outOfBounds(int index) {

	if (index >= len || index < 0) {

		cout << endl << "The given index is out of bounds! Please enter a valid index: ";
		return true;
	}
	else
		return false;
}
int Array::get(int index) { 
	
	if (outOfBounds(index)) {
		
		index = getInput();
		get(index);
	}
	else
		return arr[index]; 
}
void Array::set(int index, int elem) {

	if (outOfBounds(index)) {
		
		index = getInput();
		set(index, elem);
	}
	else
		arr[index] = elem;
}
void Array::clear() {

	for (int i = 0; i < capacity; i++) {

		arr[i] = NULL;
	}
	len = 0;
}
void Array::add(int elem) {
	// Time to resize the array if the new element if the length reaches the end of the array
	if ((len + 1) >= capacity) {

		if (capacity == 0)
			capacity = 1;
		else
			capacity *= 2;
		int *newArr = new int(capacity);
		for (int i = 0; i < len; i++) {

			newArr[i] = arr[i];
		}
		arr = newArr;
	}
	arr[len++] = elem;
}
int Array::removeAt(int index) {

	if (outOfBounds) {
		index = getInput();
		removeAt(index);
	}
	int data = arr[index];
	int* newArr = new int(index);
	for (int i = 0, j = 0; i < len; i++, j++) {

		if (i == index)
			j--;
		else
			newArr[j] = arr[i];
	}
	arr = newArr;
	capacity = --len;
	return data;
}
bool Array::remove(int elem) {

	for (int i = 0; i < capacity; i++) {

		if (arr[i] == elem) {

			removeAt(i);
			return true;
		}		
	}
	return false;
}
int Array::indexOf(int elem) {

	for (int i = 0; i < capacity; i++) {

		if (arr[i] == elem)
			return i;
	}
	return -1;
}
string Array::toString() {
	
	if (len == 0)
		return "[]";
	else {

		string s = "\n[ ";
		for (int i = 0; i < len - 1; i++) {

			s += (arr[i] + ", ");
		}
		return s + "]";
	}
}

int getInput() {

	int n;

	while (!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << "Invalid Input! Please try again with correct input: ";
	}

	return n;
}