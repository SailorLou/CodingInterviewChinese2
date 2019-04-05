#pragma once 

#include<stdlib.h >


namespace Heap
{
	// Heap is acutally a prorith queue,
	// fetch data according priority value instead of enquue order
	// which contains:
	//     max heap in which each node is biggest value among its left and right sub tree
	//     min heap in which each node is smallest value among its left and right sub tree

	// use complete binary tree to express Heap

	typedef int ElementType;

	const ElementType c_maxData = 90000;
	const ElementType c_minData = -90000;

	typedef struct HeapStruct
	{
		ElementType *elements;// store heap elements
		int size;     // current size
		int capacity; // maximum capacity
	} *MinHeap,*MaxHeap;

	namespace Max
	{
		MaxHeap Create(int maxSize)
		{
			MaxHeap maxHeap = (MaxHeap)malloc(sizeof(HeapStruct));

			maxHeap->elements = (int*)malloc(sizeof(int)*maxSize);
			maxHeap->size = 0;
			maxHeap->capacity = maxSize;

			maxHeap->elements[0] = c_maxData;//defineed as sentry to later fast operation

			return maxHeap;
		}


		// T(N) = O(LOGN)

		bool IsFull(MaxHeap maxHeap)
		{
			return maxHeap->size == maxHeap->capacity;
		}

		void Insert(MaxHeap maxHeap, ElementType item)
		{
			// elements[0] has been defined as sentry
			if (IsFull(maxHeap))
			{
				printf("heap is full\n");
				return;
			}

			int i = ++maxHeap->size;//i stands for last elements from heap
			// i/2 represents paraments of node i
			for (; maxHeap->elements[i / 2] < item; i /= 2)
			{
				maxHeap->elements[i] = maxHeap->elements[i / 2];
			}

			maxHeap->elements[i] = item;
		}

		// remove one item and return corresponding value
		// should keep the structure of complete binary tree
		bool IsEmpty(MaxHeap maxHeap)
		{
			return maxHeap->size == 0;
		}

		ElementType DeleteMaX(MaxHeap maxHeap)
		{
			if (IsEmpty(maxHeap))
			{
				printf("heap is empty\n");
				return;
			}

			int parent, child;

			ElementType maxItem, temp;

			maxItem = maxHeap->elements[1];// fetch root node

			// last element
			/* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
			temp = maxHeap->elements[maxHeap->size--];

			for (parent = 1; parent * 2 <= maxHeap->size; parent = child)
			{
				child = parent * 2;// left child
				if ((child != maxHeap->size) &&
					(maxHeap->elements[child] < maxHeap->elements[child + 1]))
					child++; /* Child指向左右子结点的较大者 */

				if (temp >= maxHeap->elements[child])
					break;
				else /* 移动temp元素到下一层 */
					maxHeap->elements[parent] = maxHeap->elements[child];
			}

			maxHeap->elements[parent] = temp;

			return maxItem;
		}
	}

	namespace Min
	{
		MinHeap Create(int maxSize)
		{
			MaxHeap minHeap = (MaxHeap)malloc(sizeof(HeapStruct));

			minHeap->elements = (int*)malloc(sizeof(int)*maxSize);
			minHeap->size = 0;
			minHeap->capacity = maxSize;

			minHeap->elements[0] = c_minData;//defineed as sentry to later fast operation

			return minHeap;
		}


		// T(N) = O(LOGN)

		bool IsFull(MinHeap minHeap)
		{
			return minHeap->size == minHeap->capacity;
		}

		void Insert(MinHeap minHeap, ElementType item)
		{
			// elements[0] has been defined as sentry
			if (IsFull(minHeap))
			{
				printf("heap is full\n");
				return;
			}

			int i = ++minHeap->size;//i stands for last elements from heap
			// i/2 represents paraments of node i
			for (; minHeap->elements[i / 2] > item; i /= 2)
			{
				minHeap->elements[i] = minHeap->elements[i / 2];
			}

			minHeap->elements[i] = item;
		}

		// remove one item and return corresponding value
		// should keep the structure of complete binary tree
		bool IsEmpty(MinHeap minHeap)
		{
			return minHeap->size == 0;
		}

		ElementType DeleteMin(MinHeap minHeap)
		{
			if (IsEmpty(minHeap))
			{
				printf("heap is empty\n");
				return;
			}

			int parent, child;

			ElementType minItem, temp;

			minItem = minHeap->elements[1];// fetch root node

			// last element
			/* 用最xiao堆中最后一个元素从根结点开始向上过滤下层结点 */
			temp = minHeap->elements[minHeap->size--];

			for (parent = 1; parent * 2 <= minHeap->size; parent = child)
			{
				child = parent * 2;// left child
				if ((child != minHeap->size) &&
					(minHeap->elements[child] > minHeap->elements[child + 1]))
					child++; /* Child指向左右子结点的较xiao者 */

				if (temp <= minHeap->elements[child])
					break;
				else /* 移动temp元素到下一层 */
					minHeap->elements[parent] = minHeap->elements[child];
			}

			minHeap->elements[parent] = temp;

			return minItem;
		}
	}


}