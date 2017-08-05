//Create a doubly linked linst with a sort function.

#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


class Employee{
    
public:
    
    Employee(){};
    
    void setName(string n){ name = n;};
    void setId(int i){ id = i;};
    void setPay(double pay){pay_rate = pay;};
    void setData(int i, double pay, string n){ id = i, pay_rate=pay,name = n;};
    void setHours(int h){ hours += h;}
    
    int getId()const{ return id;};
    int getH()const{ return hours;};
    string getName()const{ return name;};
    double getPay()const{return pay_rate;};
    double getpRoll()const{return pay_rate * hours;};
    
    void print() const;
    
private:
    
    int id;
    double pay_rate;
    string name;
    int hours;
};

void Employee::print() const
{
    cout <<"Id:" << id <<" "<<pay_rate <<" " << name <<" hours"<< hours<<endl;
}

class List
{
private:
typedef struct node
{
    Employee data;
    node* next;
    node* prev;
        
}*nodePtr;
    
    nodePtr head;
    nodePtr tail;
    nodePtr curr;
    nodePtr temp;
    void sort( nodePtr &head )
    {
        nodePtr a = NULL;
        nodePtr b = NULL;
        if( head == NULL ||  head->next == NULL ) {
            return;
        }
        split( head , a , b );
        sort( a );
        sort( b );
        head = sortedMerge( a , b );
    }
    nodePtr sortedMerge( nodePtr a , nodePtr b )
    {
        nodePtr mergeHead;
            if( a == NULL ) {
            return b;
        }
        else if( b == NULL ) {
            return a;
        }
        if( a->data.getpRoll() >= b->data.getpRoll() ) {
            mergeHead = a;
            while( b != NULL ) {
                if( a->data.getpRoll() >= b->data.getpRoll() ) {
                    if( a->next == NULL ) {
                        a->next = b;
                        b->prev = a;
                        break;
                    }
                    a = a->next;
                }
                else {
                    nodePtr add = b;
                    b = b->next;
                    add->prev = a->prev;
                    a->prev->next = add;
                    add->next = a;
                    a->prev = add;
                }
            }
        }
        else {
            mergeHead = b;
            while( a != NULL ) {
                if( b->data.getpRoll() >= a->data.getpRoll() ) {
                    if( b->next == NULL ) {
                        b->next = a;
                        a->prev = b;
                        break;
                    }
                    b = b->next;
                }
                else {
                    nodePtr add = a;
                    a = a->next;
                    add->prev = b->prev;
                    b->prev->next = add;
                    add->next = b;
                    b->prev = add;
                }
            }
        }
        return mergeHead;
    }
    void split( nodePtr head , nodePtr &front , nodePtr &back )
    {
        nodePtr fast;
        nodePtr slow;
        if( head == NULL || head->next == NULL ) {
            front = head;
            back = NULL;
        }
        else {
            slow = head;
            fast = head->next;
            while( fast != NULL ) {
                fast = fast->next;
                if( fast != NULL )
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            front = head;
            back = slow->next;
            back->prev = NULL;
            slow->next = NULL;
        }
    }
public:
    List();
    ~List();
    void AddToBack(Employee addData);
    void addHoursbyId(int id, int h);
    Employee PopFront();
    void PrintForward();
    void PrintPayRoll();
    int size =0;
    void sort();
};

List::List(){
    head=NULL;
    tail=NULL;
    curr=NULL;
    temp=NULL;

}
List::~List(){
    while(head!=NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}
void List::AddToBack(Employee addData)
{
    nodePtr n =new node;
    n->next =NULL;
    n->data = addData;
    if(head !=NULL){
        n->prev = tail;
        tail->next =n;
        tail = n;
    }
    else
    {
        head = n;
        tail = n;
    }
    tail->next = NULL;
    size++;
}
void List::sort(){
    
    sort( head );
    node* findTail = head;
    while( findTail != nullptr ) {
        if( findTail->next == nullptr ) {
            tail = findTail;
        }
        findTail = findTail->next;
    }
}

Employee List::PopFront(){
    Employee e;
    temp = head;
    curr = head;
    if(curr !=NULL){
        if(size==1){
            e = curr->data;
            delete curr;
            head=tail=NULL;
            size--;
            return e;
        }
        else{
            curr = head->next;
            curr->prev=NULL;
            e = head->data;
            delete head;
            head = curr;
            size--;
            return e;
        }
    }
    else
        cout<<"empty";
        return e;
}

void List::addHoursbyId(int id,int h)
{
    curr = head;
    while(curr !=NULL&&curr->data.getId()!=id){
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<id<<" is not in the list\n";
    }
    else{
        curr->data.setHours(h);
    }
}

void swap(Employee* a, Employee* b)
{
    Employee t = *a;
    *a = *b;
    *b=t;
}


void List::PrintForward(){
    temp = head;
    while(temp !=NULL) {
        temp->data.print();
        temp=temp->next;
    }
    cout<<endl;
}
void List::PrintPayRoll(){
    temp = head;
    while(temp !=NULL) {
        cout<<temp->data.getName()<<"   $ ";
        cout<<temp->data.getpRoll();
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

void openInputFile(ifstream& inFile){
    string filename;
    cout<<"What filename? ";
    cin>>filename;
    inFile.open(filename);
    while(!inFile){
        cout<<"Failed to open!"<<endl;
        cout<<"Enter filename? ";cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main() {
    ifstream inFile;
    ifstream inFile2;

    openInputFile(inFile);
    List listEmployees;
    List listHours;
    openInputFile(inFile2);
    
    int id;
    double p;
    string n;
    
    while(inFile>>id){
        inFile>>p;
        inFile.ignore(9999, ' ');
        getline(inFile, n);
        Employee temp;
        temp.setData(id, p, n);
        listEmployees.AddToBack(temp);
    }
    
    int i;
    int h;
    while(inFile2>>i){
        inFile2>>h;
        Employee t;
        listEmployees.addHoursbyId(i, h);
    }
//    listEmployees.PrintForward();
    listEmployees.sort();
    
    cout<<"********PAYROLL*******\n\n";
    listEmployees.PrintPayRoll();
    cout<<"**********END*********\n\n";
    return 0;
}






