class LRUCache {
private:
struct Node{
  int key , value ;
  Node* prev ;
  Node* next ;

  Node(int k , int v){
    key = k ;
    value = v ;
    prev = next = nullptr; 
  }


};

int capacity ;
unordered_map<int , Node*>cache ;

Node* head ;
Node* tail ;

public:
    LRUCache(int capacity) {
        this->capacity = capacity ;

        head = new Node(-1 , -1) ;
        tail = new Node(-1 , -1) ;


        head->next = tail ;
        tail->prev = head ;

    }

    void removeNode(Node* node){
     Node* before = node->prev ;
     Node* after = node->next ;

     before->next = after ;
     after->prev = before ;


    }

    void insertAfterHead(Node* node){

        Node* first = head->next;

        head->next = node ;
        node->prev = head ;
         
         node->next = first ;
         first->prev = node ;



    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1 ;

        }

        Node* node = cache[key] ;

        removeNode(node) ;
        insertAfterHead(node) ;

        return node->value ;
        
        
    }
    
    void put(int key, int value) {

        if(cache.find(key) != cache.end()){
            Node* node = cache[key] ;
            node->value = value ;

            removeNode(node) ;
            insertAfterHead(node) ;

            return ;

        }

        if(cache.size() == capacity){
            Node* lru = tail->prev ;
            cache.erase(lru -> key) ;
            removeNode(lru) ;
            delete lru ;

        }

        Node* node = new Node(key , value) ;
        cache[key] = node;
        insertAfterHead(node) ;


        
    }
};
