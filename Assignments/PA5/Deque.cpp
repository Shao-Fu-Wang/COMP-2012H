#include "Deque.h"
#include <iostream>
#include <fstream>

//if ($?) { g++ Deque_Iterator.cpp Deque.cpp main.cpp -o main } ; if ($?) { .\main }

Deque create_deque() {
    Deque new_deque;
    Node *sentinel = new Node; 
    Node *normal_node = new Node;
    
    sentinel->next = normal_node;
    sentinel->prev = normal_node;
    normal_node->next = sentinel;
    normal_node->prev = sentinel;
    Iterator it;
    set_node(it, normal_node);
    it.current = it.first;

    new_deque.start = it;
    new_deque.end = it;
    new_deque.sentinel = sentinel;
    new_deque.ll_size = 1;
    return new_deque;
}

void destroy_deque(Deque& deque) {
    Node* nodeiter = deque.sentinel->next;
    while (nodeiter != deque.sentinel) {
        nodeiter = nodeiter->next;
        delete nodeiter->prev;
    }
    delete deque.sentinel;
    deque.sentinel = nullptr;
}

Iterator begin(const Deque& deque) {
    return deque.start;
}

Iterator end(const Deque& deque) {
    return deque.end;
}

int front(const Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot get front: deque is empty" << endl;
        return -1;
    } else {
        return *deque.start.current; // guarunteed to be an element
    }
}

int back(const Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot get back: deque is empty" << endl;
        return -1;
    } else {
        return *(prev(deque.end).current); // before it is guarunteed to be an element
    }
}

bool empty(const Deque& deque) { // should be correct
    return equal(deque.start, deque.end);
}

int size(const Deque& deque) { // should be correct
    if (deque.ll_size == 1) {
        return (deque.end.current - deque.start.current);
    } else {
        return (deque.ll_size - 2) * CHUNK_SIZE  + (deque.end.current - deque.end.first) + (deque.start.last - deque.start.current);
    }
}

void push_back(Deque& deque, int val) {
    if (deque.end.current == deque.end.last) {
        // create new node
        Node* new_node = new Node;
        deque.ll_size++;
        // linking the new node
        new_node->next = deque.sentinel;
        new_node->prev = deque.sentinel->prev;
        deque.sentinel->prev->next = new_node;
        deque.sentinel->prev = new_node;

        set_node(deque.end, new_node);
        deque.end.current = deque.end.first;
    }

    *deque.end.current = val;
    deque.end = next(deque.end);
}

void push_front(Deque& deque, int val) {
    if (deque.start.current == deque.start.first) {
        // create new node
        Node* new_node = new Node;
        deque.ll_size++;
        // linking the new node
        deque.sentinel->next->prev = new_node;
        new_node->next = deque.sentinel->next;
        deque.sentinel->next = new_node;
        new_node->prev = deque.sentinel;
        
        set_node(deque.start, new_node);
        deque.start.current = deque.start.last;
    }
    deque.start = prev(deque.start);
    *deque.start.current = val;
}

void pop_back(Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot pop_back: deque is empty" << endl;
        return;
    }
    if(deque.end.current == deque.end.first){
        Node* del_node = const_cast<Node *>(deque.end.node);
        deque.end.node->prev->next = deque.sentinel;
        deque.sentinel->prev = deque.end.node->prev;  
        deque.end = prev(deque.end); 
        delete del_node;
        deque.ll_size--;
        deque.end.current = deque.end.last - 1;
    }
    else{
        deque.end = prev(deque.end);
    }
    /** 
     * [0][1][2][3][4][5][6][7]:8:
     * if 8 ~ 2:
     * - dec end by 1
     * if 1: 
     * - if node in front is not sentinel (i.e. last element in array)
     *   - pop and do not decrement 
     * - else
     *   - pop and set to prev array's :8:
     * 
     */
    // cout << deque.end.current << " " << *deque.end.current << " " << prev(deque.end.current) << " " << *prev(deque.end.current) << endl;
    // if (deque.end.current == deque.end.first + 1) {
    //     if (deque.ll_size <= 1) {
    //         deque.end = prev(deque.end);
    //     } else {
    //         // del node
    //         Node* del_node = const_cast<Node *>(deque.end.node);
    //         del_node->prev->next = del_node->next;
    //         deque.sentinel->prev = del_node->prev;
    //         deque.end = prev(prev(deque.end)); // putting this before del_node prevents accessing freed memory
    //         delete del_node;
    //         deque.ll_size--;
    //         // set to :8:
    //         deque.end.current++;
    //     }
    // } else if (deque.end.current == deque.end.first) { // for the case at start up
    //     Node* del_node = const_cast<Node *>(deque.end.node);
    //     deque.end = prev(deque.end);
    //     del_node->prev->next = del_node->next;
    //     deque.sentinel->prev = del_node->prev;
    //     delete del_node;
    //     deque.ll_size--;
    // } else {
    //     deque.end = prev(deque.end);
    // }
 }

