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

    class const_iterator;
    class iterator
    {
    private:
        typename List<T>::Node *current;
    public:

        iterator(typename List<T>::Node* current = nullptr)
        {
            this->current = current;
        }
        ~iterator() {};

        T& operator  *() const
        {
            return current->value;
        }
        T* operator ->() const
        {
            return &current->value;
        }

        iterator& operator++()
        {
            this->current = this->current->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator a = *this;
            ++*this;
            return a;
        }

        iterator operator +(unsigned n) const
        {
            if (n == 0)
                return *this;
            else if (n > 0)
            {
                iterator it2 = *this;
                for(unsigned int i= 0; i < n; ++i, ++it2);
                return it2;
            }

        }

        iterator& operator += (unsigned n)
        {
            return *this + n;
        }
        bool operator == (const iterator& it) const
        {
            return this->current == it.current;
        }
        bool operator != (const iterator& it) const
        {
            return this->current != it.current;
        }

        friend const_iterator;
    };

    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return nullptr;
    }

    class const_iterator
    {
    private:
        typename List<T>::Node *current;
    public:

        const_iterator(typename List<T>::Node* current = nullptr)
        {
            this->current = current;
        }
        ~const_iterator() {};

        const T& operator  *() const
        {
            return current->value;
        }
        const T* operator ->() const
        {
            return &current->value;
        }

        const_iterator& operator++()
        {
            this->current = this->current->next;
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator a = *this;
            ++*this;
            return a;
        }

        const_iterator operator +(unsigned n) const
        {
            if (n == 0)
                return *this;
            else if (n > 0)
            {
                const_iterator it2 = *this;
                for(unsigned int i= 0; i < n; ++i, ++it2);
                return it2;
            }

        }

        const_iterator& operator += (unsigned n)
        {
            return *this + n;
        }
        bool operator == (const const_iterator& it) const
        {
            return this->current == it.current;
        }
        bool operator != (const const_iterator& it) const
        {
            return this->current != it.current;
        }
    };

    friend operator == (const_iterator& cit, iterator &it){
        return cit->current == it->current;
    }

    friend operator != (const_iterator& cit, iterator &it){
        return cit->current != it->current;
    }

    friend operator == (iterator& it, const_iterator &cit){
        return cit->current == it->current;
    }

    friend operator != (iterator& it, const_iterator & cit){
        return cit->current != it->current;
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

private:
    Node *head;
};



#endif // STACK_H_INCLUDED
