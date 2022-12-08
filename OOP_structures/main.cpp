#include <iostream>
#include "list.h"
#include "stack.h"
#include "queue.h"

int main()
{
    Stack<int> stck, stckk;
    Queue<int> que;

    int a = 5, b = 8, c = 7;

    std::cout<<stck.is_empty()<<'\n';

    stck.push(a);
    stck.push(b);

    Stack<int> stcck(stck);

    std::cout<<stck<<'\n';
    std::cout<<"--------\n";
    std::cout<<stcck<<'\n';
    std::cout<<"--------\n";

    return 0;
}
