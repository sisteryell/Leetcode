class SmallestInfiniteSet {
    int curr;
    priority_queue<int,vector<int>,greater<int>>pq;
    unordered_set<int> us;
public:
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int x=pq.top();
            pq.pop();
            us.erase(x);
            return x;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num<curr and us.find(num)==us.end()){
            pq.push(num);
            us.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */