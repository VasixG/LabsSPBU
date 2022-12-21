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

    class const_iterator;
    class iterator;

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

    friend bool operator == (const_iterator& cit, iterator &it){
        return cit->current == it->current;
    }

    friend bool operator != (const_iterator& cit, iterator &it){
        return cit->current != it->current;
    }

    friend bool operator == (iterator& it, const_iterator &cit){
        return cit->current == it->current;
    }

    friend bool operator != (iterator& it, const_iterator & cit){
        return cit->current != it->current;
    }

    virtual iterator begin() = 0;

    virtual iterator end() = 0;

    virtual const_iterator begin() const = 0;

    virtual const_iterator end() const = 0;

    virtual const_iterator cbegin() const = 0;

    virtual const_iterator cend() const = 0;

    friend std::ostream& operator <<(std::ostream& stream, List<T>& list){
        for(auto it = list.begin(); it != list.end(); ++it){
            stream<<(*it)<<" ";
        }
        return stream;
    }

};



#endif // LIST_H_INCLUDED
