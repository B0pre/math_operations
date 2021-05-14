#include <string>
#include <iostream>
#include "calculator.h"

int main(int argc, char ** argv)
{

  std::string expr;
  if(argc <= 1)
	std::getline(std::cin, expr);
  else
  {
    for(int i = 1; i < argc; ++i)
      expr += argv[i];
  }

  double result = calculate(expr);
  std::cout << expr << " = " << result << std::endl;
  return 0;
}
