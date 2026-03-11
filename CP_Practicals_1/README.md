# Analysis of the solved problems

### Problem 1 — Dynamic Array Basics

The code uses vector (a dynamic container), <algorithm> for min/max functions, and <numeric> for calculating the sum of the given n integers.

```c++
vector<int> vec(n);
```
The `vector` allows memory to be allocated dynamically at runtime based on the input.

```c++
int max_val = *max_element(vec.begin(), vec.end());

```
This is the `STL algorithm` and it efficiently finds the largest element.

```c++
int min_val = *min_element(vec.begin(), vec.end());

```
This is also a `STL algorithm` and it efficiently finds the smallest element.

```c++
long long sum_val = accumulate(vec.begin(), vec.end(), 0LL);
```
It sums all elements in the range. Prevent integer overflow if the sum of integers exceeds the capacity of a standard int. 

#### Time complexity analysis : O(n)

The code have linear steps that allocates space for the n numbers of integers and read n values. To find the max_element it scans all the element once and another scan to find the min_element. To find the sum it scan all the element.


#### Space complexity analysis : O(n)

The dynamic storage is the vector size of n and other variables uses O(1) which is constand space. 


#### Reflection

While solving the problem I learned a few lessons :

1. Using the right data sturcture and algorithm 
2. The complexity of the program 
3. input and output checks

![alt text](Assets/q1.png)