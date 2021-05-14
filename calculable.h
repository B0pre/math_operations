#ifndef calculable_H
#define calculable_H

#include <memory>
#include <stack>
#include "tokens.h"

class Calculable
{
public:
  virtual void calc(std::stack<double>& execution) const = 0;
  virtual int strength() const = 0;
  virtual ~Calculable() {}
};

class SimpleValue : public Calculable
{
  double m_value;
public:
  SimpleValue(const double& value): Calculable(), m_value(value) {}
  virtual void calc(std::stack<double>& execution) const;

  virtual int strength() const
  {
    return 0;
  }
  virtual ~SimpleValue() {}
};

class UnaryOperation : public Calculable
{
public:
  virtual double calcUnary(const double& operand) const = 0;
  virtual void calc(std::stack<double>& execution) const;
  virtual ~UnaryOperation() {}
};

class UnaryNegate : public UnaryOperation
{
public:
  virtual double calcUnary(const double& operand) const
  {
    return -1 * operand;
  }
  virtual int strength() const
  {
    return 3;
  }
  virtual ~UnaryNegate() {}
};

class BinaryOperation : public Calculable
{
public:
  virtual double calcBinary(const double& operandLeft, const double& operandRight) const = 0;
  virtual void calc(std::stack<double>& execution) const;
  virtual ~BinaryOperation() {}
};

class BinarySum : public BinaryOperation
{
public:
  virtual double calcBinary(const double& operandLeft, const double& operandRight) const;
  virtual int strength() const
  {
    return 1;
  }
  virtual ~BinarySum() {}
};

class BinaryDiff : public BinaryOperation
{
public:
  virtual double calcBinary(const double& operandLeft, const double& operandRight) const;
  virtual int strength() const
  {
    return 1;
  }
  virtual ~BinaryDiff() {}
};

class BinaryMul : public BinaryOperation
{
public:
  virtual double calcBinary(const double& operandLeft, const double& operandRight) const;
  virtual int strength() const
  {
    return 2;
  }
  virtual ~BinaryMul() {}
};

class BinaryDiv : public BinaryOperation
{
public:
  virtual double calcBinary(const double& operandLeft, const double& operandRight) const;
  virtual int strength() const
  {
    return 2;
  }
  virtual ~BinaryDiv() {}
};

std::shared_ptr<BinaryOperation> createBinaryOperation(const Token& token);

std::deque<std::shared_ptr<Calculable>> toPostfix(const std::deque<Token>& tokens);

double calculatePostfix(const std::deque<std::shared_ptr<Calculable>>& postfixExpr);

#endif
