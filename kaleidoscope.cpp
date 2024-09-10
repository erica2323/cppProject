#include <iostream>
#include "lexer.cpp"

// Function to get token names for easy debugging.
std::string getTokenName(int Tok) {
  switch (Tok) {
    case tok_eof: return "eof";
    case tok_def: return "def";
    case tok_extern: return "extern";
    case tok_identifier: return "identifier";
    case tok_number: return "number";
    default: return std::string(1, (char)Tok);
  }
}

// Main REPL loop to test the lexer.
void handleInput() {
  while (true) {
    std::cout << "ready> ";
    int Tok = gettok();
    std::cout << "Received token: " << getTokenName(Tok) << std::endl;
  }
}

int main() {
  std::cout << "Kaleidoscope Lexer - Type some code and press Enter" << std::endl;
  handleInput();
  return 0;
}

//
//  kaleidoscope.cpp
//  cppProject
//
//  Created by erica chen on 9/10/24.
//

#include "kaleidoscope.hpp"
