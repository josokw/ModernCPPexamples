#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

// Avoid using #define
const int BUFFER_SIZE = 6;

using namespace std;

int main()
{
   // C array, static fixed sized
   int buffer1[BUFFER_SIZE] = {0, 3, 2, 5, 4, 0};
   buffer1[0] = 10;

   cout << "buffer1: ";
   // Ranged-based for loop
   for (auto e : buffer1) {
      cout << e << " ";
   }
   if (!is_sorted(buffer1, buffer1 + BUFFER_SIZE)) // using pointers
   {
      cout << " is not sorted" << endl;
   }
   sort(buffer1, buffer1 + BUFFER_SIZE);
   cout << "buffer1: ";
   for (auto e : buffer1) {
      cout << e << " ";
   }
   cout << endl << endl;

   // Array template container class, static fixed sized array
   array<int, BUFFER_SIZE> buffer2{1, -3, 2, -5, 4, 0}; // initializer list
   buffer2[0] = 10;

   cout << "buffer2: ";
   for (auto e : buffer2) {
      cout << e << " ";
   }
   if (!is_sorted(begin(buffer2), end(buffer2))) // using iterators
   {
      cout << " is not sorted, size = " << buffer2.size() << endl;
   }
   sort(begin(buffer2), end(buffer2));
   cout << "buffer2: ";
   for (auto e : buffer2) {
      cout << e << " ";
   }
   cout << endl << endl;

   // Dynamically sized container class ----------------------------------------
   vector<int> vec{10, 20, 50, 10, 25, -300};
   vec[0] = 15;

   cout << "vec: ";
   for (auto e : vec) {
      cout << e << " ";
   }
   if (!is_sorted(begin(vec), end(vec))) {
      cout << " is not sorted, size = " << vec.size() << endl;
   }
   sort(begin(vec), end(vec));
   cout << "vec: ";
   for (auto e : vec) {
      cout << e << " ";
   }
   if (is_sorted(begin(vec), end(vec))) {
      cout << " is sorted" << endl;
   }
   cout << endl;

   //---------------------------------------------------------------------------
   vector<int> vecTarget{0, 0, 0, 0, 0, 0, 0, 0};

   copy_n(begin(vec), 4, begin(vecTarget) + 1);
   cout << "vecTarget: ";
   for (auto e : vecTarget) {
      cout << e << " ";
   }
   cout << endl;

   int x = 15;
   int y = 200;
   // C++11 Lambda function [capture](params){body}, LOCAL function object
   auto r =
      find_if(begin(vec), end(vec), [x, y](int i) { return i > x && i < y; });

   if (r != end(vec)) {
      cout << "vec: " << x << " < first value < " << y << " = " << *r << endl;
      r = find_if(r + 1, end(vec), [x, y](int i) { return i > x && i < y; });
      if (r != end(vec)) {
         cout << "vec: " << x << " < second value < " << y << " = " << *r
              << endl;
      }
   }

   int sum = 0;
   for_each(begin(vecTarget), end(vecTarget), [&sum](int i) { sum += i; });
   cout << "Sum vecTarget = " << sum << endl << endl;

   // Initializer_list ----------------------------------------------------------
   vec = {1, 2, 3, 4, 5, 6, 7, 8}; // = vector<int> {1, 2, 3 ....}

   cout << "vec: ";
   for (auto e : vec) {
      cout << e << " ";
   }
   cout << endl;

   int min = 5;
   // Erase: removes elements in the range [first; last)
   vec.erase(remove_if(begin(vec), end(vec), [min](int n) { return n < min; }),
             end(vec));
   cout << "vec: ";
   for (auto c : vec) {
      cout << c << " ";
   }
   cout << " after removing elements, size = " << vec.size() << endl;

   return 0;
}
