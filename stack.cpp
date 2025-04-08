#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> mystack1;
    stack<int> mystack2;
    int n, count;

    cout << "How many product IDs do you want to enter? ";
    cin >> count;

    for (int x = 1; x <= count; x++) {
        cout << "Enter a product ID: ";
        cin >> n;
        mystack1.push(n);
    }
    cout << "-----------------------------------" << endl;
    cout << "Product's ID : " << endl;
    while (!mystack1.empty()) {
        cout << mystack1.top() << endl;
        mystack2.push(mystack1.top());
        mystack1.pop();
    }
    cout << "----------------------------------" << endl;
    cout << "Product's ID2: \n" << endl;
    while (!mystack2.empty()) {
        cout << mystack2.top() << endl;
        mystack2.pop();
    }
    return 0;
}
