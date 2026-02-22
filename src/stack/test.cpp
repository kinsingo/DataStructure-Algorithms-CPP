#include "stack.h"

void Test(IStack<int>* s)
{
    try
    {
        s->push(1);
        s->push(2);
        s->push(3);
        s->push(4);
        s->push(5);

        cout << s->peek() << endl;
        cout << s->peek(0) << ", " << s->peek(4) << endl;
        while (s->isEmpty() == false)
        {
            cout << s->pop() << " " << endl;
        }
    }
    catch (const exception& ex)
    {
        cout << "error:" << ex.what() << endl;
    }

}

/*
int main()
{
    Test(new ArrayStack<int>(5));
    cout << endl;
    Test(new LinkedListStack<int>());

    return 0;
}
*/