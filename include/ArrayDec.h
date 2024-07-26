#ifndef ARRAYDEC_H
#define ARRAYDEC_H

#ifndef INCLUDES
#define INCLUDES
#include <iostream>
#include <stdexcept> 
#include <functional>
#endif // !INCLUDES

template<class T, int N>
class Array {
  private:
    T m_buffer[N];
    int size;

  public:
    Array() : size(0) {}

    int getSize() const { return size; }
    int getCap() const { return N; }

    void printArray(std::function<void(T)>debug = [](T val) { std::cout << val; }) const {
      std::cout << "[";
      for (int i = 0; i < size - 1; ++i) {
        debug(m_buffer[i]); 
        std::cout << ", ";
      }
      if (size > 0) {
        debug(m_buffer[size-1]);
      }
      std::cout << "]" << std::endl;
    }

    Array(int val) : size(N) {
      for (int i = 0; i < N; ++i) m_buffer[i] = val;
    }

    template<class... Args>
      Array(Args... args) {
        if (sizeof...(args) > N) {
          throw std::out_of_range("Invalid size allocation!");
        }

        T temp[] = { args... };
        for (int i = 0; i < sizeof...(args); ++i) {
          m_buffer[i] = temp[i];
        }
        size = sizeof...(args);
      }

    T& operator[](int index) {
      if (index >= size || index < -size) {
        throw std::out_of_range("Index out of range error!");
      }

      if (index < 0) {
        return m_buffer[size + index];
      }

      return m_buffer[index];
    }

    const T& operator[](int index) const {
      if (index >= size || index < -size) {
        throw std::out_of_range("Index out of range error!");
      }

      if (index < 0) {
        return m_buffer[size + index];
      }

      return m_buffer[index];
    }

    void push_back(T val) {
      if (size >= N) {
        throw std::out_of_range("Array is full!");
      }

      m_buffer[size] = val;
      size++;
    }

    bool empty() {
      return size == 0;
    }

    void pop_back() {
      if(empty()) {
        throw std::out_of_range("The Array is empty!");
      }

      size--;
    }
};

#endif // ARRAYDEC_H
