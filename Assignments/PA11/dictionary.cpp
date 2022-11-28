#include <vector>
#include <iostream>

#include "dictionary.h"

using namespace std;

// this function will not be used in any way. For C++, templates are usually defined in header files. 
// However, for ZINC grading, we separate it into different files. So we need to use this 'trick' to
// instantiate the temnplate.
void compiler_trick_useless_function(){
    Dictionary d{""};
    lambda_for_main_cpp ct;
    d.foreach(ct);
}

int Dictionary::character_to_index(const char& ch){
    return ch - 97;
}

char Dictionary::index_to_character(const int& idx){
    return (char) (idx + 97);
}

const string& Dictionary::get_name() const{
    return name;
}

void Dictionary::set_name(const string& name){
    this->name = name;
}

Dictionary::Dictionary(const string& name)
    : name(name) 
{
    root = new Node;
}

Dictionary::~Dictionary(){
    delete root;
}

Dictionary::Dictionary(Dictionary&& d){
    root = d.root;
    d.root = nullptr;
}

Dictionary& Dictionary::operator=(Dictionary&& d){
    delete root;
    root = d.root;
    d.root = nullptr;

    return *this;
}

ostream& operator<<(ostream& o, Node* n){
    o << (*n);
    return o;
}

ostream& operator<<(ostream& o, const Node& n){
    o << " (" << n.meaning.type << ") " << n.meaning.meaning << " ";
    return o;
}


bool rec_copy_node(Node* self, Node* target) {
    bool conti = false;
    for (int i = 0; i < 26; i++) {
        Node* copyNode = (*target)[i]; 
        if (copyNode != nullptr) {

            Node* child = new Node;
            // decide child node
            self->set_child(i, child);
            child->get_parent() = self;
            bool result = rec_copy_node(child, copyNode);
            if(conti == true or result == true){
                conti = true;
            }
            else{
                conti = false;
            }
        }
    }    
    self->meaning = target->meaning;
    if (self->meaning.meaning[0] != '\0'){
        conti = true;
    } 
    return conti;
}

/**
 * TODO - Constructor for deep copy of dictionary.
*/
Dictionary::Dictionary(const Dictionary& d){
    root = new Node;
    // recursion
    rec_copy_node(root, d.root);
}

void delete_Node(Node* target) {
    delete target;
}

/**
 * TODO - Assignment operator for deep copy of dictionary.
*/
Dictionary& Dictionary::operator=(const Dictionary& d){
    delete_Node(root);
    root = new Node;
    rec_copy_node(root, d.root);
    return *this;
}

/**
 * TODO - Adds a node with the given key string, which is terminated with '\0'.
 * You should assume the key consists of lowercase letters only.
 * Do not delete the pointer.
*/
Node* Dictionary::add_node(const char* key){
    if (key[0] == '\0') {
        return root;
    }

    const char* charptr = key;
    Node* curNode = root;
    Node* nextNode = nullptr;
    bool node_exist = true;
    int charIndex = 0;
    while (*charptr != '\0') {
        charIndex = character_to_index(*charptr);
        nextNode = (*curNode)[charIndex];
        
        if (node_exist == true) {
            if (nextNode != nullptr) {  // next node exists
                curNode = nextNode;     // iter
            }
            else {
                node_exist = false;
            }
        }
        if (node_exist == false) {
            nextNode = new Node;
            curNode->set_child(charIndex, nextNode);
            nextNode->get_parent() = curNode;
            curNode = nextNode;
        }
        ++charptr;
    }

    return curNode;
}

/**
 * TODO - Shorthand for add_node.
*/
Node* Dictionary::operator+=(const char* key){
    return add_node(key);
}

/**
 * TODO - Removes all nodes starting with the given key string, which is terminated with '\0'.
 * You should assume the key consists of lowercase letters only.
 * Do not delete the pointer const char* key (of course you should clean up the nodes that are removed).
*/
void Dictionary::remove_node(const char* key){
    if (key[0] == '\0'){
        return;
    }
    else{
        const char* charptr = key;
        Node* curNode = root;
        Node* nextNode = nullptr;
        int charIndex = 0;
        while (*charptr != '\0') {
            charIndex = character_to_index(*charptr);  
            nextNode = (*curNode)[charIndex];
            if (nextNode != nullptr) {
                curNode = nextNode;
            } 
            else if(nextNode == nullptr) {
                return;
            }
            ++charptr;
        }
        if (curNode != nullptr) {
            (curNode->get_parent())->set_child(charIndex, nullptr);

            delete_Node(curNode);
        }
    }
}

/**
 * TODO - Shorthand for remove_node.
*/
void Dictionary::operator-=(const char* key){
    remove_node(key);
}

/**
 * TODO - Finds a node with the given key string, which is terminated with '\0'.
 * Returns nullptr if no such node is found.
 * You should assume the key consists of lowercase letters only.
 * Do not delete the pointer.
*/
Node* Dictionary::find_node(const char* key) const{
    if (key[0] == '\0') {
        return root;
    }
    else{
        const char* charptr = key;
        Node* curNode = root;
        Node* nextNode = nullptr;
        while (*charptr != '\0') {
            int index = character_to_index(*charptr);
            nextNode = (*curNode)[index];
            if (nextNode != nullptr) {
                curNode = nextNode;
            } 
            else {
                return nullptr;
            }
            ++charptr;
        }
        //delete
        return curNode;
    }
}

