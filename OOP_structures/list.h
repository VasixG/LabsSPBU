#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <ostream>

template <class T>
class List{
public:
    virtual ~List(){}
    virtual List& push(const T value) = 0;
    virtual T pop() = 0;
    virtual bool is_empty() const = 0;
    virtual T get_front() const = 0;

protected:
    struct Node{
        T value;
        struct Node* next;

        Node(const T _value = T(),struct Node* _next = nullptr): value{_value}, next{_next} {}
    };

    friend std::ostream& operator << (std::ostream &stream, const List& lst){

        lst.print(stream);

        return stream;
    }
    virtual void print (std::ostream& stream) const = 0;

};



#endif // LIST_H_INCLUDED
