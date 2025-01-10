# Contents

- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)

# Bubble Sort

- It works by repeatedly `swapping adjacent elements` if they are in the wrong order.
- This process "bubbles" the largest (or smallest) element to its correct position in each pass through the list.

## Implementation

- Outer Loop
- Inner Loop
- Optimaztaion

### Outer Loop

Traverse the array from first to second last(`size-1`) element and for each iteration assume the largest unsorted element "bubbles up" to its correct position.

### Inner Loop

Compare adjacent elements. If the current element is greater than the next element, swap them.

It perform sorting from right to left, and in each iteration the from the last to last `i`th item has been sorted, so we don't need to iterate them so inner loop will continue at `size-i-1` times.

### Optimization

Outer loop doesnn't have anything with the element of the array. Inner loop compare and bubbles up the element. Outer loop is just counting the element means how much times the array needs to bubbles up(the number of time inner loop should run)

Inner loop is comparing adjacent element and bubbles up, if no perform in on outer loop iteration means the array is already sorted, so we don't need to run the outer loop again.

## Charecterstics

- **`In-Place Sorting`** - no extra memory required
- **Space Complexity:** `O(1)`
  no extra memory required
- **Time Complexity:**
  - Worst Case: O(n<sup>2</sup>) - when the list is in reverse order and requires maximum comparisons and swaps
  - Best Case: O(n<sup>2</sup>) - when the list is already sorted, and no swaps are needed in a single pass.
  - Average Case: O(n<sup>2</sup>)
- **Number of Swaps:** - In the worst-case scenario, the number of swaps performed by Bubble Sort is equal to the maximum number of inversions in the list. An inversion is a pair of elements where the earlier element is greater than the later one. In the worst case, the list is sorted in reverse order, and every element needs to be swapped into its correct position. That means we need n\*(n-1)/2 swaps
- **Number of Comparisons:**
  - first iteration it compare n-1 items
  - secont iteration it compare n-2 items
  - so total comparison is n\*(n-1)/2
- **Stability:** - It is not stable, meaning that it might change the relative order of equal elements if swapping places them differently.

## When to use

- small dataset
- memory constraint
- educational purpose

# Selection Sort

- It is a simple comparison-based sorting algorithm.
- It works by `repeatedly selecting the smallest` (or largest, depending on sorting order) element from the unsorted portion of the list and `swapping it with the first element` of the unsorted section. This process is repeated until the entire list is sorted.

## Implementation

- Outer Loop
- Inner Loop
- Swap

### Outer Loop

Traverse the array from first to second last(`size-1`) element and for each iteration assume first unsorted element is the smallest

The array is divided into two equal parts initially sorted(left) have no element and unsorted(right) have all element, in each iteration `i`th item has been sorted as it's the first element of unsorted array

### Inner Loop

It is used to find the smallest element from the unsorted portion of the array

### Swap

you have the first item from the unsorted portion of the array which is from the outer loop and indicates as `min_index = i`

you also have the minimum item indexes from inner loop, so just `swap the smallest item with first element`.

if first and smallest element are same no swap are required
`if(min_index!=i) swap(arr[min_index], arr[i]);`

## Characteristics

- **`In-Place Sorting`** - no extra memory required
- **Space Complexity:** `O(1)`
  - no extra memory required
- **Time Complexity:**
  - Worst Case: O(n<sup>2</sup>) - due to two nested loops
  - Best Case: O(n<sup>2</sup>) - it still scans the unsorted portion even if the list is already sorted
  - Average Case: O(n<sup>2</sup>)
- **Number of Swaps:** - It performs at most n-1 swaps.
- **Number of Comparisons:**
  - first iteration it compare n-1 items
  - secont iteration it compare n-2 items
  - so total comparison is n\*(n-1)/2
- **Stability:** - It is not stable, meaning that it might change the relative order of equal elements if swapping places them differently.

## When to use

- minimum swaping requires
- memory is constrained
- small dataset

# Insertion Sort

It mimics how we might sort playing cards in our hands.

It works by dividing the array into a sorted and an unsorted portion. The algorithm progressively takes elements from the unsorted portion and inserts them into their correct position within the sorted portion.

## Implementation

- Outer Loop
- Inner Loop
- Shifting

### Outer Loop

The first item is considered sorted by default. Outer loop iterates through the unsorted portion, pick one element at a time and placing it into the correct position in the sorted portion

### Inner Loop

Inner loop is used to find out where the insertion should be performed. It iterate from the last element of sorted portion until lesser value of current element is not found. Until the lesser value is found the item from sorted portion shift one place right.

### Shifting

It shifts elements instead of swapping. A variable `j` is declared to track where to insert or the last index of the sorted portion after performing shifting operation.

## Charecterstics

- **`In-Place Sorting`** - no extra memory required
- **Space Complexity**: `O(1)` no extra memory required
- **Time Complexity:**
  - Worst Case: O(n<sup>2</sup>) - the array is sorted in reverse order.
  - Best Case: O(n) - No shifting is required; each element is compared once and placed immediately.
  - Average Case: O(n<sup>2</sup>)
- **Number of Shift:** - in worst case at most n\*(n-1)/2 shift is performed.
- **Number of Comparisons:**
  - first iteration it compare n-1 items
  - secont iteration it compare n-2 items
  - so total comparison is n\*(n-1)/2
- **Stability:** - It is stable, meaning that it keep the relative order of equal elements.

## When to use

- small dataset
- memory constraint
- array is nearly sorted
- minimum comparison required\

# Merge Sort

Merge Sort is a divide-and-conquer sorting algorithm that splits an array into smaller subarrays, sorts those subarrays, and then merges them back together in a sorted manner.

## Implementation

- Merge Sort
- Merge

### Merge Sort

- divide the array into two equal part(`int mid = left + (right - left) / 2;`).
- splitting the array should be continued until each subarray contains a single element or is empty.
- splitting occurs recursively untile the most left node is found, when the most left node is found, it traverse to right one, and it contues untill all element is splitted.

### Merge

Combine the two sorted halves into a single sorted array by comparing elements from each half and inserting the smaller one into the final array.

- extract the size of both array.
- copy data from main array to temporary array.
- compare and merge same amount of item from both array.
- merge remaining item of left array.
- merge remaining item of right array.

## Charecterstics

- **Space Complexity**: `O(n)` - due to the temporary arrays used during merging.
- **Time Complexity:**
  - Worst Case: O(n log n)
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - The `log n` factor comes from the division of the array, and the `n` factor comes from the merging process.
- **Number of Comparisons:** in each step there will be `n` number of comparison and there have total `log n` step so total comparison is `n log n`.
- **Stability:** - It is stable, meaning that it keep the relative order of equal elements.

## When to use

- large dataset
- suitable for linked lists because it avoids the overhead of random access.

# Quick Sort

Quick Sort is a divide-and-conquer sorting algorithm that works by selecting a "pivot" element and partitioning the array around the pivot.

The goal is to move smaller elements to the left of the pivot and larger elements to the right. The process is then recursively applied to the sub-arrays.

## Implementation

### Pivot Selection

The pivot is an element around which the array will be partitioned. Popular strategies include:

- First element - may lead to poor performancefor sorted/revers sorted arrays
- Last element - similar limatations as first element
- Random - helps by avoiding worst-case scenarios
- Medeian of first, last, middle

### Partitioning

- The array is rearranged such that:
  - All elements smaller than the pivot are moved to its left.
  - All elements larger than the pivot are moved to its right.
- This ensures the pivot is in its correct position in the sorted array.
- `swap(arr[i], arr[j]);` may swap itself.

### Recursion

Apply the same steps to the left and right sub-arrays.

## Charecterstics

- **`In-Place Sorting`** - no extra memory required during partitioning, recursive call use the function stack for managing sub-problems, but this space usage is not considered "external memory".
- **Space Complexity:** `O(log n)` - due to recursive calls in the function stack.
- **Time Complexity:**
  - Worst Case: O(n<sup>2</sup>) - occurs when the pivot consistently produces unbalanced partitions(smallest/largest)
  - Best Case: O(n log n) - occurs when the partition is balanced(equal element)
  - Average Case: O(n log n)
- **Number of Comparisons:** It depends on the pivot selection and how the array is partitioned at each step. in worst case n\*(n+1)/2 comparison will occur such as pivot is largest/smalles element.
  - first partion produces one sub array with n-1 item and another one is 0
  - second partion produces one sub array with n-2 item and another one is 1
- **Number of Swaps:** after making a comparison swap has been performed. so max swap can be n\*(n+1)/2
- **Stability:** - It is not stable, meaning that it might change the relative order of equal elements if swapping places them differently.

## When to use

- large dataset
- in-place sorting
- Performs well with random inputs compared to already sorted or reverse-sorted arrays.