#include <iostream>
#include <sstream>
#include <type_traits>
#include <functional>
using namespace std;

/*
动态装饰器 可以存储修饰对象的引用(甚至存储整个值，如果你想的话!)，并提供动态(运行时)可组合性，但代价是不能访问底层对象自己的成员。
静态装饰器 使用mixin继承(从模板参数继承)在编译时组合装饰器。这失去了任何类型的运行时灵活性(您不能重新组合对象)，但允许你访问底层对象的成员。这些对象也可以通过构造函数转发完全初始化。
函数装饰器 可以包装代码块或特定的函数，以允许 行为的组合
*/

class Shape{
public:
    virtual string str() const = 0;
};

class circleR: public Shape{
    float radius_;
public:
    circleR(float rad) : radius_(rad) {}

    string str() const override {
        ostringstream oss;
        oss << "the circel radius is " << radius_;
        return oss.str();
    }
};

class corlorShape : public Shape {
    Shape& shape_;
    const string& color_;
public:
    corlorShape(Shape& shape, const string& color) : 
        shape_(shape), color_(color) {}
    string str() const override {
        ostringstream oss;
        oss << shape_.str() << " color is " << color_;
        return oss.str();
    }
};

// std::is_base_of<Base, Derived>::value用于检查Base类是否是Derived类的基类，实则返回true.
// 静态装饰器，好处就是漂亮！层层继承，可以在子类中调用所有父类的方法
template <typename T>
class ColorShapeTemp : public T {
    static_assert(is_base_of<Shape, T>::value, "template argument must be a shape");

    string color_;

    ColorShapeTemp(){}

public:
    template <typename ...Args>
    ColorShapeTemp(const string& color, Args ...args)
        : T(std::forward<Args>(args)...), color_(color){}
    string str() const override {
        ostringstream oss;
        oss << T::str() << " has color" << color_;
        return oss.str();
    }
};

// need partial specialization for this to work
template <typename> struct Logger3;

// return type and argument list
template <typename R, typename... Args> 
struct Logger3<R(Args...)>
{
  Logger3(function<R(Args...)> func, const string& name)
    : func{func},
      name{name}
  {
  }

  R operator() (Args ...args)
  {
    cout << "Entering " << name << endl;
    R result = func(args...);
    cout << "Exiting " << name << endl;
    return result;
  }

  function<R(Args ...)> func;
  string name;
};

template <typename R, typename... Args>
auto make_logger3(R (*func)(Args...), const string& name)
{
  return Logger3<R(Args...)>(
    std::function<R(Args...)>(func), 
    name);
}

double add(double a, double b)
{
  cout << a << "+" << b << "=" << (a + b) << endl;
  return a + b;
}

void function_decorator()
{
  //Logger([]() {cout << "Hello" << endl; }, "HelloFunction")();
  

  auto logged_add = make_logger3(add, "Add");
  auto result = logged_add(2, 3);
}


int main() {
    circleR circle(5.0);
    corlorShape color_circle(circle, "blue");
    cout << color_circle.str() << endl;

    ColorShapeTemp<circleR> color_circle_temp {"bule", 5.0};
    cout << color_circle_temp.str() << endl;
    function_decorator();
}