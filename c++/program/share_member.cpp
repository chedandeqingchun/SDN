#include <iostream>

class Group {
public:
  static int age;
  static const int fans = 5;
  int year;
  static const int students[];
};


int Group::age = 3;


const int students[] = {1, 2, 3, 4, 5}; 


int main(void) {
  Group group1, group2;


  group1.year= 5;
  group1.age = 5;
  group2.year = 10;
  group2.age = 15;
  
  std::cout << group1.age << group1.year << std::endl;
  std::cout << group2.age << group2.year << std::endl;
  std::cout << group1.age << group1.year << std::endl;
  std::cout << group1.fans << std::endl;
  
  return 0;
}
