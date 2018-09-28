#include "INIreader.h"

#include <iostream>

int main()
{
   try {
      auto &iniReader{INIreader::instance()};

      iniReader.setFileName("Example.ini");
      std::cout << "Sorted cached INI data:\n" << iniReader << std::endl;

      std::string introText;
      iniReader.getData("IntroText", introText);
      std::cout << " " << introText << std::endl;

      double RoombaRadius{0.0};
      iniReader.getData("Roomba.r", &RoombaRadius);
      std::cout << " Roomba radius = " << RoombaRadius << std::endl;

      int baudrate{0};
      iniReader.getData("SerialLink.baudrate", &baudrate);
      std::cout << " Baudrate = " << baudrate << std::endl;

      double vr{0.0};
      iniReader.getData("Vehicle.rotation", &vr);
   }
   catch (std::exception &e) {
      std::cerr << "\n*** " << e.what() << std::endl;
   }
   catch (...) {
      std::cerr << "\n*** Unknown error" << std::endl;
   }

   return 0;
}
