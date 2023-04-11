# C++11主要新特性

以下是C++11的新特性列表：

1. 初始化列表(initializer_list)
2. 统一初始化语法(uniform initialization syntax)
3. auto关键字
4. decltype关键字
5. 基于范围的for循环(range-based for loop)
6. lambda表达式(lambda expressions)
7. 右值引用(rvalue references)和移动语义(move semantics)
8. 类型推断(type inference)和auto返回类型
9. 空指针常量(nullptr)
10. constexpr函数(constant expressions)
11. 静态断言(static_assert)
12. 模板别名(template aliases)
13. 默认和删除函数(defaulted and deleted functions)
14. 变长参数模板(variadic templates)
15. 委托构造函数(delegating constructors)
16. override和final关键字
17. 非静态成员初始化(non-static data member initialization)
18. 显式虚函数重载(explicit virtual function overrides)
19. 易于使用的多线程编程支持，包括原子类型(atomic types)和线程本地存储(thread-local storage)

以上是C++11的主要新特性，其中很多都是为了提高代码的简洁性、可读性和性能。C++11的引入使得C++编程变得更加现代化和强大。

## 1.初始化列表(initializer_list)

初始化列表(initializer_list)是C++11引入的一个新特性，它可以方便地初始化一个对象，可以在构造函数中使用。

初始化列表使用花括号{}来创建一个列表，并用逗号分隔每个值。例如：

```
c++Copy code#include <iostream>
#include <initializer_list>

using namespace std;

class Vector {
public:
    Vector(initializer_list<int> list) {
        for (auto item : list) {
            m_data.push_back(item);
        }
    }

    void print() {
        for (auto item : m_data) {
            cout << item << " ";
        }
        cout << endl;
    }

private:
    vector<int> m_data;
};

int main() {
    Vector v = { 1, 2, 3, 4, 5 };
    v.print();

    return 0;
}
```

在上面的例子中，Vector类的构造函数接受一个initializer_list<int>类型的参数，该参数使用花括号{}来传递一个整数列表，然后将它们添加到m_data中。在main函数中，我们创建了一个Vector对象，并使用初始化列表传递了5个整数。

使用初始化列表可以方便地初始化对象，并且可以提高代码的可读性和简洁性。可以用于任何需要一系列值的地方，如构造函数、函数参数等。

## 2.统一初始化语法(uniform initialization syntax)

统一初始化语法（uniform initialization syntax）是C++11中的一个新特性，它提供了一种新的语法，使得不同类型的变量可以使用相同的初始化方式。以前，C++中的初始化方式因类型而异，例如：

```c++
int a = 1;
std::vector<int> vec {1, 2, 3};
std::map<std::string, int> map { {"foo", 1}, {"bar", 2} };
```

可以看到，int类型使用了传统的赋值语句，vector类型使用了花括号{}，而map类型使用了一对大括号和一对小括号{}。这种不一致的初始化方式可能会使代码难以阅读和理解。

使用统一初始化语法，我们可以使用花括号{}来初始化任何类型的变量，例如：

```c++
int a{1};
std::vector<int> vec{1, 2, 3};
std::map<std::string, int> map{ {"foo", 1}, {"bar", 2} };
```

在这个例子中，我们可以看到，无论是基本类型还是复杂类型，我们都可以使用花括号{}来初始化变量。

统一初始化语法还可以用于创建数组和结构体等复杂类型的初始化，例如：

```c++
int arr[] {1, 2, 3};
struct Point {
    int x;
    int y;
};
Point p {1, 2};
```

使用统一初始化语法可以使代码更加清晰和简洁，提高代码的可读性和可维护性。

## 10.constexpr函数(constant expressions)

在C++11中，引入了一个新的函数修饰符 `constexpr`，用于声明可以在编译期计算出结果的函数，称为常量表达式函数（`constant expressions`）。这种函数的参数和返回值都必须是字面值类型（`literal types`），而且函数体必须是一个可以在编译时确定的表达式，不能包含任何形式的运行时行为，例如动态内存分配和输入输出操作等。constexpr函数的返回值可以用于编译期常量的初始化、数组大小、模板参数等需要在编译期计算的地方。

