//
// Created by ostdm on 27-Mar-18.
//

#ifndef UNTITLED_RUNESTREAM_H
#define UNTITLED_RUNESTREAM_H


#include "Rune.h"
#include "Action.h"
#include <vector>

class RuneStream {
public:
    RuneStream();
    Rune get();  
    bool has_previous_number;
    std::vector<char> buffer; 
};

#endif //UNTITLED_RUNESTREAM_H
