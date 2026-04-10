//Less Optimised Approach
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            st.push({val,min(val,st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

//Optimized Approach
class MinStack {
public:
    stack<long long> st;   
    long long mini=1e9;    

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }else if(val>mini){
            st.push(val);
        }else{
            st.push(2LL*val - mini);   
            mini=val;
        }
    }
    
    void pop() {
        long long x=st.top();   
        st.pop();
        if(x<mini){
            mini=2LL*mini - x; 
        }
    }
    
    int top() {
        long long x=st.top();   
        if(x<mini) return mini;
        else return x;
    }
    
    int getMin() {
        return mini;
    }
};
