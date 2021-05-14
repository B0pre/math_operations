#include "tokens.h"

#include <regex>
#include <stdexcept>

TokenType analyseValue(const std::string& token)
{
    if(token == "+")
        return PLUS;
    if(token == "-")
        return MINUS;
    if(token == "*")
        return MUL;
    if(token == "/")
        return DIV;
    if(token == "(")
        return PAR_L;
    if(token == ")")
        return PAR_R;

    std::regex exprInt("^[0-9]*$");
    if( regex_search(token, exprInt) )
        return NUM_INT;

    std::regex exprFlo("^[0-9]*(\\.?[0-9]+)$");
    if( regex_search(token, exprFlo) )
        return NUM_FLO;

    throw std::invalid_argument("invalid token " + token);
}

std::deque<Token> lexAnalyse(const std::string& expression)
{
  std::regex exprRegex("[-+*/\\(\\)]|[0-9]*(\\.?[0-9]+)");
  std::smatch match;

  std::string::const_iterator searchStart (expression.cbegin());
  std::deque<Token> tokens;
  while( regex_search(searchStart, expression.cend(), match, exprRegex) )
  {
    Token token(match[0], analyseValue(match[0]));
    tokens.push_back(token);
    searchStart = match.suffix().first;
  }
  return tokens;
}
