#include <iostream>
#include <vector>
#include "stack.h"


bool IsParenthesisBalanced(const std::string& expression)
{
    IStack<char>* s = new LinkedListStack<char>();
    for (int i = 0; i < expression.size(); i++)
    {
        char character = expression[i];
        if (character == '(')
            s->push(character);
        else if (character == ')')
        {
            if (s->isEmpty())
                return false;//case 1
            s->pop();
        }
    }
    return s->isEmpty();//true : case2, false : case3
}

bool IsParenthesisBalanced_2(const std::string& expression)
{
    IStack<char>* s = new LinkedListStack<char>();
    for (int i = 0; i < expression.size(); i++)
    {
        char character = expression[i];
        if (character == '(')
            s->push(character);
        else if (character == ')')
        {
            if (s->isEmpty())
                return false;//case 1
            if (s->pop() != '(')
                return false;
        }
        else if (character == '{')
            s->push(character);
        else if (character == '}')
        {
            if (s->isEmpty())
                return false;
            if (s->pop() != '{')
                return false;
        }
    }
    return s->isEmpty();//true : case2, false : case3
}
/*

int main()
{
    cout << IsParenthesisBalanced("((a+b)*(c-d))") << endl;//true (case 2)
    cout << IsParenthesisBalanced("(((a+b)*(c-d))") << endl;//false (case 3)
    cout << IsParenthesisBalanced("((a+b)*(c-d)))") << endl;//false (case 1)
    cout << endl;
    cout << IsParenthesisBalanced_2("{((a+b)*(c-d))}") << endl;//true 
    cout << IsParenthesisBalanced_2("{({a+b}*(c-d))}") << endl;//true 
    cout << IsParenthesisBalanced_2("{({a+b}*(c-d)})") << endl;//false
    cout << IsParenthesisBalanced_2("{((a+b)*(c-d)})") << endl;//false 
    cout << IsParenthesisBalanced_2("{((a+b)*(c-d))})") << endl;//false 
    cout << IsParenthesisBalanced_2("{((a+b)*(c-d)))}") << endl;//false 

    return 0;
}
*/