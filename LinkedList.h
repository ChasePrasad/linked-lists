/*
    Name: Chase Prasad
    Lab Partner: Tomas Chavarria
    Title: Linked List
*/

#pragma once
using namespace std;

template<typename T>
class LinkedList
{
    public:
        //Constructor for the LinkedList object, which initializes an empty list and sets first and last to nullptrs
        LinkedList<T>()
        {
            first = nullptr;
            last = nullptr;
        }

        //Destructor for the LinkedList object, which makes use of the clear function to properly delete all the nodes
        ~LinkedList()
        {
            this->clear();
        }

        //Creating the node structure
        struct Node
        {
            T data;
            Node* next;
            Node* previous;
            Node(T _data, Node *_next = nullptr, Node *_last = nullptr) : data(_data), next(_next), previous(_last){}
        };

        //Nested class that creates an Iterator object
        class Iterator
        {
            public:
                T operator*() const
                {
                    return currentNode->data;
                }

                Iterator& operator++()
                {
                    this->currentNode = this->currentNode->next;
                    return *this;
                }

                Iterator& operator--()
                {
                    this->currentNode = this->currentNode->previous;
                    return *this;
                }

                bool operator==(Iterator const& rhs)
                {
                    if (currentNode == rhs.currentNode)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                bool operator!=(Iterator const& rhs)
                {
                    if (currentNode == rhs.currentNode)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }

                Node* currentNode = nullptr;

        };

        //Iterator functions (iterates through the created linked list)
        Iterator begin() const
        {
            Iterator beginning;
            beginning.currentNode = first;
            return beginning;
        }

        Iterator tail() const
        {
            Iterator ending;
            ending.currentNode = last;
            return ending;
        }

        Iterator end() const
        {
            Iterator ending;
            ending.currentNode = nullptr;
            return ending;
        }

        //Linked List manipulation functions
        bool isEmpty() const
        {
            if (first == nullptr && last == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        T getFront() const
        {
            return first->data;
        }

        T getBack() const
        {
            return last->data;
        }

        bool contains(T element) const
        {
            for(Iterator curr = begin(); curr != end(); ++curr)
            {
                if(curr.currentNode->data == element)
                {
                    return true;
                }
            }

            return false;
        }

        //Adds a new element to the back of the list
        void enqueue(T element)
        {
            Node *newNode = new Node(element);

            if(first == nullptr)
            {
                first = newNode;
                last = newNode;
                first->previous = nullptr;
                last->next = nullptr;
            }
            else
            {
                last->next = newNode;
                newNode->previous = last;
                last = last->next;
                last->next = nullptr;
            }
        }

        //Removes an element from the front of the list
        void dequeue()
        {
            if (first != nullptr && last != nullptr)
            {
                if(first->next != nullptr)
                {
                    first = first->next;
                    delete first->previous;
                    first->previous = nullptr;
                }
                else
                {
                    delete first;
                    first = nullptr;
                    last = nullptr;
                }
            }
        }

        //Removes an element from the back of the list
        void pop()
        {
            if (first != nullptr && last != nullptr)
            {
                if (last->previous != nullptr)
                {
                    last = last->previous;
                    delete last->next;
                    last->next = nullptr;
                }
                else
                {
                    delete last;
                    first = nullptr;
                    last = nullptr;
                }
            }
        }

        //Removes all elements from the list
        void clear()
        {
            while(first != nullptr)
            {
                remove(first->data);
            }
        }

        //Removes a selected element from the list
        void remove(T element)
        {
            for(Iterator curr = begin(); curr != end(); ++curr)
            {
                if(curr.currentNode != nullptr && curr.currentNode->next != nullptr && curr.currentNode->previous != nullptr)
                {
                    if(curr.currentNode->data == element)
                    {
                        curr.currentNode->previous->next = curr.currentNode->next;
                        curr.currentNode->next->previous = curr.currentNode->previous;
                        delete curr.currentNode;
                        break;
                    }
                }
                else if(curr.currentNode != nullptr && curr.currentNode->next != nullptr)
                {
                    if(curr.currentNode->data == element)
                    {
                        first = curr.currentNode->next;
                        delete first->previous;
                        first->previous = nullptr;
                        break;
                    }
                }
                else if(curr.currentNode != nullptr && curr.currentNode->previous != nullptr)
                {
                    if(curr.currentNode->data == element)
                    {
                        last = curr.currentNode->previous;
                        delete last->next;
                        last->next = nullptr;
                        break;
                    }
                }
                else if(curr.currentNode != nullptr)
                {
                    if(curr.currentNode->data == element)
                    {
                        delete curr.currentNode;
                        first = nullptr;
                        last = nullptr;
                        break;
                    }
                }
            }
        }

        //Declares first and last as attributes of the linked list, which helps for iteration
        Node* first = nullptr;
        Node* last = nullptr;
};