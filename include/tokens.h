#ifndef tokens_H
#define tokens_H

#include <string>
#include <deque>

enum TokenType
{
    NUM_INT,
    NUM_FLO,
    PAR_L,
    PAR_R,
    PLUS,
    MINUS,
    MUL,
    DIV
};

class Token
{

  std::string m_value;
  TokenType m_token_type;

public:
  Token(const std::string& value, const TokenType& token_type): m_value(value), m_token_type(token_type) {}
  Token(const Token& token): m_value(token.m_value), m_token_type(token.m_token_type) {}

  std::string getValue() const
  {
    return m_value;
  }

  TokenType getType() const
  {
    return m_token_type;
  }
};

std::deque<Token> lexAnalyse(const std::string& expression);

#endif
