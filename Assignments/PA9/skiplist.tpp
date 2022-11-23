// #ifndef __SKIPLIST_TPP_ // required???
// #define __SKIPLIST_TPP_

template <typename K, typename V>
Skiplist<K, V>::Node::Node() {
    nexts = new Node*[1];
    levels = 1;
    nexts[0] = nullptr;
}

template <typename K, typename V>
Skiplist<K, V>::Node::Node(K key, V value, int levels) {
    nexts = new Node*[levels];    // new
    this->levels = levels;
    this->key = key;
    this->value = value;
    
    for (int i = 0; i < levels; ++i) {  // init
        nexts[i] = nullptr;
    }
}

template <typename K, typename V>
Skiplist<K, V>::Node::~Node() {
    delete [] nexts;
}

template <typename K, typename V>
Skiplist<K, V>::Skiplist(double prob) { // no need = 0.25 cuz already in declare
    head = new Node();
    this->prob = prob;
}

template <typename K, typename V>
Skiplist<K, V>::~Skiplist() {
    Node* prevNode = head;  // set as head
    Node* curNode = prevNode->nexts[0];

    while (prevNode != nullptr) {
        delete prevNode;
        prevNode = curNode;
        if (curNode != nullptr) {   // safety
            curNode = curNode->nexts[0];
        }
    }
}

template <typename K, typename V>
Skiplist<K, V>& Skiplist<K, V>::operator=(const Skiplist<K, V>& other) {
    // clear old
    Node* prevNode = head->nexts[0];
    if (prevNode != nullptr) {
        Node* curNode = prevNode->nexts[0];
        while (prevNode != nullptr) {
            delete prevNode;
            prevNode = curNode;
            if (curNode != nullptr){    // safety
                curNode = curNode->nexts[0];
            }
        }
    }

    prob = other.prob;

    int newlev = other.head->levels;
    head->levels = newlev;
    // clear old
    delete [] head->nexts;  // dealloc
    head->nexts = new Node*[newlev];

    // initialize the headptrs
    Node** twoDNodes = new Node*[newlev];
    for (int i = 0; i < newlev; ++i) {
        twoDNodes[i] = this->head;
    }

    Node* iterNode = other.head->nexts[0];
    while(iterNode != nullptr){
        Node* curNode = new Node(iterNode->key, iterNode->value, iterNode->levels);
        for (int i = 0; i < curNode->levels; ++i) {
            twoDNodes[i]->nexts[i] = curNode;
            twoDNodes[i] = curNode;
        }

        iterNode = iterNode->nexts[0];
    }
    

    for (int i = 0; i < newlev; ++i) {  // safety
        twoDNodes[i]->nexts[i] = nullptr;
    }
    delete [] twoDNodes;

    return *this;
}

template <typename K, typename V>
Skiplist<K, V>::Skiplist(const Skiplist<K, V>& other) {
    prob = other.prob;
    head = new Node();
    *this = other;
}

template <typename K, typename V>
bool Skiplist<K, V>::get(const K& get_key, V& rtn_value) const {
    if (empty()) {
        return false;
    }

    int curlev = head->levels-1;
    Node* prevNode = head;
    Node* curNode = head->nexts[curlev];

    while (curlev != -1) {   // iteration
        if (curNode != nullptr) {
            if (curNode->key == get_key) {  // found
                rtn_value = curNode->value;
                return true;
            } 
            else if (curNode->key > get_key) { 
                curlev--;
                curNode = prevNode->nexts[curlev];
            } 
            else {  // continue iteration
                prevNode = curNode;
                curNode = curNode->nexts[curlev];
            }
        } 

        else {
            curlev--;   // go to next level
            curNode = prevNode->nexts[curlev];
        }
    }
    // if not found then return false
    return false;
}

template <typename K, typename V>
void Skiplist<K, V>::update(const K& update_key, const V& update_value) {
    int curlev = head->levels - 1;
    Node* prevNode = head;
    Node* curNode = head->nexts[curlev];
    Node** twoDNodes = new Node*[head->levels];

    while (curlev >= 0) {   // iteration
        if (curNode != nullptr) {
            if (curNode->key == update_key) {   // success
                curNode->value = update_value;
                delete [] twoDNodes;
                return;
            } 
            else if (curNode->key > update_key) {
                twoDNodes[curlev] = prevNode;
                curlev--;
                if (curlev >= 0) {
                    curNode = prevNode->nexts[curlev];
                }
            } 
            else {
                prevNode = curNode;
                curNode = curNode->nexts[curlev];
            }
        } else {    // continue iteration
            twoDNodes[curlev] = prevNode;
            curlev--;
            if (curlev >= 0) {
                curNode = prevNode->nexts[curlev];
            }
        }
    }

    Node* newNode = new Node(update_key, update_value, getRandomLevels());
    int oldLevels = head->levels;   // -1???

    if (newNode->levels > head->levels) {
        Node** newNexttwoDNodes = new Node*[newNode->levels];
        for (int i = 0; i < newNode->levels; ++i) {
            if(i < head->levels){
                newNexttwoDNodes[i] = head->nexts[i];
            }
            else{
                newNexttwoDNodes[i] = nullptr;
            }
        }

        head->levels = newNode->levels;
        delete [] head->nexts;  // clear
        head->nexts = newNexttwoDNodes;
    }
    for (int i = 0; i < newNode->levels; ++i) {
        if (i < oldLevels) {
            newNode->nexts[i] = twoDNodes[i]->nexts[i];
            twoDNodes[i]->nexts[i] = newNode;
        } 
        else if(i >= oldLevels) {
            newNode->nexts[i] = head->nexts[i];
            head->nexts[i] = newNode;
        }
    }

    delete [] twoDNodes;
}

