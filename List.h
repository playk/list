#ifndef _LISTNODE_H_
#define _LISTNODE_H_
 
#include <iostream>
#include <string>
 
template<class T>
/**
@brief list class

@detailed insert, erase, clear and print functions included
*/

class List
{
public:
        List():head(0), tail(0) /** main constructor*/
        {
        }
        
        ~List()
        {
                while(head)
                {
                    tail=head->next;
                    delete head;
                    head=tail;
                }
        }
 
        void push_back(T val)
 /** function that push elements to the end of the list */

        {
                Node* Temp;
                Temp=new Node;
                Temp->elem=val;
                if(head==0)
                {
                        head=Temp;
                        tail=Temp;
                        return;
                }
                tail->next=Temp;
                tail=Temp;
        }
 
        void print()
/** function that prints the list*/
        {
                if(head==0)
                {
                        throw std::string("List is empty!");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                {
                        std::cout<<ptr->elem<<' ';
                }
                std::cout<<'\n';
        }
 
        void push_front(T val)
        {
                
/** function that push elements to the front of the list */

                Node* Temp;
                Temp=new Node;
                Temp->elem=val;
                Temp->next=head;
                head=Temp;
        }
 
        void erase()
        {
/** function that delete elements from the list */

                if(head==0)
                {
                        throw std::string("List is empty!\n");
                }
                Node* delptr=head->next;
                head=head->next;
                delete delptr;
        }
        
        void erase(T val)
        {
 /** function that delete separete element from the list */

                Node* ptrPrev;
                ptrPrev=new Node;
                if(head==0)
                {
                        throw std::string("List is empty\n");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                {
                        if(ptr->elem==val)
                        {
                                ptrPrev->next=ptr->next;
                                delete ptr;
                                break;
                        }
                        ptrPrev=ptr;
                }
                if(ptrPrev->next==0)
                        std::cout<<"There are no elements in list equal to "<< val <<'\n';
        }
 
        void clear()
        {
/** function that delete all elements from the list */

                while(head!=0)
                        erase();
        }
 
        void find(T val)
        {
/** function that finds the element in the list */

                if(head==0)
                {
                        throw std::string("List is empty!\n");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                {
                        if(ptr->elem=val)
                                std::cout<<"Element "<< val <<" is finded\n";
                        return;
                }
                std::cout<<"Element "<< val <<" is not finded\n";
        }
        
        void insert(T val)
        {
/** function that insert element to the list */

                if(head==0)
                {
                        push_front(val);
                        return;
                }
                Node* Temp=new Node;
                Temp->elem=val;
                Node* founded=head;
                for(founded; founded!=0; founded=founded->next)
                {
                        if(founded->elem<val)
                                break;
                }
                if(founded==0)
                {
                        push_front(val);
                        return;
                }
                Temp->next=founded->next;
                founded->next=Temp;
        }
private:
        struct Node
        {
                Node():next(0), elem(0)
                {
                }
                Node* next;
                T elem;
        };
 
        Node* head;
        Node* tail;
};
 
#endif