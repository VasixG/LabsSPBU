#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "list.h"


template <class T>
class Stack:public List<T>{

public:
    typedef typename List<T>::Node Node;
    Stack(): head{nullptr} {}

    Stack(const Stack<T> &s) {
        head = nullptr;

        if(!s.is_empty()){

            if(s.size() != 1){
                Node *curr_pos = s.head, *next_pos = s.head->next;
                Node *curr_pos_new = new Node(curr_pos->value), *next_pos_new = new Node(next_pos->value);
                curr_pos_new->next = next_pos_new;

                curr_pos = next_pos;
                next_pos = next_pos->next;

                Node *head_temp = curr_pos_new;
                head = curr_pos_new;
                curr_pos_new = next_pos_new;

                while(next_pos){
                    next_pos_new = new Node(next_pos->value);
                    curr_pos_new->next = next_pos_new;
                    curr_pos_new = next_pos_new;
                    curr_pos = next_pos;
                    next_pos = next_pos->next;

                }

                head = head_temp;
            }else{
                push(s.head->value);
            }

        }

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

        if(!s.is_empty()){

            if(s.size() != 1){
                Node *curr_pos = s.head, *next_pos = s.head->next;
                Node *curr_pos_new = new Node(curr_pos->value), *next_pos_new = new Node(next_pos->value);
                curr_pos_new->next = next_pos_new;

                curr_pos = next_pos;
                next_pos = next_pos->next;

                Node *head_temp = curr_pos_new;
                head = curr_pos_new;
                curr_pos_new = next_pos_new;

                while(next_pos){
                    next_pos_new = new Node(next_pos->value);
                    curr_pos_new->next = next_pos_new;
                    curr_pos_new = next_pos_new;
                    curr_pos = next_pos;
                    next_pos = next_pos->next;

                }

                head = head_temp;
            }else{
                push(s.head->value);
            }

        }

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

    virtual size_t size() const{

        size_t size_s = 0;

        Node *node = head;

        while(node){++size_s;node=node->next;}
        return size_s;
    }

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
