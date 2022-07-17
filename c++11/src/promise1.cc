#include <iostream>
#include <future>
#include <exception>
#include <string>
using namespace std;

void doSomething(std::promise<string> &p)
{
  try
  {
    cout << "input char:";
    char c = cin.get();

    if (c == 'x')
    {
      throw std::runtime_error(std::string("char") + c + " read");
    }
    else
    {
      std::string s = string("char ") + c + " processed";
      p.set_value(s);
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    p.set_exception(std::current_exception());
  }
}
int main()
{
  try
  {
    std::promise<string> p;
    std::future<std::string> f(p.get_future());

    //必须以引用类型传递promise
    std::thread t(doSomething, std::ref(p));
    t.detach();
    //当promise被set后，get方可获得，否则block
    cout << "result:" << f.get() << endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}