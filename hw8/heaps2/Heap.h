/* *~*~*
Specification file for the Heap class: min-heap of integers
Written By: A. Student
Changed by: Rimma Esheva
IDE: VS Code
*~**/

#ifndef HEAP_H_
#define HEAP_H_

class Heap
{
private:
	int* heapAry;
	int heapSize;
	int count;

	void _reHeapUp(int lastndx);
	void _reHeapDown(int rootndx);
	int _findParent(int index) { return (index <= 0) ? (-1) : (index - 1) / 2; }
	int _findLeftChild(int index) { return (2 * index + 1 >= count) ? (-1) : (2 * index + 1); }
	int _findRightChild(int index) { return (2 * index + 2 >= count) ? (-1) : (2 * index + 2); }

public:
	Heap() { count = 0; heapSize = 128; heapAry = new int[heapSize]; }
	Heap(int n) { count = 0; heapSize = n;	heapAry = new int[heapSize]; }
	~Heap() { delete[] heapAry; }

	int getCount() const { return count; }
	int getSize() const { return heapSize; }
	bool isEmpty() const { return count == 0; }
	bool isFull()  const { return count == heapSize; }
	bool insertHeap(int itemIn);
	bool deleteHeap(int &itemOut);
};

#endif

