/********************************************************************
 * sort.cpp
 ********************************************************************/
#include <iostream>
#include "sort.h"

using namespace std;

/********************************************************************
* This function displays the initial array for the user
********************************************************************/
void Sort :: arrayDisplay(int arr[], int size)
{
	cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i] << " ";
		else
			cout << arr[i] << ", ";
	}
	cout << "}\n\n";
}

void Sort :: swap(int * a, int * b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
	swaps++;
}

void Sort :: loopDisplay()
{
	cout << "<---------------------->\n";
	cout << "   Loop Count: " << loops << endl;
	cout << "   Swap Count: " << swaps << endl;
	cout << "   Total:      " << (loops + swaps) << endl;
	cout << "<---------------------->\n";
}

/*******************************************************************
* Binary Insertion Sort OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
*******************************************************************/
void Sort :: bis(int arr[], int size)
{
	cout << "Binary Insertion Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Bitonic Sort : Close to done
********************************************************************/
void Sort :: bs(int arr[], int size)
{
	cout << "Bitonic Sort\n\n";

	arrayDisplay(arr, size);


	// Initiate full sort loop
	// Start with 2 and continue to increase by power of 2
	
	// 1) 1,2 min-max -> 3,4 max-min

	// 2) 1,3 2,4 min-max -> 5,7 6,8 max-min

	// 1) 1,2 3,4 min-min -> 5,6 7,8 max-min

	// 4) 1,5 2,6 3,7 4,8 min-max -> 9,13 10,14 11,15 12,16 max-min

	// 2) 1,3 2,4 5,7 6,8 min-max -> 9,11 10,12 13,15 14,16 max-min

	// 1) 1,2 3,4 5,6 7,8 min-max -> 9,10 11,12 13,14 15,16 max-min

	// And so on, "x)" represents the power starting from 1, then 2 in base 2
	// If the array is 16 intigers long, the sequence will be...
	// 1   2->1   4->2->1   8->4->2->1   16->8->4->2->1 

	int i = 0;               // index
	int step = 1;            // incriments by power of 2
	int count = 1;           // determines number of times an action occured
	int power = 1;           // Shows what poer of 2 it is
	bool turn = false;
	bool done = false;
	bool first = true;


	while (!done)
	{
		do
		{
			if (count > step)
			{
				turn = !turn;
				count = 1;
				first = true;
			}

			if (turn)
			{
				if (first)
				{
					first = false;
					i += step;
				}
				if (arr[i] > arr[i + power])
					swap(&arr[i], &arr[i + power]);
			}
			else
			{
				if (first)
				{
					first = false;
					i += step;
				}
				if (arr[i] < arr[i + power])
					swap(&arr[i], &arr[i + power]);
			}

			count++;
			if (step == 1)
				i += step + 1;
			else
				i += step;

			if (i > (size - 1) && power != 1)
			{
				power = (power / 2);
				i = 0;
			}
			loops++;
		} while (power > 1 || i <= (size - 1));
		if (step == size)
			done = true;

		step *= 2;
		power = step;
		count = 1;
		turn = true;
		i = 0;
		arrayDisplay(arr, size);
	}

	// Last rearrange stage (where the power is equal to the size of the array)

	i = 0;
	count = (size / 2);
	int count2 = 1; 
	first = false;
	bool cycle = false;

	while (count >= 1)
	{
		if (cycle == true)
		{
			first = true;

		}

		if (arr[i] > arr[i + count])
		{
			swap(&arr[i], &arr[i + count]);
		}

		
		if ((i + count) >= (size - 1))
		{
			i = 0;
			count = (count / 2);
			count2 *= 2;
			cycle = true;
		}
		else
			i++;

		arrayDisplay(arr, size); loops++;
	}
	loopDisplay();
	
}

/********************************************************************
* BogoSort or Permutation Sort XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
********************************************************************/
void Sort :: bps(int arr[], int size)
{
	cout << "BogoSort or Permutation Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Bubble Sort : Done
********************************************************************/
void Sort :: bubble(int arr[], int size)
{
	cout << "Bubble Sort\n\n";

	// Sift through array and swap number to the right if it is less
	// than number to the left.
	int count = 0;   // counter to judge if array is fully sorted
	while (count < size)
	{	
		arrayDisplay(arr, size); loops++;
		for (int i = 0; i < (size - 1); i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				count = 0;
			}
			count++;
		}
	}
	loopDisplay();
}

/********************************************************************
* Bucket Sort XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
********************************************************************/
void Sort :: bucket(int arr[], int size)
{
	cout << "Bucket Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Cartesian Tree Sorting ??????????????????????????????????????????
********************************************************************/
void Sort :: cts(int arr[], int size)
{
	cout << "Cartesian Tree Sorting\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Cocktail Sort: Done
********************************************************************/
void Sort :: cs(int arr[], int size)
{
	cout << "Cocktail Sort\n\n";

	arrayDisplay(arr, size);

	bool done;

	while (!done)
	{
		done = true;
		// Sift through starting from the left side, shift numbers left
		// if less than number to right.
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				done = false;
			}
			loops++;
		}

		// Sift through starting from the right side, shift numbers right 
		// of greater than number to left.
		for (int j = size - 1; j > 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(&arr[j - 1], &arr[j]);
				done = false;
			}
			loops++;
		}
		arrayDisplay(arr, size);
	}
	loopDisplay();
}

