class RecentCounter {
private:
    queue<int> q;
    int size;
public:
    RecentCounter() {
        size = 0;
    }
    
    int ping(int t) {
        while (!q.empty() && q.front() < t - 3000) {
            size--;
            q.pop();
        }
    q.push(t);
        size++;
        return size;
    }
};
