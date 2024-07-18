#include <iostream>

using namespace std;
int &&f()
{
    return 3;
}
class Object
{
    // some members...
};

Object createObject()
{
    return Object();
}

int main()
{
    int x = 0;
    cout << "(x).addr = " << &x << endl;
    cout << "(x = 1).addr = " << &(x = 1) << endl;
    cout << "(++x).addr = " << &++x << endl;
    // cout << "(x++).addr = " << &(x++) << endl; // error
    cout << "(cout << ' ').addr=" << &(cout << ' ') << endl;
    cout << "(\"hello\").addr=" << &("hello") << endl;
    // cout << "(int && f()).addr=" << &(f()) << endl;
    // cout << "static_cast<int&&>(7).addr=" << &(static_cast<int &&>(7)) << endl;
    // cout << "std::move(7).addr=" << &(std::move(7)) << endl;

    Object obj;                              // 'obj' 是一个左值
    Object &&tempObj = createObject();       // 'createObject()' 返回一个右值
    const Object &ctempObj = createObject(); // 'createObject()' 返回一个右值

    int a = 42;              // 'a' 是一个左值
    int &&rvalueRef = a + 5; // 'a + 5' 是一个右值

    // 取地址示例
    Object *pObj = &obj; // 可以，因为 'obj' 是左值
    // Object* pTempObj = &createObject();  // 错误，因为 'createObject()' 是一个右值
}