// Step 1: Define a stack to hold brackets
// Step 2: Traverse the expression from left to right
// Step 2.1: If the character is opening bracket (, or { or [, then push it into stack
// Step 2.2: If the character is closing bracket ), } or ] Then pop from stack, and if the popped character is matched with the starting bracket then it is ok. otherwise they are not balanced.
// Step 3: After traversal if the starting bracket is present in the stack then it is not balanced.




#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string expr) {
   stack<char> s;
   char ch;
   for (int i=0; i<expr.length(); i++) {    //for each character in the expression, check conditions
      if (expr[i]=='('||expr[i]=='['||expr[i]=='{') {    //when it is opening bracket, push into     stack
         s.push(expr[i]);
         continue;
      }
      if (s.empty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
         return false;
         switch (expr[i]) {
            case ')':    //for closing parenthesis, pop it and check for braces and square brackets
               ch = s.top();
               s.pop();
               if (ch=='{' || ch=='[')
                  return false;
                  break;
            case '}': //for closing braces, pop it and check for parenthesis and square brackets
               ch = s.top();
               s.pop();
               if (ch=='(' || ch=='[')
                  return false;
                  break;
            case ']': //for closing square bracket, pop it and check for braces and parenthesis
               ch = s.top();
               s.pop();
               if (ch =='(' || ch == '{')
                  return false;
                  break;
         }
      }
      return (s.empty()); //when stack is empty, return true
}
main() {
   string expr = "[{}(){()}]";
   if (isBalanced(expr))
      cout << "Balanced";
   else
      cout << "Not Balanced";
}