template <typename K, typename V>
bool Skiplist<K,V>::remove(const K& remove_key) {
    bool returnflag = false;
    int curlev = head->levels-1;
    Node* prevNode = head;
    Node* curNode = head->nexts[curlev];
    Node** twoDNodes = new Node*[head->levels];

    while (curlev >= 0) {
        if (curNode != nullptr) {
            if (curNode->key == remove_key) {
                twoDNodes[curlev] = prevNode;
                curlev--;
                if (curlev >= 0) {
                    curNode = prevNode->nexts[curlev];
                }
                returnflag = true;
            } 
            else if (curNode->key > remove_key) { 
                twoDNodes[curlev] = prevNode;
                curlev--;
                if (curlev >= 0) {
                    curNode = prevNode->nexts[curlev];
                }
            } 
            else { 
                prevNode = curNode;
                curNode = curNode->nexts[curlev];
            }
        }
        else {
            twoDNodes[curlev] = prevNode;
            curlev--;
            if (curlev >= 0) {
                curNode = prevNode->nexts[curlev];
            }
        }
    }

    if (returnflag == true) {
        Node* removeNode = curNode;
        int iter;
        for (iter = 0; iter < head->levels && head->nexts[iter] != nullptr; iter++) {
            if (twoDNodes[iter]->nexts[iter] != nullptr){
                twoDNodes[iter]->nexts[iter] = removeNode->nexts[iter]; 
            }
        }

        if (iter < head->levels) {
            Node** newtwoDNodes = new Node*[iter];

            for (int j = 0; j < iter; iter++) {
                newtwoDNodes[j] = head->nexts[iter];
            }

            head->levels = iter+1;
            delete [] head->nexts;
            head->nexts = newtwoDNodes;
        }
        delete removeNode;
    }
    delete [] twoDNodes;

    return returnflag;
}

template <typename K, typename V>
int Skiplist<K,V>::size() const {
    int cnt = 0;
    Node* cntNode = head->nexts[0];
    while(cntNode != nullptr){
        cntNode = cntNode->nexts[0];
        ++cnt;
    }
    return cnt;
}

template <typename K, typename V>
bool Skiplist<K,V>::empty() const {
    if(head->nexts[0] == nullptr){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename K, typename V>
void Skiplist<K,V>::print() const {
    std::cout << "{";
    Node* curNode = head->nexts[0];
    while(curNode != nullptr){
        std::cout << curNode->key << ": " << curNode->value;
        curNode = curNode->nexts[0];
        if (curNode != nullptr) {
            std::cout << ", ";
        }
    }

    std::cout << "}" << std::endl;
}

template <typename K, typename V>
template <typename T>
Skiplist<K,T> Skiplist<K,V>::map(T (*f)(V value)) const {
    Skiplist<K, T> mapper;
    Node* iterNode = head->nexts[0];

    while(iterNode != nullptr){
        mapper.update(iterNode->key, f(iterNode->value));
        iterNode = iterNode->nexts[0];
    }
    
    return mapper;
}

template <typename K, typename V>
Skiplist<K,V> Skiplist<K,V>::filter(bool (*f)(V value)) const {
    Skiplist<K, V> filterer;
    Node* iterNode = head->nexts[0];
    
    while(iterNode != nullptr){
        if (f(iterNode->value) == true){
            filterer.update(iterNode->key, iterNode->value);
        }
        iterNode = iterNode->nexts[0];
    }

    return filterer;
}

template <typename K, typename V>
Skiplist<K,V> Skiplist<K,V>::operator+(const Skiplist<K,V>& other) const {
    Skiplist<K, V> temp;
    Node* ownIterNode = head->nexts[0];
    while(ownIterNode != nullptr){
        temp.update(ownIterNode->key, ownIterNode->value);
        ownIterNode = ownIterNode->nexts[0];
    }

    Node* otherIterNode = other.head->nexts[0];
    while(otherIterNode != nullptr){
        temp.update(otherIterNode->key, otherIterNode->value);
        otherIterNode = otherIterNode->nexts[0];
    }
    return temp;
}


// #endif 