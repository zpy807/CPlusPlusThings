#include <iostream>
#include <chrono>

class BigMemoryPool
{
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) { std::cout << "default constructor." << std::endl; }
    ~BigMemoryPool()
    {
        if (pool_ != nullptr)
        {
            delete[] pool_;
        }
    }
    BigMemoryPool(BigMemoryPool &&other)
    {
        std::cout << "move big memory pool." << std::endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }
    BigMemoryPool &operator=(BigMemoryPool &&other)
    {
        std::cout << "move(operator=) big memory pool." << std::endl;
        if (pool_ != nullptr)
        {
            delete[] pool_;
        }
    }
    BigMemoryPool(const BigMemoryPool &other) : pool_(new char[PoolSize])
    {
        std::cout << "copy big memory pool." << std::endl;
        memcpy(pool_, other.pool_, PoolSize);
    }

private:
    char *pool_;
};
void move_pool(BigMemoryPool &&pool)
{
    std::cout << "call move_pool" << std::endl;
    BigMemoryPool my_pool1(pool);
    BigMemoryPool my_pool2(static_cast<BigMemoryPool &&>(pool));
    BigMemoryPool my_pool3(std::move(pool));
}
BigMemoryPool get_pool(const BigMemoryPool &pool)
{
    return pool;
}
BigMemoryPool make_pool()
{
    BigMemoryPool pool;
    return get_pool(pool);
}
int main()
{
    // BigMemoryPool my_pool1;
    // BigMemoryPool my_pool2 = my_pool1;
    // BigMemoryPool my_pool3 = static_cast<BigMemoryPool &&>(my_pool1);
    move_pool(make_pool());
}