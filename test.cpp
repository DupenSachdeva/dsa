#include <iostream>

using namespace std;

class node {
public:

  int data;
  node* next;

  node(int data){
       this->data = data;
    }
};

node* create(int l){
      
      node *head = new node(90) ;

      node *curr = head;

      while(l>0){
        curr->next = new node(l);
        curr = curr->next;
        l--;
      }

      curr->next = NULL;

      return head;


}

void print(node *head){
    
    node *curr = head;

    while(curr!=NULL){
        cout<<endl<<curr->data;
        curr = curr->next;
    }

}


int main() {
      
      int size = 5;

      node * head = create(5);

      cout<<head;
      
      print(head);
      

   

    return 0;
}
