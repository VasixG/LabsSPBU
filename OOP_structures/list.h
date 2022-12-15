#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <ostream>

//abstract class of list
template <class T>
class List{
protected:

    struct Node{
        T value;
        struct Node* next;

        Node(const T _value = T(),struct Node* _next = nullptr): value{_value}, next{_next} {}
    };


public:
    virtual ~List(){}

    virtual List& push(const T value) = 0;

    virtual T pop() = 0;

    virtual bool is_empty() const = 0;

    virtual T get_front() const = 0;

    virtual size_t size() const = 0;

};



#endif // LIST_H_INCLUDED