使用`constexpr`修饰函数后，可以在编译期间对其进行求值，从而避免了运行时的函数调用开销。在编译期求值的函数，由于其参数和返回值都必须是字面值类型，所以其实现代码通常非常简单。

下面是一个使用`constexpr`的示例代码，计算阶乘：

```c++
constexpr int factorial(int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main()
{
    constexpr int x = factorial(5); // 编译期求值
    static_assert(factorial(5) == 120, "Wrong result"); // 编译期断言
    return 0;
}
```

在上面的代码中，`factorial`是一个`constexpr`函数，可以在编译期间求值。在`main`函数中，我们可以使用`constexpr`的特性，将`factorial(5)`的结果在编译期间求值，并将结果赋值给变量`x`。我们还可以使用`static_assert`在编译期间对`factorial(5)`的结果进行断言。

需要注意的是，`constexpr`函数并不是只能在编译期间使用，它也可以在运行时被调用，只不过此时它的行为和普通函数没有区别。同时，C++11还引入了`constexpr`变量的概念，可以将某些变量声明为编译期常量。

## 1.静态断言(static_assert)

静态断言是 C++11 引入的一种编译期检查机制，其主要目的是在编译时检查程序是否符合特定的要求。在编译时，如果静态断言失败，编译器会抛出一个编译错误，从而防止程序在运行时出现问题。

静态断言的语法形式如下：

```c++
static_assert(条件表达式, "错误提示信息");
```

其中，条件表达式必须是一个**编译时常量表达式**，如果条件表达式的值为 false，编译器将会在编译时输出指定的错误提示信息。

静态断言通常用于以下几种场景：

- **检查类型大小或成员变量偏移量是否符合预期**
- **检查模板参数是否符合要求**
- **检查编译时常量表达式是否符合要求**

例如，以下代码展示了如何使用静态断言检查结构体的大小：

```c++
#include <iostream>
#include <type_traits>

struct MyStruct {
    int a;
    char b;
};

int main() {
    static_assert(sizeof(MyStruct) == sizeof(int) + sizeof(char), "MyStruct size error");
    std::cout << "MyStruct size is OK" << std::endl;
    return 0;
}
```

如果 MyStruct 的大小不等于 int 和 char 大小之和，编译器将会输出 MyStruct size error，并停止编译。否则，程序将会输出 MyStruct size is OK。

静态断言可以帮助程序员在编译时发现潜在的问题，提高程序的可靠性和稳定性。

## 13.默认和删除函数(defaulted and deleted functions)

C++11引入了两种新的函数声明方式：默认函数和删除函数。

默认函数声明使用关键字"default"，它可以在函数声明或定义中使用。如果一个函数被声明为"default"，则编译器将生成函数的默认实现。例如，以下代码声明了一个默认的构造函数：

```c++
class MyClass {
public:
    MyClass() = default;
};
```

删除函数声明使用关键字"delete"，它可以在函数声明或定义中使用。如果一个函数被声明为"delete"，则编译器将禁止调用该函数。例如，以下代码禁止了一个默认构造函数：

```c++
class MyClass {
public:
    MyClass() = delete;
};
```

使用默认函数和删除函数可以使代码更加清晰，并且可以防止一些编译时和运行时的错误。

## 14.变长参数模板(variadic templates)

使用变长参数模板时，我们需要使用三个点(...)表示参数包。我们可以在函数定义中使用参数包，并使用展开运算符（即另一个三个点(...)）来展开参数包。

例如，以下是一个简单的变长参数模板函数，用于计算一组整数的总和：

```c++
template<typename... Args>
int sum(Args... args)
{
    return (args + ...);
}
```

在此示例中，我们使用模板参数包`Args`来表示参数列表中的类型，使用函数参数包`args`来表示参数列表中的值。我们使用`(args + ...)`来展开函数参数包并计算总和。展开运算符是将函数参数包中的所有值添加在一起。

