#include <iostream>
#include <initializer_list>
#include <vector>

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
