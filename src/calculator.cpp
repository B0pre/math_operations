#include "calculator.h"

#include <deque>
#include <memory>
#include <iostream>
#include "calculable.h"
#include "calculator.h"
#include "tokens.h"

double calculate(const std::string& expr)
{
  std::deque<Token> tokens = lexAnalyse(expr);
  std::deque<std::shared_ptr<Calculable>> postfixExpr = toPostfix(tokens);
  double result = calculatePostfix(postfixExpr);
  return result;
}
