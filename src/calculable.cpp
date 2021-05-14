#include "calculable.h"

void SimpleValue::calc(std::stack<double>& execution) const
{
  execution.push(m_value);
}

void UnaryOperation::calc(std::stack<double>& execution) const
{
  double operand = execution.top();
  execution.pop();
  double result = calcUnary(operand);
  execution.push(result);
}

void BinaryOperation::calc(std::stack<double>& execution) const
{
  double operandRight = execution.top();
  execution.pop();
  double operandLeft = execution.top();
  execution.pop();
  double result = calcBinary(operandLeft, operandRight);
  execution.push(result);
}

double BinarySum::calcBinary(const double& operandLeft, const double& operandRight) const
{
  return operandLeft + operandRight;
}

double BinaryDiff::calcBinary(const double& operandLeft, const double& operandRight) const
{
  return operandLeft - operandRight;
}

double BinaryMul::calcBinary(const double& operandLeft, const double& operandRight) const
{
  return operandLeft * operandRight;
}

double BinaryDiv::calcBinary(const double& operandLeft, const double& operandRight) const
{
  return operandLeft / operandRight;
}

std::shared_ptr<BinaryOperation> createBinaryOperation(const Token& token)
{
  if(token.getValue() == "+")
    return std::make_shared<BinarySum>();
  if(token.getValue() == "-")
    return std::make_shared<BinaryDiff>();
  if(token.getValue() == "*")
    return std::make_shared<BinaryMul>();
  if(token.getValue() == "/")
    return std::make_shared<BinaryDiv>();
  return nullptr;
}

std::deque<std::shared_ptr<Calculable>> toPostfix(const std::deque<Token>& tokens)
{
  std::deque<std::shared_ptr<Calculable>> result; 

  std::shared_ptr<Calculable> delimeter(nullptr);
  std::deque<std::shared_ptr<Calculable>> buffer;
  bool lastWasOperation = true;

  std::deque<Token>::const_iterator tokenIterator = tokens.cbegin();
  while( tokenIterator != tokens.end() )
  {
    const Token& token = *tokenIterator;
    switch(token.getType())
    {
      case NUM_INT:
      {
        lastWasOperation = false;
		++tokenIterator;
        int value = std::atoi(token.getValue().c_str());
        result.push_back(std::make_shared<SimpleValue>(value));
        break;
      }
      case NUM_FLO:
      {
        lastWasOperation = false;
		++tokenIterator;
        double value = std::atof(token.getValue().c_str());
        result.push_back(std::make_shared<SimpleValue>(value));
        break;
      }
      case PAR_L:
      {
		++tokenIterator;
        buffer.push_front(delimeter);
        lastWasOperation = true;
        break;
      }
      case PAR_R:
      {
		++tokenIterator;
        lastWasOperation = false;
        while(buffer.size() != 0 && buffer.front() != delimeter)
        {
          result.push_back(buffer.front());
          buffer.pop_front();
        }
        if(buffer.front() == delimeter)
          buffer.pop_front();
        break;
      }
      case MINUS:
      {
        if(lastWasOperation)
        {
		  ++tokenIterator;
          std::shared_ptr<Calculable> operation = std::make_shared<UnaryNegate>();
          buffer.push_front(operation);
          lastWasOperation = true;
          break;
        }
      }
      case PLUS:
      case MUL:
      case DIV:
      {
		++tokenIterator;
        std::shared_ptr<Calculable> operation = createBinaryOperation(token);
        lastWasOperation = true;
        int strength = operation->strength();
        while(buffer.size() != 0 && buffer.front() != delimeter && buffer.front() -> strength() >= strength)
        {
          result.push_back(buffer.front());
          buffer.pop_front();
        }
        buffer.push_front(operation);
        break;
      }
      default:
      {
		++tokenIterator;
      }
    }
  }
  while(buffer.size() != 0 && buffer.front() != delimeter)
  {
    result.push_back(buffer.front());
    buffer.pop_front();
  }
  return result;
}

double calculatePostfix(const std::deque<std::shared_ptr<Calculable>>& postfixExpr)
{
  std::stack<double> execution;
  for(std::deque<std::shared_ptr<Calculable>>::const_iterator it = postfixExpr.cbegin(); it != postfixExpr.cend(); ++it)
  {
    (*it) -> calc(execution);
  }
  return execution.top();
}
