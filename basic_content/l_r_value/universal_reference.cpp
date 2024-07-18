#include <vector>
void foo(int &&i) {} // i为右值引用

template <class T>
void bar(T &&t) {} // t为万能引用

int get_val() { return 5; }
int &&x = get_val(); // x为右值引用

auto &&y = get_val(); // y为万能引用

template <class T>
void foo(std::vector<T> &&t) {}

int main()
{
    int i = 42;
    const int j = 11;
    bar(i);
    bar(j);
    bar(get_val());
    auto &&x = i;
    auto &&y = j;
    auto &&z = get_val();
    std::vector<int> v{1, 2, 3};
    foo(v); // 编译错误
}