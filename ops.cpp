#include<iostream>
using namespace std;

struct node
{
  int data;
  node *next;
  node *prev;
};

class dlinkedlist
{
/*private:
  node *head,*tail;

 */public:
   node *head,*tail;

   dlinkedlist()
   {
    head=NULL;
    tail=NULL;
   }

   void display(node *head)
   {
     node* temp=new node;
     if(head==NULL)
     {
       cout<<"list is empty";
     }
     else
     {
       temp=head;
       while(temp->next != NULL)
       {
         cout<<temp->data<<"  ";
         temp=temp->next;
       }
     }
   }
   void addbegg(node *head,int value)
   {
     node *temp=new node;
     temp->data=value;
     temp->prev=NULL;
      if(head==NULL)
      {
        temp->next=NULL;
        head=temp;;
      }
      else
      {
        temp->next=head;
        head=temp;
      }
   }
  /*  node *gethead()
    {
      return head;
    }*/
   void addendd(node* head,int value)
   {
     node *temp= new node;
     node *curr= head;

     temp->data=value;
     temp->next=NULL;

     if(head==NULL)
     {
       temp->prev=NULL;
       head=temp;
       //temp=head;
     }
     else
     {
       //curr=head;
       while(curr->next!=NULL)
       {
          curr=curr->next;
      //   curr->next=temp;
        // temp->prev=curr;
       }
       curr->next=temp;
       temp->prev=curr;
     }
   }

   void addafterr(int pos,node* head,int value)
   {
     node *temp=new node;
     temp->data=value;
     if(head==NULL)
     {
       temp->prev=NULL;
       temp->next=NULL;
       head=temp;
     }
     else
     {
       node *temp1=head;
       node *temp2=NULL;

       for(int i=0;i<pos;i++)
       {
         temp1->next=temp1;
       }
      temp2=temp1->next;
      temp1->next=temp;
      temp->prev=temp1;
      temp->next=temp2;
      temp2->prev=temp;
     }
   }

   void delnodee(int value,node*head)
   {
      node * temp=head;
     if(head==NULL)
     {
       cout<<"list is empty";
     }
     while(temp->next!=NULL)
     {
       if(temp->next==NULL)
       {
        cout<<"the given element not found";
       }
       else
       {
         temp=temp->next;
       }
     }
     if(temp==head)
     {
      head=temp->next;
      delete temp;
     }
     else
     {
       temp->next->prev=temp->prev;
       delete temp;
     }
   }
};

int main()
{
    node *head;
     cout << "-1";
    dlinkedlist d;
     cout << "0";
     d.addendd(head,20);
     cout << "1";
     d.addendd(head,30);
     cout << "2";
     d.addbegg(head,10);
     cout << "3";
     d.display(head);
   cout << "4";
     d.addafterr(2,head,100);
     d.display(head);
     d.delnodee(30,head);
     d.display(head);

     return 0;
}