/********************************************************************
* Comb Sort: Done
********************************************************************/
void Sort :: comb(int arr[], int size)
{
	cout << "Comb Sort\n\n";

	arrayDisplay(arr, size);

	bool done = false;
	int index = size / 1.3;
 	
 	// Start with the size of the array and devide by 1.3, the answer
 	// is what the numbers will be sorted by. After a full cycle 
 	// through array, devide by 1.3 again, and contine until vale is 
 	// 1.
	while (!done)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + index] && (i + index) < (size))
			{
				swap(&arr[i], &arr[i + index]);
				done = false;
			}
			loops++;
		}
		if (index == 1)
			done = true;
		index = index / 1.3;
		arrayDisplay(arr, size);
		loops++;
	}
	loopDisplay();
}

/********************************************************************
* Counting Sort
********************************************************************/
void Sort :: count(int arr[], int size)
{
	cout << "Counting Sort\n\n";

	arrayDisplay(arr, size);

	// Find highest value in array and base all future arrays on it's size
	int max = 0;
	for (int z = 0; z < size; z++)
	{
		if (arr[z] > max)
			max = arr[z];
	}

	// Replace size if needed
	if (max > size)
		size = max - 1;

	// Create a new array with the same size
	int arr2[size];

	// Populate new array with each index for display purposes
	for (int i = 0; i <= size; i++)
	{
		arr2[i] = i;
	}
	arrayDisplay(arr2, size);

	// Populate new array with zeros.
	for (int i = 0; i <= size; i++)
	{
		arr2[i] = 0;
	}

	// // Fill array with total for each number in origonal array according
	// // to it's slot in the array i.e. arr {1,(4),3,5,(4)} -> arr2[4] = 2.
	for (int j = 0; j < size; j++)
	{
		arr2[arr[j]] += 1; loops++;
	}
	arrayDisplay(arr2, size);

	// Add all numbers up in arr2 going from left to right.
	// Create another array to hold totals
	int arrTot[size];
	int tot = 0;
	for (int k = 0; k < size; k++)
	{
		tot += arr2[k];
		arrTot[k] = tot; loops++;
	}
	arrayDisplay(arrTot, size);
	
	// Create a third array for the sorted answer
	int arr3[size];

	// Populate new array with zeros.
	for (int i = 0; i <= size; i++)
	{
		arr3[i] = 0;
	}
	
	// Go back through first array, where that number is found as
	// an index in the second array, take that index value and use
	// it as the index to store the origonal number in the third array.
	// i.e store "4" in the second slot of the answer array starting
	// from 0 -> 1,3,(4),4,5
	for (int l = 0; l < size; l++)
	{
		arr3[arrTot[arr[l]]-1] = arr[l];   // Got "-1" from Geeks for Geeks
		--arrTot[arr[l]];                  // Got "--" before index from GfG
		loops++;
	} 

	// Sort through array to remove zeros
	int arrAns[size];
	int index = 0;
	for (int x = 0; x < size; x++)
	{
		if (arr3[x] > 0)
		{
			arrAns[index] = arr3[x];
			index++;
		}
		loops++;
	}

	arrayDisplay(arrAns, index - 1);
	loopDisplay();
}

