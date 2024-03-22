template <typename T, int N> // requires Element<T>()
struct array
{ // not quite the standard array
    using value_type = T;
    using iterator = T *;
    using const_iterator = const T *;
    using size_type = unsigned int; // the type of a subscript

    T elems[N];
    // no explicit construct/copy/destroy needed

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems + N; }
    const_iterator end() const { return elems + N; }
    size_type size() const;

    T &operator[](int n) { return elems[n]; }
    const T &operator[](int n) const { return elems[n]; }

    const T &at(int n) const; // range-checked access
    T &at(int n);             // range-checked access

    T *data() { return elems; }
    const T *data() const { return elems; }
};
