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
    stck.push(c);

    stckk = stck;

    std::cout<<stckk;

    std::cout<<stck<<'\n';
    std::cout<< stck[2];

    Stack<int> stcck(stck);

    std::cout<<stck<<'\n';
    std::cout<<stcck<<'\n';

    stck.pop();
    std::cout<<stck<<'\n';

    stck.pop();
    std::cout<<stck<<'\n';

    stck.pop();

    que.push(a);
    que.push(b);
    que.push(c);

    std::cout<<que<<'\n';

    std::cout<<que[0];
    return 0;
}