/********************************************************************
* Cycle Sort
********************************************************************/
void Sort :: cycle(int arr[], int size)
{
	cout << "Cycle Sort\n\n";

	arrayDisplay(arr, size);

	// Sort through array
	int i = 0;
	while (i < size)
	{
		// If the index is larger than the one to the left, keep going
		// If the index is smaller, swap them and go back one index
		if (i + 1 <= size && arr[i] > arr[i + 1])
		{
			swap(&arr[i], &arr[i + 1]);
			arrayDisplay(arr, size);
			if (i > 0)
				i--;
		}
		else
			i++;
		loops++;
	}
	loopDisplay();
}

/********************************************************************
* Gnome Sort
********************************************************************/
void Sort :: gs(int arr[], int size)
{
	cout << "Gnome Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Heap Sort
********************************************************************/
void Sort :: hs(int arr[], int size)
{
	cout << "Heap Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Insertion Sort 
********************************************************************/
void Sort :: is(int arr[], int size)
{
	cout << "Insertion Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Iterative Merge Sort
********************************************************************/
void Sort :: ims(int arr[], int size)
{
	cout << "Iterative Merge Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Iterative Quick Sort
********************************************************************/
void Sort :: iqs(int arr[], int size)
{
	cout << "Iterative Quick Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Merge Sort
********************************************************************/
void Sort :: ms(int arr[], int size)
{
	cout << "Merge Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Merge Sort for Doubly Linked List
********************************************************************/
void Sort :: msdl(int arr[], int size)
{
	cout << "Merge Sort for Doubly Linked List\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Merge Sort for Linked Lists
********************************************************************/
void Sort :: msll(int arr[], int size)
{
	cout << "Merge Sort for Linked Lists\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Odd-Even Sort / Brick Sort
********************************************************************/
void Sort :: oesbs(int arr[], int size)
{
	cout << "Odd-Even Sort / Brick Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Pancake Sorting 
********************************************************************/
void Sort :: pan(int arr[], int size)
{
	cout << "Pancake Sorting\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Pigeonhole Sort
********************************************************************/
void Sort :: ps(int arr[], int size)
{
	cout << "Pigeonhole Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Quick Sort
********************************************************************/
void Sort :: qs(int arr[], int size)
{
	cout << "Quick Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* QuickSort on Doubly Linked List
********************************************************************/
void Sort :: qdll(int arr[], int size)
{
	cout << "QuickSort on Doubly Linked List\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* QuickSort on Singly Linked List
********************************************************************/
void Sort :: qsll(int arr[], int size)
{
	cout << "QuickSort on Singly Linked List\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Radix Sort
********************************************************************/
void Sort :: rs(int arr[], int size)
{
	cout << "Radix Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Recursive Bubble Sort
********************************************************************/
void Sort :: rbs(int arr[], int size)
{
	cout << "Recursive Bubble Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Recursive Insertion Sort
********************************************************************/
void Sort :: ris(int arr[], int size)
{
	cout << "Recursive Insertion Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Selection Sort
********************************************************************/
void Sort :: ss(int arr[], int size)
{
	cout << "Selection Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Shell Sort 
********************************************************************/
void Sort :: shell(int arr[], int size)
{
	cout << "Shell Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Sleep Sort
********************************************************************/
void Sort :: sleep(int arr[], int size)
{
	cout << "Sleep Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Stooge Sort
********************************************************************/
void Sort :: stooge(int arr[], int size)
{
	cout << "Stooge Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Strand Sort 
********************************************************************/
void Sort :: strand(int arr[], int size)
{
	cout << "Strand Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Structure Sorting
********************************************************************/
void Sort :: structure(int arr[], int size)
{
	cout << "Structure Sorting\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Tag Sort
********************************************************************/
void Sort :: tag(int arr[], int size)
{
	cout << "Tag Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Tim Sort
********************************************************************/
void Sort :: tim(int arr[], int size)
{
	cout << "Tim Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* Tree Sort
********************************************************************/
void Sort :: tree(int arr[], int size)
{
	cout << "Tree Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* 3-way Merge Sort
********************************************************************/
void Sort :: wms(int arr[], int size)
{
	cout << "3-way Merge Sort\n\n";

	arrayDisplay(arr, size);
}

/********************************************************************
* 3-Way QuickSort
********************************************************************/
void Sort :: wq(int arr[], int size)
{
	cout << "3-Way QuickSort\n\n";

	arrayDisplay(arr, size);
}	