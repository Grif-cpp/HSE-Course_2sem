//
// Created by Denis on 12.03.2021.
//

#ifndef HOMEWORK_2_STATIC_ARRAY_H
#define HOMEWORK_2_STATIC_ARRAY_H

template<typename T, size_t sz = 0>
class static_array {
public:
    class iterator {
      public:
        iterator(const iterator &);

        ~iterator();

        iterator &operator=(const iterator &);

        iterator &operator++();

        iterator &operator--();

        T *operator->() const;

        T &operator*() const;

         bool operator==(iterator const &other) const; 

         bool operator!=(iterator const &other) const;

         friend class static_array;
    private:
    iterator(static_array<T, sz> *array_);
    iterator(static_array<T, sz> *array_, size_t pos_);
    std::size_t pos;
    static_array<T, sz> *array;
    };

    static_array();

    static_array(size_t sz);

    size_t current_size();

    size_t size();

    void clear();

    static_array::iterator emplace(size_t ind, T &&obj);

    template<class... Args>
    static_array::iterator emplace(size_t ind, Args &&... args);

    void erase(static_array::iterator it);

    T &at(size_t ind);

    static_array::iterator begin();

    static_array::iterator end();
    private:
    std::vector<T *>data;
    std::vector<bool>used;
    size_t cur_size_;
    size_t size_;
    static_array::iterator begin_;
    static_array::iterator end_;
};

#endif //HOMEWORK_2_STATIC_ARRAY_H
