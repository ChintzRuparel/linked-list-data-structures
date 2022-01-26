#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
class DoubleyLL
{
    node *head= new node;
public:    DoubleyLL()
    {
        head=NULL;
    }


void insertbeg(int x)
{
    node *first = new node;
    first->prev=NULL;
    first->next=head;
    first->data=x;
    if(head==NULL)
    {
        head=first;
    }
    else
    {
        head->prev=first;
        head=first;
    }
}
int counter()
    {
        int c=0;
        node *current=head;
        if(head==NULL)
        {
            cout<<"empty list"<<endl;

        }
        else
        {
            while(current!=NULL)
            {
                current = current->next;
                c++;
            }
        }
        return c;
    }
void insertany(int x)
{
      int counte=counter();
        int pos;
        cout<<"enter position="<<endl;
        cin>>pos;
        node *mid=new node();
        mid->data=x;
        node *temp=head;
        node *temp2;
        if(pos==0)
        {
            insertbeg(x);
        }
        else if(pos==counte)
        {
            insertend(x);
        }
        else if(pos>counte)
        {
            cout<<"invalid position"<<endl;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            mid->next=temp->next;
            mid->prev=temp;
            temp->next=mid;
            temp2->prev=mid;
        }

}
void insertend(int x)
{
    node *last = new node;
    last->data=x;
    last->next=NULL;
    node *tail;
    tail=head;
    if(head==NULL)
    {
        insertbeg(x);
    }
    else
    {
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        last->prev=tail;
        tail->next=last;
    }
}
 void deletebeg()
    {
        if(head==NULL)
        {
            cout<<"empty list"<<endl;
        }
        else
        {
            node *temp=head;
            head=temp->next;
            head->prev=NULL;
            delete temp;
        }
    }
     void deleteend()
    {
        if(head==NULL)
        {
            cout<<"empty list"<<endl;
        }
        else if(head->next==NULL)
        {
            deletebeg();
        }
        else
        {
            node *current=head;
            node *temp;
            while(current->next!=NULL)
            {
                temp=current;
                current=current->next;
            }
            temp->next=NULL;
            delete current;
        }
    }
    void deleteany()
    {
        int counte=counter();
        int pos;
        cout<<"enter pos="<<endl;
        cin>>pos;
        node *temp=head;
        node *temp2=temp->next;
        if(head==NULL)
        {
            cout<<"empty list"<<endl;

        }
        else if(pos==0)
        {
            deletebeg();
        }
        else if(pos==counte)
        {
            deleteend();
        }
        else if(pos>counte)
        {
            cout<<"invalid pos"<<endl;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
               temp=temp->next;
               temp2=temp2->next;
            }
            temp->next=temp2;
            temp2->prev=temp;
            temp=temp->next;
            delete temp;
        }
    }
void display()
{
     node *prev;
        prev = head;
        int i = 0;
        if(head==NULL)
            cout<<"LIST IS EMPTY";
        else
        {
        do
        {
            cout<<"\nNode: "<<i;
            cout<<"\nData: "<<prev -> data<<endl;
            prev = prev -> next;
            i++;
        }
        while(prev != NULL);
        }
}
};
int main()
{
    int ch,value;
    DoubleyLL obj;
    while(ch!=8){
    cout<<"Enter\n1 - insert beginning\n2 - insert any\n3 - insert end\n4 - display\n5 - delete beg\n6 - delete any\n7 - delete end\n8 - exit"<<endl;
    cout<<"Enter choice="<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter data="<<endl;
        cin>>value;
        obj.insertbeg(value);
        break;
    case 2:
        cout<<"Enter data="<<endl;
        cin>>value;
        obj.insertany(value);
        break;
    case 3:
        cout<<"Enter data="<<endl;
        cin>>value;
        obj.insertend(value);
        break;
    case 4:
       obj.display();
       break;
    case 5:
        obj.deletebeg();
        break;
    case 6:
        obj.deleteany();
        break;
    case 7:
        obj.deleteend();
        break;
    case 8:
        break;
    default:
        cout<<"invalid input"<<endl;
    }
    }
}
