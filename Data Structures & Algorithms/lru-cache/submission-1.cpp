class LRUCache {

private:
struct Node{
    int key , value ;
    Node* next ;
    Node* prev ;
    
    Node(int k , int v ){
        key = k  ;
        value = v ;
        next = prev = nullptr ;
        
    }

   
   

};

 int capacity ;
    unordered_map<int , Node*>cache ;

    Node* head ;
    Node* tail;


public:
    LRUCache(int capacity) {
        this->capacity = capacity ;
         
         head = new Node(-1  , -1) ;
         tail = new Node(-1 , -1) ;
         

         head->next = tail ;
         tail->prev = head ;
        
    }

    void RemoveNode(Node* node){
        Node* before = node->prev ;
        Node* after = node->next ;

        before->next = after ;
        after->prev = before ;

    }

    void InsertAfterHead(Node* node){
        Node* some = head->next  ;

        node->prev = head ;
        head->next = node ;
        
        some->prev = node ;
        node->next = some ;


    }




    
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1 ;

        }
        
        Node* node = cache[key] ;

        RemoveNode(node);
        InsertAfterHead(node) ;
         
        return node->value ;
        
        
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
          Node* node = cache[key] ;
          node->value = value ;

          RemoveNode(node);
          InsertAfterHead(node) ;

          return;

        }

        if(cache.size() == capacity){
            Node* lru = tail->prev ;
            cache.erase(lru->key) ;
            RemoveNode(lru);
            delete lru ;

        }

        Node* node = new Node(key , value) ;
        cache[key] = node ;
        InsertAfterHead(node) ;

    }
};
