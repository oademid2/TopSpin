//

#include <iostream>
using namespace std;

template <class T>
class CDLL{
    
private:
    class Node{
public:
        Node(T val, Node * nx=NULL, Node * prv = NULL ) : value(val), next(nx),prev(prv){ }
        T value;
        Node * next;
        Node * prev;
    };
    
    
private:
    Node * m_head;
    Node * m_tail;
    unsigned int m_size;
    
public:
    CDLL();
    ~CDLL();
    
    void addData(T d); //will add a new node to the end of the linked list with value d
    void incrementHead(); //will advance head to next node
    void decrementHead(); //will move head to previous node
    void swap(unsigned int src,unsigned int dst); //will swap the data in the 2 nodes (easier than swapping the nodes themselves)
    T getData(unsigned int i) const; //will return the data associated in the i-th node of the list
    
};



template <class T>
CDLL<T>::CDLL():m_head(NULL), m_tail(NULL), m_size(NULL){}

template <class T>
void CDLL<T>::addData(T d){
    
    if (m_head == NULL)//If the list is currently empty
    {
        m_head = new Node(d, m_head, m_head); // create a new node at the head
        
        m_tail = m_head; //the tail will also be considered the head
        m_tail->next = m_tail;//the tail will point next to itself
        m_tail->prev = m_tail;//the tai; will point back to itself
        m_size++; // the size will increase by one
        
        
    }else{//if list is not empty
        
        Node * oldTail = m_tail; //store the current address/value of the tail
        
        // a new tail next to where the current tail is -- set the value at this point to be d and it's next pointer to head and its previous pointer to the old tail (hold)
        m_tail = m_tail->next = new Node(d, m_head, oldTail );
        
        oldTail->next = m_tail;//the old tail is now pointng to the new tail
        m_head->prev = m_tail; //the previous pointer for the head is now pointing to the new tail
        m_tail->next = m_head; //the new tail points to the head next
        m_size++; //increase size by 1
        
    }

}

template <class T>
void CDLL<T>::incrementHead(){
    
    Node* here = m_head;
    T temp = m_head->value;//store value at the head
    
    //hold = here;
    for (unsigned int k = 1; k <= m_size; k++){
        here->value = here->prev->value; //change the value at each node to be the one before
        here = here->prev; //now move back one and do it again
    };
    
    m_head->next->value = temp; //The head value has already been changed so instead of the value besied head usin prev-> value it uses the stored head value
    
}

template <class T>
void CDLL<T>::decrementHead(){
    
    
    Node* here = m_head;
    int temp = m_head->value;//store value at the head
    
    for (unsigned int k = 1; k <= m_size; k++){//change the value at each node to be the one after
        here->value = here->next->value;
        here = here->next; //now move up and do it again
    };
    
    m_tail->value = temp;//The tauk value has already been changed so instead of the value beside tail using prev-> value it uses the stored head value
    
    
    
}

template <class T>
T CDLL<T> :: getData( unsigned int n ) const {
    if(1<=n && n<=m_size){
        if (n == 1) return m_head->value;
        Node * here = m_head;
        for (unsigned int k = 1; k < n; k++ ) here = here->next;
        return here->value;
    }
    return NULL;
}

template <class T>
void CDLL<T>::swap(unsigned int src,unsigned int dst){
    
    //T returnValue;
    Node * here = m_head;
    Node * here2 = m_head;
    
    int holdSrc = getData(src);//store the src value
    int holdDst = getData(dst);//store the dst value
    
    
    for (unsigned int k = 1; k < src; k++){
        here = here->next; //start at the head and find the src node
    }
    here->value = holdDst; //the src node now has the dst value
    
    for (unsigned int k = 1; k < dst; k++){
        here2 = here2->next;//start at the head and find dst node
    }
    here2->value = holdSrc; //dst node now has src value
  
}

template <class T>
CDLL<T> :: ~CDLL( ) {
    Node * here = m_head, * nextNode; //create a node which holds the head node and is the value of the next node
    
    while (m_size) { //while there is a list
        nextNode = here->next; // the value at the next node is now the value that was before
        delete here; //delete the present node
        m_size--;
        here = nextNode; //now the present node is what was considered the next node
    }
}















/*

*/