要使用此函数，我们可以传递任意数量的整数作为参数：

```c++
int s1 = sum(1, 2, 3, 4, 5);  // s1的值为15
int s2 = sum(2, 4, 6, 8);     // s2的值为20
int s3 = sum(3, 5);           // s3的值为8
```

有几个使用技巧：

1. 当我们使用变长参数模板时，必须考虑到参数包中的参数数量可能为零。我们可以使用递归函数和基本情况来解决这个问题。
2. 我们可以使用参数包展开运算符和std::initializer_list来创建通用的函数。例如，我们可以编写一个可变参数模板函数来查找一组值的最小值：

```c++
template<typename T>
T find_min(const T& t)
{
    return t;
}

template<typename T, typename... Args>
T find_min(const T& t, const Args&... args)
{
    return std::min(t, find_min(args...));
}
```

在此示例中，我们定义了两个函数，第一个函数用于一个参数包中的基本情况，第二个函数用于递归调用。我们在递归调用中使用std::min来查找每个参数的最小值。

1. 我们可以使用变长参数模板来实现通用的函数，例如，可以将一组参数转换为字符串，并使用逗号分隔符连接它们。例如：

```c++
template<typename... Args>
std::string join(const std::string& separator, const Args&... args)
{
    std::stringstream ss;
    int n = sizeof...(Args);
    int i = 0;
    ((ss << args << (++i == n ? "" : separator)), ...);
    return ss.str();
}
```

在此示例中，我们使用stringstream将参数转换为字符串，并使用逗号分隔符连接它们。我们使用参数包展开运算符和逗号表达式将参数包中的所有参数连接在一起。我们还使用sizeof...(Args)来计算参数包中的参数数量，并使用(++i == n ? "" : separator)来确定是否添加分隔符。

## 15.委托构造函数(delegating constructors)

在C++11之前，如果我们想让一个类的多个构造函数有一些共同的初始化代码，那么我们需要在这些构造函数中都重复这些代码，这样既浪费时间，也容易出错。C++11引入了委托构造函数(delegating constructors)的概念，使得我们可以通过调用同一个类的另一个构造函数来避免重复代码。

委托构造函数的语法非常简单，就是在构造函数的初始化列表中使用this指针调用同一个类的另一个构造函数。例如：

```c++
class MyClass {
public:
    MyClass() : MyClass(0, 0) {}
    MyClass(int x) : MyClass(x, 0) {}
    MyClass(int x, int y) : x_(x), y_(y) {}
private:
    int x_;
    int y_;
};
```

这里我们定义了三个构造函数，其中前两个都调用了第三个构造函数，并传递了不同的参数。这样，我们就避免了在每个构造函数中都重复初始化x_和y_的代码。

需要注意的是，**委托构造函数必须在构造函数的初始化列表中出现**，而且只能调用同一个类的其他构造函数。此外，**一个类只能有一个默认构造函数**，因此如果我们使用了委托构造函数，则需要保证至少有一个构造函数不是委托构造函数。

## 17.非静态成员初始化(non-static data member initialization)

在C++11之前，非静态成员变量的初始化只能在构造函数的初始化列表中进行。这种方式不仅繁琐，而且容易出错，因为如果忘记初始化一个成员变量，它的值将是未定义的，可能导致程序出现意想不到的结果。

为了解决这个问题，C++11引入了非静态成员初始化，使得我们可以在声明成员变量时直接为其指定初始值。例如：

```
cppCopy codeclass MyClass {
public:
  int x = 0; // 初始化为0
  std::string s = "hello"; // 初始化为"hello"
};
```

这样，当创建类的对象时，其成员变量将自动初始化为指定的值。如果构造函数初始化列表中没有对成员变量进行初始化，它们将使用在声明时指定的默认值进行初始化。

非静态成员初始化还**支持使用constexpr、默认参数和函数**等作为初始值。注意，如果一个成员变量同时在声明时指定了初始值和在构造函数初始化列表中进行了初始化，后者将覆盖前者。

