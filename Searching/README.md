# Binary Search
## Identify
**1. Check for Sorted or Monotonic Data**
- Finding an element in a sorted array.
- Finding the smallest or largest value that satisfies a given condition.

**2. Define the Search Space**

This can be:
- An array or list.
- A numerical range

**3. Formulate a Decision Function**

A binary search problem often involves a yes/no decision at each step. You need to define a function or condition that splits the search space:
- **Yes**: The target can be in this part of the search space.
- **No**: The target cannot be in this part of the search space.

**4. Check for Optimal/Suboptimal Decisions**

Binary search works if you can discard half of the search space in each step by making a decision. Problems that have:

- A clear objective (find minimum, maximum, or an exact value).
- A way to eliminate half of the options.

**5. Determine the Goal**

Decide if you are looking for:

- **Exact Match**: Find an element in a sorted array.
- **Boundary Value**: Find the smallest/largest value satisfying a condition.

## Solve
**1. Understand the Problem**

Clearly define the problem, including the input, output, and any constraints. Ask:

- Is the data sorted or can it be interpreted as sorted (monotonic)?
- What are you searching for (an exact value or a boundary condition)?

**2. Define the Search Space**

Determine the range of values (`low` and `high`) to search.

- If searching in a sorted array, the range is the indices of the array.
- If solving a numerical problem, define a meaningful range based on the constraints.

**3. Formulate the Decision Function**

Create a function or condition that:

- Splits the search space into two parts.
- Identifies which half might contain the solution.
- Typically involves a yes/no decision like "Does this value meet the condition?"

**4. Update the Search Space**

Based on the decision function:

- Narrow the search space by updating low or high.
- Use:
    - `low = mid + 1` if searching the right half.
    - `high = mid - 1` if searching the left half.

**5. Determine the Stopping Condition**

Binary search typically stops when:

- `low > high` (search space is exhausted).
- The desired condition is satisfied (e.g., an exact match or a boundary condition).

**6. Handle Edge Cases**

Think about edge cases such as:
- Empty arrays or invalid ranges.
- Values outside the search space.
- Single-element search space.
