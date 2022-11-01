#include <stack>
#include <iostream>
#include "solution.h"

bool isOpeningBracket(char bracket)
{
  if (bracket == '(' || bracket == '{' || bracket == '[')
  {
    return true;
  }
  return false;
}

bool isClosingBracket(char bracket)
{
  if (bracket == ')' || bracket == '}' || bracket == ']')
  {
    return true;
  }
  return false;
}

bool isLetter(char letter)
{
  if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
  {
    return true;
  }
  return false;
}

char getOppositeBracket(char bracket)
{
  switch (bracket)
  {
  case '(':
    return ')';
    break;
  case '{':
    return '}';
  case '[':
    return ']';
  default:
    return 0;
  }
}

bool isCorrect(const char *expression)
{
  std::stack<char> stack;

  while (*expression)
  {
    if (isClosingBracket(*expression) && stack.empty())
    {
      return false;
    }
    else if (!isLetter(*expression) && *expression != ' ')
    {
      if (isOpeningBracket(*expression))
      {
        stack.push(*expression);
      }
      else if (isClosingBracket(*expression) && !stack.empty())
      {
        if (*expression == getOppositeBracket(stack.top()))
        {
          stack.pop();
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    expression++;
  }

  return stack.empty();
}
