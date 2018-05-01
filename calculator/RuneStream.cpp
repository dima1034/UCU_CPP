//
// Created by ostdm on 27-Mar-18.
//

#include "RuneStream.h"
#include "iostream"

Rune RuneStream::get() {

    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case '=':    // for "print"
        case 'x':    // for "quit"
        case '(': case ')': case '{': case '}':
        case '+': case '-': case '*': case '/':
        case '!':
            return Rune(ch);
        
        // cos sin
        case 's': case 'i': case 'n':
        case 'c': case 'o': 
        { 
            return { 's', ch }; 
        }
        
        // numbers
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            std::cin.putback(ch);         
            int val;
            std::cin >> val;              
            return {'n', val};
        }
        default: void(0);
    }
}

RuneStream::RuneStream(): has_previous_number(false) {}
