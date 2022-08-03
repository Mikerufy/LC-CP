class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
   bool book(int start, int end) {
        pair<int,int>p = {start,end};
        for(auto it : v){
            if(!(start >= it.second)){
                if(!(end <= it.first)){
                return false;
                }
            }

        }
        v.push_back(p);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */