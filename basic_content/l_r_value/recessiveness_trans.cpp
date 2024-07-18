#include <iostream>
#include <string>
using namespace std;
struct X
{
    X() = default;
    X(const X &) = default;
    X(X &&)
    {
        std::cout << "move ctor";
    }
};

X f(X x)
{
    return x;
}

X f1()
{
    X x;
    return x;
}

int main()
{
    X r = f(X{});
    X r1 = f1();
    std::string path{"saldkfja;sdfa"};
    const int &value = std::max(30, 100);
    cout << value << endl;
    // const char *str = path.trimmed().toStdString().c_str();
}
