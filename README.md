# 🔢 Push_Swap - 42 School Project

## 🚀 Project Overview

**Push_Swap** is a sorting algorithm challenge where the goal is to sort a stack of integers using a limited set of operations, with the least number of moves possible. This project strengthens understanding of algorithm optimization, data structures, and problem-solving with constrained resources.

During this project, I developed skills in:

- 🗂 **Stack data structure** management using linked lists or arrays.
- 🔄 Implementing and optimizing sorting algorithms under constraints.
- ⚙️ Using a **limited instruction set** to manipulate stacks:
  - `sa`, `sb`, `ss` (swap)
  - `pa`, `pb` (push)
  - `ra`, `rb`, `rr` (rotate)
  - `rra`, `rrb`, `rrr` (reverse rotate)
- 🔍 **Algorithmic thinking** to minimize moves and optimize sorting strategies.
- 🧮 Understanding and applying sorting techniques like:
  - Insertion sort (for small datasets)
  - Divide and conquer approaches (chunking, indexing)
  - Quick sort-inspired partitioning
- 🧹 Memory management and error handling in C.

## 🛠 Technical Concepts Used

- **Linked lists or arrays** for stacks A and B.
- Parsing and validating input arguments (integers, no duplicates).
- Writing efficient and clean C code following 42’s Norm.
- Using **recursion and iteration** strategically.
- Debugging and benchmarking the number of moves.
- Optimizing based on stack size (different tactics for small vs large inputs).

## 🧩 Algorithm Highlights

- Handling **small stacks (2-5 elements)** with simple conditional logic.
- For **larger stacks**, splitting the list into chunks and pushing elements accordingly.
- Using **indexes** or **normalization** to simplify comparisons.
- Minimizing operations by combining moves where possible (`ss`, `rr`, `rrr`).
- Balancing operations between stack A and B for optimal sorting.

## 🚫 Challenges Overcome

- ✅ Devising an efficient sorting strategy within limited instructions.
- ✅ Avoiding infinite loops or redundant operations.
- ✅ Handling edge cases (already sorted, reversed, duplicates).
- ✅ Writing modular code to separate logic and operations.
- ✅ Ensuring correctness with minimal operation counts.

## 🧠 Key Takeaways

Push_Swap taught me to think critically about algorithm efficiency and to work within tight constraints. It sharpened my skills in:

- Data structure manipulation
- Writing optimized, clean C code
- Debugging complex logic flows
- Applying algorithm design principles to real-world coding challenges

## 🏆 Sorting Performance Goals

To achieve the **maximum grade**, the number of operations performed by your program must stay within these limits (as per 42’s push_swap evaluation criteria):

| Number of Elements | Maximum Allowed Operations |
|--------------------|----------------------------|
| 3                  | ≤ 3                        |
| 5                  | ≤ 12                       |
| 100                | ≤ 700                      |
| 500                | ≤ 5500                     |

These goals ensure your sorting algorithm is **efficient** and well-optimized for different input sizes.
