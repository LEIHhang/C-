#include <thread>
#include <exception>
#include <iostream>
#include <random>

using namespace std;

void doSomething(int num, char c)
{
  try
  {
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(1, 100);
    for (int i = 0; i < num; i++)
    {
      std::this_thread::sleep_for(chrono::microseconds(id(dre)));
      cout.put(c).flush();
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "threadID:" << std::this_thread::get_id() << '\n';
  }
}

int main()
{
  try
  {
    std::thread t1(doSomething, 5, '.');
    cout << "- start fg thread" << t1.get_id() << endl;

    for (int i = 0; i < 5; i++)
    {
      std::thread t(doSomething, 10, '+');
      cout << "- detach bg thread" << t.get_id() << endl;
      t.detach();
    }

    cin.get();
    cout << "- join fg thread" << endl;
    t1.join();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}