/**
 * TODO - A function to do pre-order traversal on the tree. The function accepts a lambda function as argument,
 * and then the lambda function would be called for every node in the tree (except the root node). 
 * The lambda function accepts two arguments, (Node* current_node, vector<int>& current_key).
 * For each node accessed via pre-order traversal (except root node), call the lambda function.
 * 
 * Of course current_node should be the pointer to the node accessed. current_key should contain
 * a list of integers which corresponds to the indices required to travel to current_node from
 * the root node. For more explanation see the webpage.
 * 
 * The lambda is not supposed to change the dictionary.
*/

template<typename T> void Traversal(vector<int> key, Node* node, T&& lambda) {  // not sure 
    if (key.size() >= 1) {
        lambda(node, key);
    }

    for (int i = 0; i < 26; ++i) {
        Node* childNode = (*node)[i];
        if (childNode != nullptr) {
            vector<int> keyVec = key;
            keyVec.push_back(i);

            Traversal(keyVec, childNode, lambda); // recusion
        }
        else if(childNode == nullptr){
        //     return;
        }
    }
 
}

template<typename T> void Dictionary::foreach(T&& lambda) const{
    vector<int> vec;
    Traversal(vec, root, lambda);
}

/**
 * TODO - Prints all the nodes in the dictionary, in depth first alphabetical order.
 * See the webpage description for more details.
*/
void Dictionary::print_all_elements(ostream& o) const{
    int cnt = 0;
    foreach([&cnt, &o](Node* curNode, vector<int> curKey){
        string str;

        for (vector<int>::const_iterator iter = curKey.cbegin()/*+1*/ ; iter != curKey.cend(); ++iter) {
            str = str + Dictionary::index_to_character(*iter);  //concatenation
        }
        o << str << curNode << "[" << ++cnt << "]\n";
        
    });

}

/**
 * TODO - Calls print_all_elements
*/
std::ostream& operator<<(std::ostream& o, const Dictionary& dict){
    dict.print_all_elements(o);
    return o;
}

/**
 * TODO - Prints all the words in the dictionary, such that the word type is equal to the given type,
 * in depth first alphabetical order. See the webpage description for more details.
*/
void Dictionary::print_elements_given_type(const char* type) const{
    int cnt = 0;
    foreach([&cnt, type](Node* curNode, vector<int> curKey){
        if (type != nullptr && curNode->meaning.type != type) {
                return;
        }
        if (curNode->meaning.meaning[0] == '\0') {
            return;
        }

        string str;
        for (vector<int>::const_iterator iter = curKey.cbegin()/*+1*/; iter != curKey.cend(); ++iter) {
            str += Dictionary::index_to_character(*iter);
        }
        cout << str << curNode << "[" << ++cnt << "]\n";
    });
}

/**
 * TODO - Merges with another dictionary. Creates a new dictionary,
 * and does not modify the contents of the original dictionaries.
 * For words that exists in both dictionary,
 * use the word definition in the dictionary this.
*/
Dictionary Dictionary::merge(const Dictionary& d2) const{
    Dictionary mergeDict = *this;
    d2.foreach([&](Node* curNode, vector<int> keyVec) {
        string str;

        for (vector<int>::const_iterator iter = keyVec.cbegin()/*+1*/; iter != keyVec.cend(); ++iter) {
            str += Dictionary::index_to_character(*iter);
        }
        Node* mergeNode = mergeDict.add_node(str.c_str());

        if (mergeNode == d2.root){
            return 0;
        } 
        else if(mergeNode->meaning.meaning[0] != '\0') {
            return 0;
        }
        
        mergeNode->meaning = curNode->meaning;
    });
    mergeDict.set_name(""); // set name blank

    return mergeDict;
}

void compTraversal(Node* self, Node* target) {
    
    if (target->meaning.meaning[0] != '\0') {
        self->meaning = target->meaning;
    }

    for (int i = 0; i < 26; ++i) {
        Node* targetChild = (*target)[i];
        if (targetChild != nullptr) {
            Node* selfChild = (*self)[i];

            if (selfChild == nullptr) { // make a new one
                selfChild = new Node;
                selfChild->get_parent() = self;
                self->set_child(i, selfChild);
            }
            
            compTraversal(selfChild, targetChild);  // recurrsion
        }
    }
}
/**
 * TODO - Merges with another dictionary. Moves the contents of d2
 * into a new dictionary. For words that exists in both dictionary,
 * use the word definition in the dictionary this.
*/

Dictionary Dictionary::merge(Dictionary&& d2) const{
    Dictionary&& newDict = move(d2);
    compTraversal(newDict.root, this->root);
    newDict.set_name("");   // set as black
    return move(newDict); 
}

/**
 * TODO - Creates a new dictionary, consisting only of the words
 * starting with the given key.
*/
Dictionary Dictionary::filter_starting_word(const char* key) const{
    Dictionary targetDict("");
    if (key == nullptr || key[0] == '\0') {
        targetDict = *this;
        return targetDict;
    }
    else{
        Node* node = find_node(key);
        if (node != nullptr) {
            Node* roots = targetDict.add_node(key);
            if (rec_copy_node(roots, node) == true) {
                return targetDict;
            }
        }

        return Dictionary("");
    }
}

Dictionary Dictionary::operator+(const Dictionary& d2) const{
    return merge(d2);
}

Dictionary Dictionary::operator+(Dictionary&& d2) const{
    return merge(move(d2));
}