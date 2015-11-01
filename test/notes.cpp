
// -----------------------
// General Reminders
// -----------------------

// how much space does it require to represent an integer as a single bit,
// corresponding to a "number on a line" (e.g. for storing a set of ints)?
// 16 bit int, values 0..65000 => bit set has size 8k
// 32 bit int, values 0..4294967296 = 4.2 * 10^9 => bit set has 512 MB
// a reasonable range would be 0..10 million which has bit set size ~1 MB
// question inspired from: http://alexbowe.com/rrr/

// complexity of storing permutations?
// O(N * N!) because the number of permutations itself is N!
// but storing each permutation itself is O(N)


// clear the lowest set bit of x
x & (x - 1)

// extract the lowest set bit of x
x & ~(x - 1)

// swap bit i
x ^ (1L << i)

// simple argument why quicksort/quickselect are worst case quadratic
// => triangular numbers grow quadratically

// terms for "the terminating case of a recursion":
// initial condition, boundary condition, base case

// Examples for cubic algorithms:
// - matrix multiplication

// "abstract data type" vs "data structure"
// ADT means abstract functionality, examples: containers, dictionaries, and priority queues
// A DS is a concrete implementation.

// Advanced trees material:
// Red-Black:
//   https://www.youtube.com/watch?v=tzq766Spphw

// How to convert an recursion to iteration?
// Basically: Use your own stack, and push parameters.
Stack<Object> stack;
stack.push(first_object);
while( !stack.isEmpty() ) {
   // Do something
   my_object = stack.pop();

  // Push other objects on the stack.

}
// example of quicksort -- recursive
void quicksort(int* array, int left, int right)
{
    if(left >= right)
        return;

    int index = partition(array, left, right);
    quicksort(array, left, index - 1);
    quicksort(array, index + 1, right);
}
// example of quicksort -- iterative
// note that neither two stacks, nor stack<int,int> is required
// by simply pushing pairs
void quicksort(int *array, int left, int right)
{
    int stack[1024];
    int i=0;

    stack[i++] = left;
    stack[i++] = right;

    while (i > 0)
    {
        right = stack[--i];
        left = stack[--i];

        if (left >= right)
             continue;

        int index = partition(array, left, right);
        stack[i++] = left;
        stack[i++] = index - 1;
        stack[i++] = index + 1;
        stack[i++] = right;
    }
}

#include <iostream>
#include <algorithm>

void print(int *a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}

// Chomsky classes:
/*
Type-0 	Recursively enumerable 	Turing machine 	alpha -> beta (no restrictions)
Type-1 	Context-sensitive 	Linear-bounded non-deterministic Turing machine 	alpha A beta -> alpha gamma beta
Type-2 	Context-free 	Non-deterministic pushdown automaton 	A -> gamma
Type-3 	Regular 	Finite state automaton 	A -> a and A -> aB (right-regular)

gamma = terminals + non-terminals
Difference CH2 vs CH3: RHS for CH3 only allows one non-terminal which is always
either on the right or left (right/left) regular, while CH2 allows any combination
on the RHS.
Both have a single non-terminal on the LHS.

https://en.wikipedia.org/wiki/Chomsky_hierarchy#Summary
*/






// -----------------------
// Sorting
// -----------------------

// Insertion sort
insertion_sort(item s[], int n)
{
  int i,j;                /* counters */
  for (i=1; i<n; i++) {
    j=i;
    while ((j>0) && (s[j] < s[j-1])) {
      swap(&s[j], &s[j-1]);
      j = j-1;
    }
  }
}

// Selection sort
selection_sort(int s[], int n)
{
  int i,j;                /* counters */
  int min;                /* index of minimum */
  for (i=0; i<n; i++) {
    min=i;
    for (j=i+1; j<n; j++) {
      if (s[j] < s[min]) min=j;
    }
    swap(&s[i], &s[min]);
  }
}

// Quicksort with nice partition implementation.
// - Complexity: O(N log N) (best/average), O(N^2) (worst case)
// - Memory: O(log N) (best/average), O(N) (worst case, unless Sedgewick version, which maintains O(log N))
// - unstable, can be made stable by using O(N) additional memory (copying the arrays)
//   there are rumors that there it is also possible to get stable + O(log N) memory,
//   but apparently with worse performance.
// http://codereview.stackexchange.com/questions/77782/quick-sort-implementation
// Nice, because it moves both from left to right and right to left,
// until the "<= pivot" and "> pivot" are BOTH violated.
// Now the swap solves two problems at once!
// The pivot = mid heuristic seems also be reasonable.
int partition(int *arr, const int left, const int right) {
  const int mid = left + (right - left) / 2;
  const int pivot = arr[mid];
  // move the mid point value to the front.
  std::swap(arr[mid],arr[left]);
  int i = left + 1;
  int j = right;
  while (i <= j) {
    while(i <= j && arr[i] <= pivot) {
      i++;
    }
    while(i <= j && arr[j] > pivot) {
      j--;
    }
    if (i < j) {
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i - 1],arr[left]);
  return i - 1;
}

