
// clear the lowest set bit of x
x & (x - 1)

// extract the lowest set bit of x
x & ~(x - 1)



// determine extreme values of a type T
#include <limits>
int best_val = std::numeric_limits<int>::max();


// negative vector indices:
v[i]    // no bounds check and negative allowed (but relative to start, not relative to end, think pointers not python)
v.at(i) // with bounds check and negative always throw out_of_range





