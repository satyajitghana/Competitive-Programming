//I enjoyed this problem!
class StockSpanner {
public:
    StockSpanner() {
        
    }
    //vector<int> V;
    stack<int> p;
    stack<int> c;
    
    int next(int price) {
        int count=1;
        //p.push(price);
        //c.push(count);
        while(!p.empty()&&p.top()<=price)
        {
            count=count+c.top();
            p.pop();
            c.pop();
        }
        p.push(price);
        c.push(count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
