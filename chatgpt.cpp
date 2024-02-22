#include <iostream>
#include <string>

using std::string;
using std::cout;


struct Payload;
struct Vector;
struct List;
struct VectorIterator;
struct ListIterator;

// Payload struct
struct Payload {
    static int counter;
    int id;
    string name;

    Payload(string n = "") : id(++counter), name(n) { say_born(); }
    ~Payload() { say_die(); }
    Payload(const char * n) : Payload(string(n)) {}
    Payload(const Payload & x) : id(++counter), name(x.name) { say_born(); }
    Payload(Payload && x) : id(++counter), name(x.name) { say_born(); }
    void operator=(const Payload & x) { name = x.name; }
    void say_born() const;
    void say_die() const;
    void print() const;
};

int Payload::counter = 0;

void Payload::say_born() const {
    cout << '(' << name << " is born)\n";
}

void Payload::say_die() const {
    cout << '(' << name << " dies)\n";
}

void Payload::print() const {
    cout << '(' << name << ')';
}

struct VectorIterator {

    Payload *current;


    VectorIterator(Payload *ptr) : current(ptr) {}

    VectorIterator& operator++() {
        ++current;
        return *this;
    }

    bool operator!=(const VectorIterator& other) const {
        return current != other.current;
    }

    Payload& operator*() const {
        return *current;
    }
};


struct ListIterator {

    Node *current;

    ListIterator(Node *node) : current(node) {}

    ListIterator& operator++() {
        current = current->next_link;
        return *this;
    }

    bool operator!=(const ListIterator& other) const {
        return current != other.current;
    }

    Payload& operator*() const {
        return current->instance;
    }
};

// Node struct
struct Node {
    Payload instance;
    Node *next_link;
    Node(Payload n) : instance(n), next_link(nullptr) {}
};

// List class
struct List {
    Node *Head_List;


    List() : Head_List(nullptr) {}
    ~List();

    void push_front(const Payload& name);
    void pop_front();
    void push_back(const Payload& name);
    void pop_back();
    int size() const;
    void print() const;
    bool empty() const;
    Payload front() const;
    Payload back() const;

  // Iterator-related functions
    typedef ListIterator iterator;

    iterator begin() const { 
        return iterator(Head_List); 
    }

    iterator end() const { 
        return iterator(nullptr); 
};

List::~List() {
    while (Head_List != nullptr) {
        Node* temp = Head_List;
        Head_List = Head_List->next_link;
        delete temp;
    }
}

void List::push_front(const Payload& name) {
    Node *newNode = new Node(name);
    newNode->next_link = Head_List;
    Head_List = newNode;
}

void List::pop_front() {
    if (Head_List == nullptr) {
        cout << "No elements inside the list" << '\n';
    } else {
        Node *temp = Head_List->next_link;
        delete Head_List;
        Head_List = temp;
    }
}

void List::push_back(const Payload& name) {
    if (Head_List == nullptr) {
        Head_List = new Node(name);
    } else {
        Node* tail = Head_List;
        while (tail->next_link != nullptr) {
            tail = tail->next_link;
        }
        tail->next_link = new Node(name);
    }
}

void List::pop_back() {
    if (Head_List == nullptr) {
        cout << "No elements inside the list" << '\n';
        return;
    } else if (Head_List->next_link == nullptr) {
        delete Head_List;
        Head_List = nullptr;
        return;
    } else {
        Node* tail = Head_List;
        while (tail->next_link->next_link != nullptr) {
            tail = tail->next_link;
        }
        delete tail->next_link;
        tail->next_link = nullptr;
    }
}

int List::size() const {
    int counter = 0;
    Node *temp = Head_List;
    while (temp != nullptr) {
        temp = temp->next_link;
        counter++;
    }
    return counter;
}

void List::print() const {
    Node *temp = Head_List;
    while (temp != nullptr) {
        temp->instance.print();
        temp = temp->next_link;
    }
}

bool List::empty() const {
    return Head_List == nullptr;
}

Payload List::front() const {
    if (Head_List == nullptr) {
        cout << "No objects inside the list" << '\n';
        throw "Error";
    } else {
        return Head_List->instance;
    }
}

Payload List::back() const {
    if (Head_List == nullptr) {
        cout << "No objects inside the list" << '\n';
        throw "Error";
    } else {
        Node *temp = Head_List;
        while (temp->next_link != nullptr) {
            temp = temp->next_link;
        }
        return temp->instance;
    }
}

// Vector class
struct Vector {

    int VecCounter;
    static const int VecMax = 4;
    int IdVec;
    int Capacity;
    Payload *Objects;


    Vector();
    ~Vector();

    void push_back(const Payload& name);
    void pop_back();
    void push_front(const Payload& name);
    void pop_front();
    int size() const;
    int capacity() const;
    void print() const;
    bool empty() const;
    Payload front() const;
    Payload back() const;

    // Iterator-related functions
    typedef VectorIterator iterator;

    iterator begin() const { 
        return iterator(Objects); 
    }

    iterator end() const { 
        return iterator(Objects + VecCounter); 
    }
};

Vector::Vector() : VecCounter(0), IdVec(0), Capacity(1), Objects(new Payload[Capacity]) {}

Vector::~Vector() {
    delete[] Objects;
}

void Vector::push_back(const Payload& name) {
    if (Capacity <= VecCounter) {
        Capacity = 2 * Capacity;
        Payload* temp = new Payload[Capacity];
        for (int i = 0; i < VecCounter; ++i) {
            temp[i] = Objects[i];
        }
        delete[] Objects;
        Objects = temp;
    }
    Objects[VecCounter] = name;
    ++VecCounter;
}

void Vector::pop_back() {
    if (VecCounter <= 0) {
        cout << "Vector is empty. No objects to pop_back." << "\n";
    } else {
        Objects[VecCounter - 1].~Payload();
        --VecCounter;
    }
}

void Vector::push_front(const Payload& name) {
    if (Capacity <= VecCounter) {
        Capacity = 2 * Capacity;
        Payload* temp = new Payload[Capacity];
        for (int i = 0; i < VecCounter; ++i) {
            temp[i] = Objects[i];
        }
        delete[] Objects;
        Objects = temp;
    }
    for (int i = VecCounter; i > 0; i--) {
        Objects[i] = Objects[i - 1];
    }
    Objects[0] = name;
    ++VecCounter;
}

void Vector::pop_front() {
    if (VecCounter <= 0) {
        cout << "Vector is empty. No objects to pop_front." << "\n";
    } else {
        for (int i = 0; i < VecCounter - 1; i++) {
            Objects[i] = Objects[i + 1];
        }
        --VecCounter;
    }
}

int Vector::size() const {
    return VecCounter;
}

int Vector::capacity() const {
    return


//modify function
template <class C> void modify(C & v)
{
   
   for ( auto & i : v )
   {
    
    i.name += '!';
   
   }
    
}


template <class C> void print(C & v)
{
cout << "print:";
for ( auto & i : v )
cout << ' ' << i.name;
cout << '\n';
}


int main()
{
Vector v;
for(int i=0; i<10; i++)
v.push_back(std::to_string(i));
modify(v);
print(v);
List s;
for(int i=0; i<10; i++)
s.push_front(std::to_string(i));
modify(s);
print(s);
}
