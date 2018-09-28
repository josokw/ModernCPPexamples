#include "Tokenizer.hpp"

#include <iostream>

using namespace std;

int main()
{
   // string containing ints and doubles
   string line{" 1  2   33.337  "};
   cout << endl << "Input: '" << line << "'" << endl;

   // using default delimiter: isspace (see Tokenizer.hpp)
   vector<string> tokens{split(line)};

   for (const auto &tkn : tokens) {
      cout << tkn << endl;
   }
   cout << endl;

   // conversion of string tokens to int and double types
   int i1{stoi(tokens[0])};
   int i2{stoi(tokens[1])};
   double d3{stod(tokens[2])};

   cout << i1 << " " << i2 << " " << d3 << endl << string(50, '-') << endl;

   // example: using MQTT topic string
   string topic{"ESEiot/BBB0200/temperature"};
   cout << "Topic: '" << topic << "'" << endl;
   vector<string> tokensTopic{split(topic, isForwardSlash)};

   for (const auto &tkn : tokensTopic) {
      cout << tkn << endl;
   }
   cout << endl
        << tokensTopic[0] << " " << tokensTopic[1] << " " << tokensTopic[2]
        << endl
        << string(50, '-') << endl;

   return 0;
}
