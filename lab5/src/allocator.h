#pragma once

#include <memory>
#include <vector>
#include <stdexcept>

template <class T, size_t BLOCK_SIZE>
class Allocator
{
private:
    std::vector<T> used_blocks;
    std::vector<T*> free_blocks;
    size_t free_count;

public:
    static constexpr size_t max_count = BLOCK_SIZE;
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    Allocator();

    ~Allocator();

    template <class U>
    struct rebind
    {
        using other = Allocator<U, BLOCK_SIZE>;
    };

    T *allocate(size_t n);

    void deallocate(T *pointer, size_t n);

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args);

    void destroy(pointer p);
};


template<class T, size_t BLOCK_SIZE>
Allocator<T, BLOCK_SIZE>::Allocator()
    {
        
        used_blocks.reserve(max_count);
        for (uint64_t i = 0; i < max_count; i++){
            free_blocks.push_back(&used_blocks[i]);
        }
        free_count = max_count;
        //std::cout << "Allocator cnstructed: \n" << free_count << std::endl;
    }

template<class T, size_t BLOCK_SIZE>
Allocator<T, BLOCK_SIZE>::~Allocator()
    {
        //std::cout << "destroyed allocator";
        //used_blocks.clear();
        //used_blocks.shrink_to_fit();
        //free_blocks.clear();
        //used_blocks.shrink_to_fit();
    }


template<class T, size_t BLOCK_SIZE>
T* Allocator<T, BLOCK_SIZE>:: allocate(size_t n)
    {
        if(n != 1){
            throw std::bad_alloc();
        }
        
        T *result = nullptr;
    
        if (free_count > 0)
        {
            result = free_blocks[--free_count];
            //std::cout << "allocated an element\n";
        }
        else
        {
            //std::cout << "bad alloc\n";
            throw std::bad_alloc();
        }
        return result;
    }

template<class T, size_t BLOCK_SIZE>
void Allocator<T, BLOCK_SIZE>::deallocate(T *pointer, size_t)
    {
        //std::cout << "dealocated and element\n";
        free_blocks[free_count++] = pointer;
    }
    
template<class T, size_t BLOCK_SIZE>
template <typename U, typename... Args>
    void Allocator<T, BLOCK_SIZE>::construct(U *p, Args &&...args)
    {
        //std::cout << "constructed an element\n";
        new (p) U(std::forward<Args>(args)...);
    }

template<class T, size_t BLOCK_SIZE>
void Allocator<T, BLOCK_SIZE>::destroy(pointer p)
    {
        //std::cout << "element destroyed\n";
        p->~T();
    }

template <class T, class U, size_t BLOCK_SIZE>
constexpr bool operator==(const Allocator<T, BLOCK_SIZE> &lhs, const Allocator<U, BLOCK_SIZE> &rhs) 
{
    return true;
}

template <typename T, typename U, size_t BLOCK_SIZE>
constexpr bool operator!=(const Allocator<T, BLOCK_SIZE> &lhs, const Allocator<U, BLOCK_SIZE> &rhs)  
{
    return false;
}