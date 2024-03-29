void insertbottom(stack<int> &stack, int x)
{
    if(stack.empty())
    {
        stack.push(x);
        return;
    }

    int num=stack.top();
    stack.pop();
    insertbottom(stack, x);
    stack.push(num);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty())
    {
        return;
    }
    int num=stack.top();
    stack.pop();

    reverseStack(stack);

    insertbottom(stack,num);
}
