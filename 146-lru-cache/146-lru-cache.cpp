class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// class par{
//   public:
//     int first;
//     int second;
//     par(int f, int s){
//         first = f;
//         second = s;
//     }
// };
// class LRUCache {
//     unordered_map<int,par*> m;
//     queue<par> q;
//     int size;
// public:
//     LRUCache(int capacity) {
//         size = capacity;
//     }
    
//     int get(int key) {
        
//         while(!q.empty()){
//             cout<<q.front().first<<" "<<q.front().second<<endl;
//             q.pop();
//         }
        
//         int value=-1;
//         //if(m.find(key)==m.end()){
// //             par* pp = m[key]; 
// //             value = pp->second;
// //             //cout<<value<<endl;
// //             if(value!=-1){
// //                 pp->second = -1;
// //                 size++;
// //             }else return value;
            
// //             par p(key,value);
// //             m[key] = &p;
// //             q.push(p);
//         //}
//         return value;
//     }
    
//     void put(int key, int value) {
        
//         if(!m.empty() && m.find(key) != m.end()){
//             //par* pp = m[key];
//             cout<<m[key].second<<endl;
//             //pp->second = -1;
//             size++;
//         }
//         par p(key,value);
//         m[key] = &p;

//         while(q.front().second == -1){
//                 q.pop();
//                 size--;
//         }
        
//         int count = q.size();
//         if(count < size){
//             q.push(p);
//         }else{
//             par temp = q.front();
//             m.erase(temp.first);
//             q.pop();
//             q.push(p);
//         }
        
//     }
// };