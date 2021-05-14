#include <string>
#include <deque>
#include <memory>
#include <iostream>
#include "calculable.h"
#include "tokens.h"


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

  std::deque<Token> tokens = lexAnalyse(expr);
  std::deque<std::shared_ptr<Calculable>> postfixExpr = toPostfix(tokens);
  double result = calculatePostfix(postfixExpr);

  std::cout << expr << " = " << result << std::endl;
  return 0;
}
