#include <iomanip>
#include <iostream>
#include <type_traits>

// Templates are used in the Standard Template Library (STL).
//
// Without templates you must implement this function for every type:
// function overloading.
//
// void hexdump(int data) {
//   unsigned char* p = reinterpret_cast<unsigned char*>(&data);
//   for (size_t i = 0; i < sizeof(int); ++i) {
//      std::cout << std::setfill('0') << std::setw(2)
//                << std::hex << static_cast<int>(p[i]) << " ";
//   }
// }
//
// void hexdump(double data) {
//   unsigned char* p = reinterpret_cast<unsigned char*>(&data);
//   for (size_t i = 0; i < sizeof(double); ++i) {
//      std::cout << std::setfill('0') << std::setw(2)
//                << std::hex << static_cast<int>(p[i]) << " ";
//   }
// }
//

// Generic function
template <typename T> void hexdump(T data)
{
   // Compile time checking, no pointer types allowed
   static_assert(not std::is_pointer<T>::value, "T can't be a pointer");

   unsigned char *p = reinterpret_cast<unsigned char *>(&data);
   for (size_t i = 0; i < sizeof(T); ++i) {
      std::cout << std::setfill('0') << std::setw(2) << std::hex
                << static_cast<int>(p[i]) << " ";
   }
}

using namespace std;

int main(int argc, char *argv[])
{
   cout << "Hello World of template functions!" << endl << endl;

   hexdump(1.123L); // long double
   cout << endl;
   hexdump(1.123);  // double
   cout << endl;
   hexdump(10LL);   // long long
   cout << endl;
   hexdump(10L);    // long
   cout << endl;
   hexdump(10);     // int
   cout << endl;
   // hexdump("This is text"); //=> compile time error caused by static assert
   // cout << endl;
   hexdump('a'); // char
   cout << endl << endl;

   return 0;
}
