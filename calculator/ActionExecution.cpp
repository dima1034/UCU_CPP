//
// Created by ostdm on 27-Mar-18.
//

#include "ActionExecution.h"

int ActionExecution::execute(Action action) {

    switch(action.operato_r) {
        
        case '*':
            return action.operand1 * action.operand2;
        
        case '+':
            return action.operand1 + action.operand2;

        case '-':
            return action.operand1 - action.operand2;            

        case '/':
            return action.operand1 / action.operand2;

        default: void (0);
    }
}
