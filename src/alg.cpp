// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priorit(char x) {
    switch (x) {
      case '(':
          return 0;
      case ')':
          return 1;
      case '+':
      case '-':
          return 2;
      case '*':
      case '/':
          return 3;
      default:
          return -1;
    }
}

std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  return std::string("");
    TStack<char> stack;
    std::string res;

    for (int i = 0; i < inf.length(); i++) {
        if ((inf[i] >= '0') && (inf[i] <= '9')) {
            res += inf[i];
            res += ' ';
        } else if (inf[i] == '(') {
            stack.push(inf[i]);
        } else if (priorit(inf[i]) > priorit(stack.get()) || stack.isEmpty()) {
            stack.push(inf[i]);
        } else if (inf[i] == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                res += stack.get();
                res += ' ';
                stack.pop();
            }

            if (stack.get() == '(') {
               stack.pop();
            }
        } else {
            while (!stack.isEmpty() && priorit(stack.get()) >= priorit(inf[i])) {
                res += stack.get();
                res += ' ';
                stack.pop();
            }

            stack.push(inf[i]);
        }
    }

    while (!stack.isEmpty()) {
        res += stack.get();
        res += ' ';
        stack.pop();
    }

    while (res[res.length() - 1] == ' ') {
        result = res.substr(0, res.length()-1);
    }

    return res;
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
    TStack<int> stack;

    for (int i = 0; i < pst.length(); i++) {
        if ((pst[i] >= '0') && (pst[i] <= '9')) {
            stack.push(pst[i] - '0');
        } else if (pst[i] != ' ') {
            int y1 = stack.get();
            stack.pop();
            int y2 = stack.get();
            stack.pop();

            if (pst[i] == '-') {
                stack.push(y2 - y1);
            } else if (pst[i] == '+') {
                stack.push(y2 + y1);
            } else if (pst[i] == '*') {
                stack.push(y2 * y1);
            } else {
                stack.push(y2 / y1);
            }
        }
    }

    return stack.get();
}
