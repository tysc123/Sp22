//Tyler Schmalenbach
//1482664

#ifndef StaticArray_h
#define StaticArray_h

template <typename T, int CAP>
class StaticArray {
    T values[CAP]; //T datatypr CAP compasity
    T dummy; 
    
public:
    StaticArray();
    int capacity() const {return CAP;}
    T operator[](int) const; //getter
    T& operator[](int); //setter
};

template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray() {
    for (int index = 0; index < CAP; index++)
        values[index] = T();
}

template <typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const {
    if (index < 0 || index >= CAP)
        return T(); 
    return values[index]; 
}

template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index) {
    if (index < 0 || index >= CAP)
       return dummy; 
    return values[index]; 
}

#endif
