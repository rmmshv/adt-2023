/* *~*~*
Implementation file for the Heap class: min- or max-heap of integers
Written By: A. Student
Changed by: Rimma Esheva
IDE:  VS Code
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx, int compare(int, int))
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parent = _findParent(lastndx);
		while (parent != -1 && compare(heapAry[lastndx], heapAry[parent]) < 0)
		{
			int temp = heapAry[lastndx];
			heapAry[lastndx] = heapAry[parent];
			heapAry[parent] = temp;

			lastndx = parent;
			parent = _findParent(lastndx);
		}
	}
}


/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootndx, int compare(int, int))
{
	int left = _findLeftChild(rootndx);
	if (left != -1) // if there's a left child
	{
		int right = _findRightChild(rootndx);
		int smallerChild = left;

		if (right != -1 && compare(heapAry[right], heapAry[left]) < 0)
			smallerChild = right;

		if (compare(heapAry[smallerChild], heapAry[rootndx]) < 0)
		{
			int temp = heapAry[rootndx];
			heapAry[rootndx] = heapAry[smallerChild];
			heapAry[smallerChild] = temp;

			_reHeapDown(smallerChild, compare);
		}
	}
}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int itemIn, int compare(int, int))
{
	if (isFull())
		return false;

	heapAry[count] = itemIn;
	_reHeapUp(count, compare);
	count++;

	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &itemOut, int compare(int, int))
{
	if (isEmpty())
		return false;

	itemOut = heapAry[0];
	count--;
	heapAry[0] = heapAry[count];
	_reHeapDown(0, compare);

	return true;
}