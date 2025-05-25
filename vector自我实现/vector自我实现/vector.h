#pragma once
namespace bit
{
    template<class T>
    class vector
    {
    public:
        typedef T* iterator；
        typedef const T* const_iterator；
        iterator begin()；
        iterator end()；
        const_iterator cbegin()；
        const_iterator cend() const；
        vector()；
        vector(int n, const T& value = T())；
        template<class InputIterator>
        vector(InputIterator first, InputIterator last)；
        vector(const vector<T>& v)；
        vector<T>& operator= (vector<T> v)；
        ~vector()；
        size_t size() const ；
        size_t capacity() const；
        void reserve(size_t n)；
        void resize(size_t n, const T& value = T())；
        T& operator[](size_t pos)；
        const T& operator[](size_t pos)const；
        void push_back(const T& x)；
        void pop_back()；
        void swap(vector<T>& v)；
        iterator insert(iterator pos, const T& x)；
        iterator erase(Iterator pos)；
    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾
    };
}