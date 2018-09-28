// C++11 code example ----------------------------------------------------------

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main()
{
   //---------------------------------------------------------------------------
   string s(1000, 'a'); // s contains 1000 'a' chars

   cout << endl << "Size = " << s.size() << endl << endl;

   //---------------------------------------------------------------------------
   string s1{"Hello World\n"};
   string s2{"10"};
   string s3{to_string(123)};
   string s4{to_string(123.99)};
   int i{stoi(s2)};

   cout << s1 << " " << s2 << " = " << i << endl;
   cout << s3 << " " << s4 << endl << endl;

   //---------------------------------------------------------------------------
   string s10{"123"};
   size_t pos1{0};
   int j{stoi(s10, &pos1)};

   cout << s10 << "==>" << j << " s10 to int conversion pos1: " << pos1 << endl;

   //---------------------------------------------------------------------------
   string s20{"123xyz"};
   size_t pos2{0};
   int k{stoi(s20, &pos2)};

   cout << s20 << "==>" << k << " s20 to int conversion pos2: " << pos2 << endl;
   if (s20.size() != pos2) {
      cout << "## Wrong format integer string s20: '" << s20 << "'" << endl;
   }

   //---------------------------------------------------------------------------
   try {
      string s30{"xyz123"};
      size_t pos3{0};
      int l{stoi(s30, &pos3)};

      cout << s30 << "==>" << l << " s30 to int conversion pos3: " << pos3
           << endl;
      if (s30.size() != pos3) {
         cout << "## Wrong format integer string s30: '" << s30 << "'" << endl;
      }
   }
   catch (invalid_argument &e) {
      cout << endl << "## EXCEPTION s30 invalid_argument: " << e.what() << endl;
   }

   //---------------------------------------------------------------------------
   try {
      string s40{"1231111111111111111111111111111111111111"};
      size_t pos4{0};
      int m{stoi(s40, &pos4)};

      cout << s40 << "==>" << m << " s40 to int conversion pos4: " << pos2
           << endl;
      if (s40.size() != pos4) {
         cout << "## Wrong format integer string s40: '" << s40 << "'" << endl;
      }
   }
   catch (invalid_argument &e) {
      cout << endl << "## EXCEPTION s40 invalid_argument: " << e.what() << endl;
   }
   catch (out_of_range &e) {
      cout << endl << "## EXCEPTION s40 out_of_range: " << e.what() << endl;
   }
   // using an anounymous string object (object without a name)
   cout << string(50, '-') << endl;

   return 0;
}
