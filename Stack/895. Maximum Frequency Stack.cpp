class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int mf = 0;
    FreqStack() {
    }
    
    void push(int val) {
        mf = max(mf,++freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int x = m[mf].top();
        m[mf].pop();
        freq[x]--;
        if(m[mf].size()==0) mf--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */