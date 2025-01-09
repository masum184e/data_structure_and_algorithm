# Contents

- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)

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
