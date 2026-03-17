#include <iostream>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

int main() {
    deque<int> line;
    string operation;
    bool sawInput = false;

    // Read operations until EOF
    while (getline(cin, operation)) {
        if (operation.empty())
            continue;

        sawInput = true;
        istringstream iss(operation);
        string cmd;
        iss >> cmd;

        if (cmd == "push_front") {
            int x;
            if (iss >> x) {
                line.push_front(x);
            }
        } else if (cmd == "push_back") {
            int x;
            if (iss >> x) {
                line.push_back(x);
            }
        } else if (cmd == "pop_front") {
            if (!line.empty()) {
                line.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (!line.empty()) {
                line.pop_back();
            }
        }

        // Print current line contents
        if (line.empty()) {
            cout << "<empty>";
        } else {
            for (int v : line) {
                cout << v << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
