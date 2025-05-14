#include <iostream>
#include <vector>

template<class T>
class allocator
{
public:
    using value_type = T;

    allocator(allocator<int> allocator1) {}

    T* allocate(size_t n)
    {
        std::cout << "Items: " << n << " allocate: " << n * sizeof(T) << " bytes\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* ptr, size_t n)
    {
        std::cout << "Deallocate: " << n * sizeof(T) << " bytes\n";
        ::operator delete(ptr);
    }
};

int main() {
    std::vector<int, allocator<int>> vec;
    vec.reserve(100);
    return 0;
}