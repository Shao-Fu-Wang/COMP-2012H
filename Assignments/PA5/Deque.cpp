#include "Deque.h"
#include <iostream>
#include <fstream>

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
        return *deque.start.current; 
    }
}

int back(const Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot get back: deque is empty" << endl;
        return -1;
    } else {
        return *prev(deque.end).current; 
    }
}

bool empty(const Deque& deque) { 
    return equal(deque.start, deque.end);
}

int size(const Deque& deque) { 
    if (empty(deque)) {
        return 0;
    }
    else if (deque.ll_size == 1) {
        return (deque.end.current - deque.start.current);
    } 
    else {
        return (deque.ll_size-2)*CHUNK_SIZE  + (deque.end.current-deque.end.first) + (deque.start.last-deque.start.current);
    }
}

void push_back(Deque& deque, int val) {
    if (deque.end.current == deque.end.last) { 
        Node* new_end = new Node;
        deque.ll_size++;
        new_end->next = deque.sentinel;
        new_end->prev = deque.sentinel->prev;
        deque.sentinel->prev->next = new_end;
        deque.sentinel->prev = new_end;

        deque.end = next(deque.end);
        *(deque.end.current-1) = val; 
     } 
     else {
        
        *(deque.end.current++) = val;
     }
}

void push_front(Deque& deque, int val) {
    if (deque.start.current == deque.start.first) {
        Node* new_start = new Node;
        deque.ll_size++;
        new_start->next = deque.sentinel->next;
        new_start->prev = deque.sentinel;
        deque.sentinel->next->prev = new_start;
        deque.sentinel->next = new_start;
    }
    deque.start = prev(deque.start);
    *deque.start.current = val;
}

void pop_back(Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot pop_back: deque is empty" << endl;
        return;
    }
    else if(deque.end.current == deque.end.first) {
        deque.sentinel->prev->prev->next = deque.sentinel;
        deque.sentinel->prev = deque.sentinel->prev->prev;
        delete deque.end.node;
        deque.ll_size--;
        deque.end = prev(deque.end);
        deque.end.current = deque.end.last - 1;
    }
    else{
        deque.end = prev(deque.end);
    }
 }

void pop_front(Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot pop_front: deque is empty" << endl;
        return;
    }
    else if (deque.start.current == prev(deque.start.last)) {
        deque.sentinel->next->next->prev = deque.sentinel;
        deque.sentinel->next = deque.sentinel->next->next;
        delete deque.start.node;
        deque.ll_size--;
        deque.start = next(deque.start);
        deque.start.current = deque.start.first;
    
    }  
    else {
        deque.start = next(deque.start);
    }
}

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
    if (empty(deque)) {
        push_back(deque, val);
    }
    else if (equal(pos, deque.end)) {
        push_back(deque, val);
    }
    else {
        Iterator curr_pos = prev(deque.end);
        push_back(deque, *curr_pos.current);
        for (; !equal(curr_pos, pos); curr_pos = next(curr_pos)) {
            *curr_pos.current = *prev(curr_pos).current;
        }
        *pos.current = val;
    }
}

void erase(Deque& deque, const Iterator& pos) {
    Iterator iter = pos;
    for(; !equal(iter, prev(deque.end)); iter = next(iter)) {
        *iter.current = *(next(iter).current);
    }
    pop_back(deque);
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
}