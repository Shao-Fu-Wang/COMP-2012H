// #ifndef __OBJECT_TPP_   // required???
// #define __OBJECT_TPP_
//--------------------------------------T pointer----------------------------
template <typename T>
object::T_pointer<T>::T_pointer(T value) {  //Conversion constructor for T_pointer
    this->value = value;
}

template <typename T>
const std::type_info& object::T_pointer<T>::type() const {  //This function returns the type_info of T, using the typeinfo library.
    return typeid(T);
}

template <typename T>
object::object_pointer* object::T_pointer<T>::copy() const {    //This function returns a deep copy of the current T_pointer object.
    T_pointer<T> *tempPtr = new T_pointer<T>(this->value);
    return tempPtr;
}

template <typename T>
object::object_pointer* object::T_pointer<T>::add(const object_pointer& other) const {
    T_pointer<T>* summing_pointer = new T_pointer<T>(this->value + dynamic_cast<const T_pointer<T>*>(&other)->value);
    return summing_pointer;
}

template <typename T>
bool object::T_pointer<T>::equal(const object_pointer& other) const {
    if(this->value == dynamic_cast<const T_pointer<T>*>(&other)->value){
        return 1;
    }
    else{
        return 0;
    }
}
//--------------------------------------object----------------------------
template <typename T> 
object::object(const T& value) {    //Conversion constructor for object.
    obj_ptr = new T_pointer<T>(value);
}

object::~object() { //Destructor for object. 
    delete obj_ptr;
}

object& object::operator=(const object& other) {
    delete obj_ptr; // release

    obj_ptr = (other.obj_ptr->copy());
    return *this;
}

object::object(const object& other) {   //The deep copy constructor of object.
    obj_ptr = (other.obj_ptr->copy());
}

const std::type_info& object::type() const {    //This function gets the type of the current object.
    return obj_ptr->type();
}

template <typename T>
T object::cast_back() const {   //This function casts the value that the current object is storing back to type T.
    if (typeid(T) != obj_ptr->type()) {
        throw std::runtime_error("Object casting failed!");
    }
    else{
        return dynamic_cast<T_pointer<T>*>(obj_ptr)->value;
    }
}

//-------------------------------------------------bonus-----------------------------------------

object object::operator+(const object& other) const {
    if (type() != other.type()){  // throw err
        throw std::runtime_error("Types needed to be the same when performing +");
        // return;
    }
    else{   // correct
        object summing_object = object();
        delete summing_object.obj_ptr;

        object_pointer* summing_pointer = obj_ptr->add(*(other.obj_ptr));
        summing_object.obj_ptr = summing_pointer;
        // assigned
        return summing_object;
    }
}

bool object::operator==(const object& other) const {
    if (obj_ptr->type() != other.obj_ptr->type()){
        return false;
    }
    else{
        if(obj_ptr->equal( *(other.obj_ptr) )){
            return true;
        }
        else{
            return false;
        }
    }
}

std::ostream& operator<<(std::ostream &os, const object& obj) {
    return obj.obj_ptr->print(os);
}


// #endif 