void pop_front(Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot pop_front: deque is empty" << endl;
        return;
    }
    if(deque.start.current == deque.start.last - 1){
        Node* del_node = const_cast<Node *>(deque.start.node);
        deque.start.node->next->prev = deque.sentinel;
        deque.sentinel->next = deque.start.node->prev;  
        deque.start = next(deque.start); 
        delete del_node;
        deque.ll_size--;
        deque.start.current = deque.start.first;
    }
    else{
        deque.start = next(deque.start);
    }
    // cout << deque.start.first << " " << *deque.start.current << " " << next(deque.start.current) << " " << *next(deque.start.current) << endl;
    /**
     * [0][1][2][3][4][5][6][7]:8:
     * if 0 ~ 6:
     * - inc end by 1
     * if start.current is 7: 
     * - if ll = 1:
     *  - set end.current to 7
     * - else
     *  - del node and move to next array
     * 
     */
    // if (deque.start.current == prev(deque.start.last)) {
    //     if (deque.ll_size <= 1) {
    //         deque.end = deque.start;
    //     } else {
    //         Node* del_node = const_cast<Node *>(deque.start.node);
    //         deque.start = next(deque.start);
    //         del_node->next->prev = del_node->prev;
    //         deque.sentinel->next = del_node->next;
    //         delete del_node;
    //         deque.ll_size--;
    //     }
    // }  else {
    //     deque.start = next(deque.start);
    // }
}

// #define DEBUG_PRINT
void print_deque(const Deque& deque) {
    Iterator iter = deque.start;
    cout << "[";
    if(!empty(deque)){
        while (!equal(iter, prev(deque.end))) {
            cout << *iter.current;
            cout << ", ";
            iter = next(iter);
        }
        cout << *prev(deque.end).current;
    }
    cout << "]" << endl;
}

void insert(Deque& deque, const Iterator& pos, int val) {
    // cout << pos.current << " " << val << " " << deque.start.current << " " << deque.end.current << endl;
    /**
     * [0][1][2][3][4][5][6][7]:8: [0][1][2][3][4]...
     * 
     * it = [1]
     * 
     * temp = [1]
     * [1] = val
     * val = temp
     * 
     * it++
     * 
     * temp = [2]
     * [2] = val
     * val = temp
     * 
     * it++
     * 
     * etc.
     * until it reaches prev(end)
     * then just simply push_back(val)
     * assumption: deque is non-empty
     */
    Iterator iter = prev(deque.end);
    int temp = back(deque);
    while (!equal((pos), iter)) {
            *iter.current = *prev(iter).current;
            iter = prev(iter);
    }
    *pos.current = val;
    push_back(deque, temp);

    // int temp;
    // Iterator it = pos;

    // if (!equal(pos, deque.end)) {
    //     temp = *it.current;
    //     *it.current = val;
    //     val = temp;

    //     while (!equal(it, prev(deque.end))) {
    //         it = next(it);
    //         temp = *it.current;
    //         *it.current = val;
    //         val = temp;
    //     }
    // }

    // push_back(deque, val);

}

void erase(Deque& deque, const Iterator& pos) {
    /**
     * [0][1][2][3][4][5][6][7]:8: [0][1][2][3][4]...
     * 
     * del [2]:
     * 
     * if [2] is not prev(end), then
     * [2] = [3]
     * it = [3]
     * if [3] is not prev(end), then
     * [3] = [4]
     * it = [4]
     * if [4] is not prev(end), then
     * [4] = [5]
     * it = [5]
     * since [5] is prev(end), we stop
     * pop_back()
     * 
     * ...
     * until it = prev(end)
     * then just simply pop_back(end)
     * assumption: deque has at least one element
     * 
     * if only one element, simply popback
     * 
     */
    

    Iterator iter = pos;
    while (!equal(iter, prev(deque.end))) {
            *iter.current = *next(iter).current;
            iter = next(iter);
    }
    pop_back(deque);
    // *pos.current = val;
    // push_back(deque, temp);

    // Iterator it = pos;

    // while(!equal(it, prev(deque.end))) {
    //     *it.current = *(next(it).current);
    //     it = next(it);
    // }

    // while (!equal(next(it), prev(deque.end))) { // todo: debug this
    //     *it.current = *(next(it).current);
    //     it = next(it);
    // }

    // if (size(deque) > 1) {
    //     *it.current = *(next(it).current);
    //     while (!equal(next(it), prev(deque.end))) {
    //         it = next(it);
    //         *it.current = *(next(it).current);
    //     }
    // }

    // pop_back(deque);
}

void store_deque(const Deque& deque, const char* filename) {
    ofstream ofs(filename);
    Iterator iter = deque.start;

    if(ofs.is_open()){
        if(!empty(deque)){
            while (!equal(iter, prev(deque.end))) {
                ofs << *iter.current << endl;
                iter = next(iter);
            }
            ofs << *prev(deque.end).current;
        }
        ofs.flush();
        ofs.close();
    }
    
    // ofstream ofs(filename);
    // Iterator it = deque.start;
    // ofs << size(deque) << endl;
    // if (!empty(deque)) {
    //     ofs << *it.current << endl;
    //     while (!equal(it, prev(deque.end))) {
    //         it = next(it);
    //         ofs << *it.current << endl;
    //     }
    // }
    // ofs.close();
}

Deque load_deque(const char* filename) {
    ifstream ifs(filename);
    Deque deque = create_deque();

    int item;
    if (ifs.is_open()){
        while(ifs >> item){
            push_back(deque, item);
        }
        
    }
    ifs.close();
    return deque;

    // int size, temp;
    // ifs >> size;
    // for (; size > 0; size--) {
    //     ifs >> temp;
    //     push_back(deque, temp);
    // }
    // ifs.close();
    // return deque;
}