#include <iostream>
#include <type_traits>

// Any uses of SIZE are now guaranteed to have the constant value 11 
// instead of computing 10 + 1 at runtime.
constexpr auto SIZE = 10 + 1;

// C++11 constexpr functions can only contain a return statement.
// Recursive calculation of the factorial of n.
// Factorial of n is the product of all the consecutive integers from 1 to n.
constexpr long factorial(int n) noexcept {
  return (n == 0L ? long(1) : (n * factorial(n - 1)));
}

// Compile time unit tests
static_assert(factorial(0) == 1, "ERROR: factorial(0) != 1");
static_assert(factorial(1) == 1, "ERROR: factorial(1) != 1");
static_assert(factorial(2) == 2, "ERROR: factorial(2) != 2");

int main(void) 
{  
  long nfac1[SIZE]{0};
  
  constexpr long nfac2[SIZE]{
    factorial(0), factorial(1), factorial(2), factorial(3), factorial(4), 
    factorial(5), factorial(6), factorial(7), factorial(8), factorial(9), 
    factorial(10)
  };
  
  int i = 0;
  for(auto& nf: nfac1) {
    // run time initialization
    nf = factorial(i++);
    std::cout << nf << " ";
  }
  std::cout << std::endl;
  
  for(const auto& nf: nfac2) {
     std::cout << nf << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