## 18.显式虚函数重载(explicit virtual function overrides)

在C++11之前，如果子类需要重载父类的虚函数，必须要在子类中声明一个与父类虚函数完全一致的函数，包括函数名、参数类型、返回类型和const属性等。如果子类不小心修改了函数签名，就会导致虚函数的重载失败，而不是重载覆盖。这可能会导致程序出现严重的问题，而这种问题很难被发现和排除。

C++11引入了一种新的方式，即显式虚函数重载（explicit virtual function overrides），它可以帮助程序员更加清晰地指定虚函数的重载。在显式虚函数重载中，可以在子类中使用`override`关键字来指示该函数是父类虚函数的重载，从而在编译期间检查函数签名是否与父类虚函数相同。

例如，假设有以下的基类和子类：

```c++
class Base {
public:
    virtual void foo() const;
};

class Derived : public Base {
public:
    virtual void foo() const override; // 显式指示重载父类虚函数
};
```

在上述代码中，`Derived`类中的`foo()`函数通过使用`override`关键字来显式指示它是对`Base`类中的`foo()`函数的重载。如果在`Derived`类中的`foo()`函数的声明中没有使用`override`关键字，而且`Derived`类中的函数签名与`Base`类中的函数签名不完全一致，则编译器将产生一个编译错误，这样可以避免潜在的错误。

显式虚函数重载可以提高代码的可读性和可维护性，因为它可以更清晰地表明代码的意图。

## 19.易于使用的多线程编程支持，包括原子类型(atomic types)和线程本地存储(thread-local storage)

C++11标准引入了对多线程编程的支持，包括原子类型和线程本地存储。

原子类型（Atomic types）是一种特殊的类型，可以保证对它们的操作是原子的，即不会被中断或交叉执行，从而避免了竞态条件和数据竞争的问题。在C++11中，可以使用std::atomic模板类来定义原子类型。例如，std::atomic<int>就定义了一个原子整型。

线程本地存储（Thread-local storage）是一种技术，可以让每个线程拥有自己的变量副本，而不会被其他线程访问到。在C++11中，可以使用thread_local关键字来定义线程本地存储变量。

这些功能在多线程编程中非常有用，可以使程序更加健壮和高效。然而，需要注意的是，在使用这些功能时要小心线程安全和同步的问题。

## 20. std::promise && std::future

当我们需要进行异步编程时，C++11提供了std::future和std::promise两个类来支持这种编程模式。std::future和std::promise是通过线程来实现异步编程的。

std::future和std::promise可以一起使用，std::promise负责向std::future传递一个值，而std::future则负责等待这个值的返回。

下面是一个简单的例子，演示了如何使用std::future和std::promise：

```c++
#include <iostream>
#include <future>

int main() {
    std::promise<int> prom;          // 创建promise对象
    std::future<int> fut = prom.get_future();  // 获取future对象

    std::thread t([&](){             // 在另一个线程中设置值
        prom.set_value(10);
    });

    std::cout << "Waiting..." << std::endl;
    fut.wait();                      // 等待值返回
    std::cout << "The result is " << fut.get() << std::endl; // 获取值

    t.join();                        // 等待线程结束

    return 0;
}
```

在这个例子中，我们创建了一个std::promise<int>对象，并调用其get_future()函数获得一个std::future<int>对象。我们将std::promise的值设为10，通过std::future对象获取到了这个值，并打印输出。

需要注意的是，这里我们使用了std::thread来创建了一个线程，并在这个线程中设置了值。在使用std::future和std::promise时，我们可以使用任何线程库来创建线程。

std::future和std::promise的实现中，利用了“期望值（Promise-Future）”的概念。std::promise表示一个期望值，std::future则表示对这个期望值的等待。当我们调用std::promise的set_value()函数来设置期望值时，std::future中对这个期望值的等待就会被唤醒。

总的来说，std::future和std::promise提供了一种简单易用的方式来进行异步编程。它们在实现中依赖于线程，可以通过多种方式创建线程，从而灵活地满足不同的需求。