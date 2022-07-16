#include <iostream>
#include <future>
#include <thread>
using namespace std;

int queryNumber()
{
  std::cout << "read number:";
  int num;
  std::cin >> num;
  if (!cin)
  {
    throw runtime_error("no number read");
  }

  return num;
}
int doSomething(char c, shared_future<int> f)
{
  try
  {
    int num = f.get();

    for (int i = 0; i < num; i++)
    {
      this_thread::sleep_for(chrono::microseconds(100));
      cout.put(c).flush();
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << this_thread::get_id() << e.what() << '\n';
  }
}

int main()
{
  try
  {
    std::shared_future<int> f = std::async(std::launch::async, queryNumber);

    auto f1 = async(std::launch::async, doSomething, '.', f);
    auto f2 = async(std::launch::async, doSomething, '+', f);
    auto f3 = async(std::launch::async, doSomething, '*', f);

    f1.get();
    f2.get();
    f3.get();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  cout << "\ndone" << endl;
}