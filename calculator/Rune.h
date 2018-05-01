//
// Created by ostdm on 27-Mar-18.
//

#ifndef UNTITLED_RUNE_H
#define UNTITLED_RUNE_H


class Rune {
public:
    char kind_of;
    int value;
    
    // not sure about explicit
    explicit Rune(char ch)
            :kind_of(ch), value(0) { }
    Rune(char ch, int val)
            :kind_of(ch), value(val) { }
};


#endif //UNTITLED_RUNE_H
