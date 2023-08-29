#include <iostream>

template <typename T>

class Vector
{
public:
    Vector();
    Vector(int, int, T*);
    Vector(Vector<T>&);
    Vector(Vector<T>&&);
    Vector<T>& operator =(Vector<T>&&);
    void PushBack(const T&);
    T PopBack();
    int Size() const;
    int Capacity() const;
    T& operator[](int);
    T& At(int);
    bool Empty();
    void PrintVector();
    ~Vector();

private:
    int m_size;
    int m_capacity;
    T* m_arr;
};

template<typename T>
Vector<T>::Vector() {
    m_size = 0;
    m_capacity = 1;
    m_arr = new T[m_capacity];
} 

template<typename T>
Vector <T>::Vector(int s, int c, T* arr)
    : m_size(s), m_capacity(c), m_arr(new T[m_capacity])
{
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = arr[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector<T>& other)

    : m_arr(new T[m_capacity]),
      m_size(other.m_size),
      m_capacity(other.m_capacity)
{
    for (size_t i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];  
    }
    std::cout << "copy ctor" << std::endl;
}


template<typename T>
Vector <T>::Vector(Vector<T>&& other)
    : m_arr(new T[m_capacity]),
      m_size(other.m_size),
      m_capacity(other.m_capacity)
{
    for (size_t i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }

    std::cout << "move ctor" << std::endl;
    other.m_arr = nullptr;
    other.m_size = other.m_capacity = 0;
}   

template<typename T>
Vector<T>& Vector <T>::operator =(Vector<T>&& other) {
    
        delete[] m_arr;
        m_size = other.m_size;
        m_arr = new T[m_capacity];
        
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
      
        m_capacity = other.m_capacity;
        other.m_arr = nullptr;
    
    return *this;
}


template<typename T>
void Vector <T>::PushBack(const T& element) {
    ++m_size;
    if (m_size > m_capacity) {
        m_capacity *= 2;
        T* newArr = new T[m_capacity];

        for (int i = 0; i < m_size - 1; ++i) {
            newArr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = newArr;
        newArr = nullptr;  
    }
    m_arr[m_size - 1] = element;
}

template <typename T>
T Vector <T>::PopBack() {
    return m_arr[--m_size];  
}

template <typename T>
int Vector <T>::Size() const {
    return m_size;
}

template <typename T>
int Vector <T>::Capacity() const {
    return m_capacity;
}

template <typename T>
T& Vector <T>::operator[](int index) {
    if (index < 0) throw std::out_of_range("error: out of range!");
    return m_arr[index];
}

template <typename T>
T& Vector <T>::At(int index) {
    if (index >= m_size || index < 0) {
        throw std::out_of_range("error: out of range!");
    }
    return m_arr[index];
}

template <typename T>
bool Vector <T>::Empty() {
    if (m_size == 0) {
        return true;
    }
    return false;
}

template <typename T>
void Vector <T>::PrintVector() {
    std::cout << "size: "  << Size() << std::endl;
    std::cout << "capacity: " << Capacity() << std::endl;
    std::cout << "m_arr: ";

    for (int i = 0; i < m_size; ++i) {
        if (i != m_size - 1) std::cout << m_arr[i] << ", ";
        else std::cout << m_arr[i] << std::endl;
    }

    if (Empty()) {
        std::cout << "Your vector is empty" << std::endl;
    }
}

template<typename T>
Vector <T>::~Vector() {
    delete[] m_arr;
}





