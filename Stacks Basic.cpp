//in-built function
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    //push operation
    s.push(2);
    s.push(3);
    //pop operation
    s.pop();
    //top operation
    cout<<"the top element is "<<s.top()<<endl;
    //checking for emptiness
    if(s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"stack is not empty"<<endl;
    }

    //creating stacks function
#include <iostream>
using namespace std;
class stack{
  public:
  int *arr;
  int top;
  int size;
  
  stack(int size)
  {
      this->size = size;
      arr = new int(size);
      top = -1;
  }
  
  void push(int element)
  {
    if(size-top>1)  
    {
        top++;
        arr[top]=element;
    }
    else
    {
        cout<<"stack overflow "<<endl;
    }
  }
  void pop()
  {
      if(top>=0)
      {
        top--;
      }
      else
      {
        cout<<"stack empty "<<endl;
      }
  }
  
  int peak()
  {
      if(top>=0)
      {
        return arr[top];
      }
      else
      {
          cout<<"empty stack "<<endl;
      }
  }
  
  bool isempty()
  {
      if(top==-1)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
};

int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.peak()<<endl;
    st.pop();
    cout<<st.peak()<<endl;
    st.pop();
    cout<<st.isempty()<<endl;
    cout<<st.peak()<<endl;
    st.pop();
    st.peak();
    st.pop();
    cout<<st.isempty();
    
    
}
      cout<<"size of stack "<<s.size()<<endl;

}