void quicksort(int *arr, const int left, const int right, const int sz){
  if (left >= right) {
    return;
  }
  int pivot_index = partition(arr, left, right);
  quicksort(arr, left, pivot_index - 1, sz);
  quicksort(arr, pivot_index + 1, right, sz);
}



/*

Core language

*** What are the types in C, Java, C++, and Perl? How many bits does it take to represent the basic types?

*** What do floating point numbers look like in memory? Specifically, how many bits are there in a double and what sequence to the bits appear in?
Single Precision 	Sign: 1 [31] 	Exponent: 8 [30-23] 	Fraction: 23 [22-00] 	Bias: 127
Double Precision 	Sign: 1 [63] 	Exponent: 11 [62-52] 	Fraction: 52 [51-00] 	Bias: 1023
The exponent is not the actual exponent value: There is a bias of 127/1023 which has to be added
to the stored value to get the actual exponent.
The mantiassa is obtained by assuming an implicit leading bit, followed by the "fraction" bits.

Examples:
https://en.wikipedia.org/wiki/Single-precision_floating-point_format

*** What is twos-complement notation?
Given N-bit number x:
Two-complement == (2^N == one "1" followed by N "0" = 1L << N) MINUS x
               == One-complement PLUS 1
One-complement == all reversed:
Example (-1) in 3-bits:
  Method 1: 1000 - 1 = 0111
  Method 2: represntation of corresponding positive => 001 => One-complement => 110 => PLUS 1 => 111

What's the advantage?
Due to the (subtracted from 2^N)-notion, two-complement representation allows to
implement addition, subtraction, and multiplication EXACTLY AS IF they were unsigned,
i.e., operations do not have to test whether operands are negative.

*** How would you implement a bit array class?

*** Does the check x == x + 1 always return false for integer x?

*** What does a C struct look like in memory? What does a C++ object look like in memory? What does a Java object look like in memory?

*** What is the difference between an interpreted and a compiled language?

*** What is garbage collection?

*** How would you determine if call stack grows up or down relative to memory addresses?

*** Give an example of a memory leak in Java.

- open resource like a stream, and don't close it in finally.
- Static field holding object reference
- there are other nasty things involing classload + thread uglyness.
http://stackoverflow.com/questions/6470651/creating-a-memory-leak-with-java

*** What is tail recursion? How can it be removed automatically?
Easy: Last op is function call.

*** Is the natural recursive program for computing n! tail recursive?
No, last op is a multiplication.

*** Your manager reads an online article that says it is 10X faster to code in Python than in C++. He wants you to code exclusively in Python from now on. What would you say to him?

*** What does an executable look like as a sequence of bytes?



Programming language implementation

*** Give an example of a language which cannot be parsed by any computer.

Ex1: The language consisting of all programs which terminate.
Ex2: The language consisting of finite sets of nxn matrices, which can be multiplied to the zero matrix
     in a potentially infinite series.
https://en.wikipedia.org/wiki/List_of_undecidable_problems

*** What problems does dynamic linkage solve? What problems does it introduce?
*** What is a functional language?
*** What is a virtual function?
*** How is method dispatch implemented in Java?
*** What is automatic garbage collection and how is it implemented?
*** What is a type-safe language?
*** What is the difference between a lexer and a parser?
*** Give an example of a language which cannot be recognized by a lexer.
*** Give an example of a language which cannot be parsed by a parser.

*/





// -----------------------
// Streaming & Sketching
// -----------------------

/*
Terminology:
  - dyadic range: Refers to the concept of dividing an interval (or time)
    into subintervals, which grow exponentially in size.


*/


// -----------------------
// C++ specific
// -----------------------


// Quirk: Negating a negative int does not necessarily result in a positive result!
// Reason: The max-neg int does not have a positive equivalent, because the range is assymmetric.
// Therfore: -max-neg-int

// Why is “using namespace std;” considered bad practice?
// Because when using two namesspaces foo and bar, foo might change, and collide with bar...
// Two issues: (1) renaming required, (2) new function in bar could be a better match and silently call wrong function!

// determine extreme values of a type T
#include <limits>
int best_val = std::numeric_limits<int>::max();


// negative vector indices:
v[i]    // no bounds check and negative allowed (but relative to start, not relative to end, think pointers not python)
v.at(i) // with bounds check and negative always throw out_of_range


// split a string
vector<string> split(const string& s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}

// convert a string to float _and_ validate it (atof will return 0.0 on errors :())
istringstream iss(s);
double value;
iss >> ws >> value >> ws; // ws for allowing surrounding white space
if (iss.eof() && !iss.fail()) {
  // okay
}



