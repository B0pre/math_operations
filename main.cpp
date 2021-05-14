#include <string>
#include <deque>
#include <memory>
#include <iostream>
#include "calculable.h"
#include "tokens.h"


int main(int argc, char ** argv)
{
  std::deque<Token> tokens = lexAnalyse(argv[1]);
  std::deque<std::shared_ptr<Calculable>> postfixExpr = toPostfix(tokens);
  double result = calculatePostfix(postfixExpr);

  std::cout << argv[1] << " = " << result << std::endl;
  return 0;
}
