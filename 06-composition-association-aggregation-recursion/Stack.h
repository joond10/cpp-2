#ifndef SDDS_STACK_H__
#define SDDS_STACK_H__

//COMPOSITION EXAMPLE

/*
A stack in C++ is a data structure that works on the principle of "last in, first out" (LIFO). It's like a stack of plates where you can only take the top plate off the stack.
In C++, a stack is typically implemented as an adapter over other data structures like arrays or linked lists. It has operations like push and pop.

Push: Adds an element to the top of the stack.
Pop: Removes the element from the top of the stack.
You can think of it like a container where you can only add or remove elements from one end, the top. 
This makes it useful for many algorithms and problems, like keeping track of function calls in recursion, undo functionality in text editors, and more.

Each node of a stack is essentially an element knows where the next one is,
that is, it is an entity, one part of the node keeps data of the node and the second part points to another node.
a stack automatically points to the top node. When we add a new node, it points to the top node and the stack now
points at the new node. 

THIS is composition. The creation of the nodes are the responsibility of a stack
*/

//Forward declaration
template <typename T>
class Stack;
template <typename T>
class Node {
    //Node pointer points to next
    Node<T>* m_next = nullptr;
    //Holds the data for specific node
    T m_data;
    Node(T data, Node<T>* next) {
        m_next = next;
        m_data = data;
    }
    //Class is fully private so stack is a friend
    friend class Stack<T>;
    virtual ~Node() {
    }
};

template <typename T>
class Stack {
    //Pointing to the top node
    Node<T>* top{};
    int size{};
public:
    Stack<T>& push(T data) {
        //Creates a node pushing the data in it
        top = new Node<T>(data, top);
        //Incrementing the size of it
        size++;
        return *this;
    }
    T pop() {
        T val{ top->m_data };
        Node<T>* todel = top;
        top = top->m_next;
        delete todel;
        size--;
        return val;
    }
    bool isEmtpy() {
        return top == nullptr;
    }
    operator bool() {
        return top != nullptr;
    }
    virtual ~Stack() {
        Node<T>* todel = top;
        while (top != nullptr) {
            top = top->m_next;
            delete todel;
            todel = top;
        }
    }
    size_t depth() {
        return size;
    }
};


#endif // ! SDDS_STACK_H__