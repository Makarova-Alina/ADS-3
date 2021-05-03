// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

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
    TStack<char> stack;
    std::string str;
    for (int i = 0; i < inf.length(); i++) {
        if ((inf[i] >= '0') && (inf[i] <= '9')) {
            str += inf[i];
            str += ' ';
        } else if (stack.isEmpty())
            || (inf[i] == '(')
            || (priorit(inf[i]) > priorit(stack.get()))) {
            stack.push(inf[i]);
        } else if (inf[i] == ')') {
            char tp = stack.get();
            while (tp != '(') {
                str += tp;
                str += ' ';
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && (priorit(stack.get()) >= priorit(inf[i]))) {
                str += stack.get();
                str += ' ';
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }
    while (!stack.isEmpty()) {
            str += stack.get();
            str += ' ';
            stack.pop();
    }
    str.pop_back();
    return str;
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
  TStack<int> stack;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9')) {
      stack.push(pst[i] - '0');
    } else if (pst[i] != ' ') {
      int y2 = stack.get();
      stack.pop();
      int y1 = stack.get();
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
