#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "list.h"

template <class T>
class Queue: public List<T>{
public:
    typedef typename List<T>::Node Node;
    typedef typename List<T>::iterator iterator;
    typedef typename List<T>::const_iterator const_iterator;

    Queue(): head{nullptr}, tail{nullptr} {}

    Queue(const Queue<T> &q) {
        head = nullptr;
        tail = nullptr;
        Node *temp = q.head;
        while(temp)
        {
            push(temp->value);
            temp = temp->next;
        }
    }

    Queue<T>(Queue<T> &&q): head(q.head), tail(q.tail) {head = nullptr; tail = nullptr;}

    virtual ~Queue(){
        while(head) pop();
    }

    enum ERR_CODE {EMPTY, OUT_OF_RANGE};

    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return nullptr;
    }


    const_iterator begin() const
    {
        return const_iterator(head);
    }
    const_iterator end() const
    {
        return nullptr;
    }

    const_iterator cbegin() const
    {
        return const_iterator(head);
    }
    const_iterator cend() const
    {
        return nullptr;
    }


    Queue<T> &operator = (Queue<T> &&q)
    {
        if(&q == this) return *this;
        while(head) pop();
        head = q.head;
        tail = q.tail;
        return *this;
    }


    Queue<T> &operator = (const Queue<T> &q)
    {
        if(&q == this) return *this;
        while(head) pop();
        head = nullptr;
        tail = nullptr;
        Node *temp = q.head;
        while(temp)
        {
            push(temp->value);
            temp = temp->next;
        }

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

    virtual Queue& push(const T value){
        if(tail != nullptr){
            Node *node = new Node(value);

            tail->next = node;

            tail = node;
        }else{
            Node *node = new Node(value);

            node->next = tail;

            head = node;
            tail = node;
        }

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

    virtual size_t size() const{
        size_t size_s = 0;

        Node *node = head;

        while(node){++size_s;node=node->next;}
        return size_s;

    }

    virtual bool is_empty() const {return !(head);}

private:
    Node* head, *tail;

};



#endif // QUEUE_H_INCLUDED
