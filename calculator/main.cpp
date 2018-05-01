#include <iostream>
#include <stack>
#include "RuneStream.h"
#include "ActionExecution.h"

void executeExpression(Rune             rune, 
                       std::stack<char> &operator_stack, 
                       std::stack<int>  &number_stack, 
                       ActionExecution  &actionExecution, 
                       RuneStream       &runeStream) {

    switch(rune.kind_of) {

        case 's':
            
            runeStream.buffer.push_back(rune.value);
            break;
        
        case 'n':

            runeStream.has_previous_number = true;
            number_stack.push(rune.value);
            break;

        case '=':
           
            
//            TODO: throw?
            if (number_stack.size() - 1 != operator_stack.size()) throw;
            
            while (number_stack.size() != 1)
            {
                int operand1 = number_stack.top();
                number_stack.pop();

                int operand2 = number_stack.top();
                number_stack.pop();

                number_stack.push(actionExecution.execute(
                        Action(
                                operator_stack.top(),
                                operand2,
                                operand1
                        )));
                
                operator_stack.pop();
            }

            std::cout << number_stack.top() << std::endl;
            number_stack.pop();
            
            break;

        case ')':
        {
            int operand2 = number_stack.top();
            number_stack.pop();

            int operand1 = number_stack.top();
            number_stack.pop();

            number_stack.push(actionExecution.execute(
                    Action(
                            operator_stack.top(),
                            operand1,
                            operand2
                    )));

            operator_stack.pop();
            break;
        }
        case '*': case '/': 
        {
            auto next_rune = runeStream.get();

            if (runeStream.has_previous_number && next_rune.kind_of == 'n') {
                auto previous_number = number_stack.top();
                auto result_number = actionExecution.execute(
                        Action(
                                rune.kind_of,
                                previous_number,
                                next_rune.value
                        ));


                number_stack.pop();
                number_stack.push(result_number);
                runeStream.has_previous_number = false;

                break;
            }

            operator_stack.push(rune.kind_of);
            break;
        }
        case '+': case '-':

            operator_stack.push(rune.kind_of);
            break;

        default:
            void(0);
    }
}

int main() {

    auto runeStream      = RuneStream();
    auto actionExecution = ActionExecution();
    std::stack<char> operator_stack;
    std::stack<int> number_stack;
    
    while (std::cin) {
        Rune rune = runeStream.get();
        executeExpression(rune, operator_stack, number_stack, actionExecution, runeStream);
    }
    return 0;
}
