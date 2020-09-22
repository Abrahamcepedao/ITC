#ifndef Node_h
#define Node_h
template<class T>
class Node{
    private:
        T data;
        Node<T> *next;
    public:
        Node();
        Node(T data);
        Node(T data, Node<T> *next);

        //set Data
        void setData(T data){this->data = data;};
        void setNext(Node<T> *next){this->next = *next;};
        //get Data
        T getData(){return data;};
        Node<T>* getNext(){return *next;};
        
        //push
        //insert
        //apend
};

template<class T>


#endif
