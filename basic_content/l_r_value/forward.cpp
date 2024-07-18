// 原文链接：https : // blog.csdn.net/weixin_62892290/article/details/131185891
#include <iostream>
#include <string>
template <class T>
void show_type(T t)
{
    std::cout << typeid(t).name() << std::endl;
}
template <class T>
void normal_forwarding(T t)
{
    show_type(t);
}
template <class T>
void normal_forwardingV1(T &t)
{
    show_type(t);
}

template <class T>
void normal_forwardingV1_1(const T &t)
{
    show_type(t);
}

/*
如果已经理解了引用折叠规则，那么上面的代码就很容易理解了。
唯一可能需要注意的是show_type(static_cast<T&&>(t));中的类型
转换，之所以这里需要用到类型转换，是因为作为形参的t是左值。为
了让转发将左右值的属性也带到目标函数中，这里需要进行类型转换。
当实参是一个左值时，T被推导为std::string&，于
是static_cast<T&&>被推导为static_cast<std:: string&>，传递
到show_type函数时继续保持着左值引用的属性；当实参是一个右值
时，T被推导为std::string，于是static_cast <T&&>被推导
为static_caststd::string&&，所以传递到show_type函数时保
持了右值引用的属性。

*/
template <class T>
void perfect_forwarding(T &&t)
{
    show_type(static_cast<T &&>(t));
}

template <class T>
void perfect_forwardingV1(T &&t)
{
    show_type(std::forward<T>(t));
}

std::string get_string()
{
    return "hi world";
}
int main()
{
    std::string s = "hello world";
    normal_forwarding(s);
    normal_forwardingV1("hello world");
    // normal_forwardingV1(get_string()); // cannot bind non-const lvalue reference to an rvalue of type
    normal_forwardingV1_1(get_string());

    // perfect forward
    perfect_forwarding(s);
    perfect_forwarding(get_string());
}
