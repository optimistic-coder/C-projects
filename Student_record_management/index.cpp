#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    int rollno;
    string name;
    string dept;
    Node* next;
};

Node* head = new Node();

int check(int number){
    if(head==NULL){
        return false;
    }
    Node* t = new Node;
    t = head;

    while (t!=NULL)
    {
       if(t->rollno == number){
           return true;
       }
       t = t->next;
    }
    return false;
    
}

void insert_student(int rollno,string name,string dept){

    Node* t = new Node;
   if(check(rollno)){
       cout<<"Student already exists"<<endl;
       return;
   }

   //inserting at begining
    t->rollno = rollno;
    t->name = name;
    t->dept = dept;
    t->next =head;
    head = t;

    cout<<"Student inserted in link list successfully"<<endl;

}

void search_student(int rollno){
    Node* p = new Node;
    p =head;
    while (p!=NULL)
    {
        if(p->rollno==rollno){
            cout<<"NAME : "<<p->name<<endl;
            cout<<"ROLL NO : "<<p->rollno<<endl;
            cout<<"DEPT : "<<p->dept<<endl;
            return;
        }
        p=p->next;
    }
    
}
void delete_student(){
  
   Node* temp =head;
   head =head->next;
   delete(temp);
   cout<<"record deleted"<<endl;

}

void display(){
    Node* p = new Node;
    p = head;
    if(p==NULL){
        cout<<"No records display"<<endl;
        return;
    }
    while(p->next!=NULL){
       cout<<"NAME : "<<p->name<<endl;
       cout<<"ROLL NO : "<<p->rollno<<endl;
       cout<<"DEP : "<<p->dept<<endl;
       p = p->next;
    }

}

int main(){
    char choice;
    string name,dept;
    

    int rollno,input;

 

    do{
        cout<<"1. insert students"<<endl;
        cout<<"2. search students"<<endl;
        cout<<"3. delete students"<<endl;
        cout<<"4. show students"<<endl;
        cin>>input;

        switch (input)
        {
        case 1:
                cout<<"Enter student rollno : "<<endl;
                cin>>rollno;
                cout<<"Enter student name : "<<endl;
                cin>>name;
                cout<<"Enter student dept : "<<endl;
                cin>>dept;
                insert_student(rollno,name,dept);
            break;
        case 2:
            cout<<"ENter roll no : "<<endl;
            cin>>rollno;

            search_student(rollno);
            break;
        case 3:
           delete_student();
        break;
        case 4:
            display();
            break;
        default:
            cout<<"Wrong choice"<<endl;
            break;
        }

        cout<<"Do you want to continue y/n : ";
        cin>>choice;

    }while(choice=='Y'||choice=='y');

    return 0;
}