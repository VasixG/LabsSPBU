#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "list.h"
#include <ostream>

template <class T>
class Stack:public List<T>{

public:
    typedef typename List<T>::Node Node;
    Stack(): head{nullptr} {}

    Stack(const Stack<T> &s) {
        head = nullptr;

        Stack<T> *temp_st = new Stack<T>;

        Node *temp = s.head;


        while(temp)
        {
            temp_st->push(temp->value);
            temp = temp->next;
        }

        Node *temp_2 = temp_st->head;

        while(temp_2)
        {
            push(temp_2->value);
            temp_2 = temp_2->next;
        }

        delete temp_st;
        delete temp;
    }

    Stack<T>(Stack<T> &&s): head(s.head) {s.head = nullptr; }

    virtual ~Stack(){
        while(head) pop();
    }

    enum ERR_CODE {EMPTY, OUT_OF_RANGE};

    Stack<T> &operator = (const Stack<T> &s)
    {
        if(&s == this) return *this;
        while(head) pop();

        head = nullptr;

        Stack<T> *temp_st = new Stack<T>;

        Node *temp = s.head;

        while(temp)
        {
            temp_st->push(temp->value);
            temp = temp->next;
        }

        Node *temp_2 = temp_st->head;

        while(temp_2)
        {
            push(temp_2->value);
            temp_2 = temp_2->next;
        }

        delete temp_st;
        delete temp;

        return *this;
    }


    Stack<T> &operator = (Stack<T> &&s)
    {
        if(&s == this) return *this;
        while(head) pop();

        head = s.head;

        return *this;
    }

    T operator [](size_t i) const{
        if (is_empty())throw EMPTY;
        Node *node = head;
        while(node != nullptr && i!=0){
            --i;
            node = node->next;
        }
        if(!i && node != nullptr)return node->value;
        throw OUT_OF_RANGE;
    }

    virtual Stack& push(const T value){
        Node *node = new Node(value);

        node->next = head;

        head = node;

        return *this;
    }

    virtual T pop(){
        if(!is_empty()){
            Node *node = head;

            T val = head->value;
            head = head->next;

            delete node;

            return val;
        }else{
            throw EMPTY;
        }
    }

    virtual T get_front() const{
        return head->value;
    }

    bool is_empty() const{return !(head);}

protected:
    void print(std::ostream& stream) const{
        if(is_empty()){throw EMPTY;}
        Node *node = head;
        stream<<"head->";
        while(node != nullptr){
            stream<<node->value<<' ';
            node = node->next;
        }
    }

private:
    Node *head;
};



#endif // STACK_H_INCLUDED
