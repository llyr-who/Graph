template<typename Item>
class Stack
{
private:
  struct node
  {
    Item item; node* next;
    node(Item x, node* t)
    {
      item = x;
      next = t;
    }
  };
  node* head;
public:
  Stack(int){
    head = 0;
  }
  int empty() const{
    return head ==0;
  }
  void push(Item x){
    head = new node(x,head);
  }
  Item pop(){
    Item v = head->item;
    node * t = head->next;
    delete head;
    head = t;
    return v;
  }
};
