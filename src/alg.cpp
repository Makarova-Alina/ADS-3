// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
#include <stack>

int priorit(char x) {
    if ((x == '+') || (x == '-'))
        return 2;
    else if ((x == '*') || (x == '/'))
        return 3;
    else
        return 0;
}
std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  return std::string("");
  std::stack<char> stack;
    std::string str;
    for (int i = 0; i < inf.length(); i++) {
        if ((inf[i] >= '0') && (inf[i] <= '9')) {
            str = str + inf[i];
            str = str + " ";
        } else if ((stack.empty()) || (inf[i] == '(') || (priorit(inf[i] > priorit(stack.top())))) {
            stack.push(inf[i]);
        } else if (inf[i] == ')') {
            while (stack.top() != '(') {
                str = str + stack.top();
                str = str + ' ';
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.empty() && (priorit(stack.top()) >= priorit(inf[i]))) {
                str = str + stack.top();
                str = str + ' ';
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }
     if (!stack.empty()) {
         while (!stack.empty()) {
            str = str + stack.top();
            str = str + ' ';
            stack.pop();
         }
     }
    str.pop_back();
    return str;
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
  std::stack<char> stack;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9')) {
      stack.push(pst[i] - '0');
    } else if (pst[i] != ' ') {
      int y2 = stack.top();
      stack.pop();
      int y1 = stack.top();
      stack.pop();
      if (pst[i] == '+') stack.push(y1 + y2);
        else if (pst[i] == '-') stack.push(y1 - y2);
        else if (pst[i] == '*') stack.push(y1 * y2);
        else
            stack.push(y1 / y2);
    }
  }
  return stack.top();
}
