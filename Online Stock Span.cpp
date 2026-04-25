//Brute Force Approach
class StockSpanner {
public:
    vector<int> arr;   
    StockSpanner() {
        //empty
    }
    int next(int price) {
        arr.push_back(price);
        int cnt = 1;
        for(int i = arr.size() - 2; i >= 0; i--){
            if(arr[i] <= price){
                cnt++;
            }
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//Optimal Approach
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind;
    StockSpanner() {
        ind = -1;
    }
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
