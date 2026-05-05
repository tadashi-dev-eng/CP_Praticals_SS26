#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// A compact node for the Patricia trie.
// Each edge label is stored as a string, and children point to the next node.
struct Node {
    bool word = false;                                // marks the end of a stored key
    vector<pair<string, Node*>> children; // edge label -> child node pairs
    ~Node() { for (auto &p : children) delete p.second; }
};

// Compute the length of the common prefix between two strings.
static size_t commonPrefix(const string &a, const string &b) {
    size_t i = 0, n = min(a.size(), b.size());
    while (i < n && a[i] == b[i]) ++i;
    return i;
}

class PatriciaTrie {
    Node *root = new Node; // root node has no incoming edge label
public:
    ~PatriciaTrie() { delete root; }

    // Insert a key into the Patricia trie.
    void insert(string s) {
        Node *n = root;
        while (!s.empty()) {
            auto it = find_if(n->children.begin(), n->children.end(),
                [&](auto &p){ return p.first[0] == s[0]; });
            // If no child starts with this character, add a new edge/node.
            if (it == n->children.end()) {
                n->children.emplace_back(move(s), new Node{true});
                return;
            }
            size_t l = commonPrefix(it->first, s);
            // If the existing edge partially matches, split the edge.
            if (l < it->first.size()) {
                Node *split = new Node;
                split->children.emplace_back(it->first.substr(l), it->second);
                it->first = s.substr(0, l);
                it->second = split;
                // If the key ends at the split point, mark the split node as a word.
                if (l == s.size()) split->word = true;
                else split->children.emplace_back(s.substr(l), new Node{true});
                return;
            }
            // Entire edge matched, continue down the trie with the remaining suffix.
            s.erase(0, l);
            n = it->second;
        }
        // Exact key exists on this node; mark it as a word.
        n->word = true;
    }

    // Search for an exact key in the Patricia trie.
    bool search(string s) const {
        const Node *n = root;
        while (!s.empty()) {
            auto it = find_if(n->children.begin(), n->children.end(),
                [&](auto &p){ return p.first[0] == s[0]; });
            if (it == n->children.end()) return false;
            // The stored edge label must fully match the prefix of the remaining string.
            if (commonPrefix(it->first, s) != it->first.size()) return false;
            s.erase(0, it->first.size());
            n = it->second;
        }
        return n->word;
    }

    // Remove a key from the trie and prune nodes if needed.
    bool remove(string s) {
        vector<pair<Node*, size_t>> path;
        Node *n = root;
        while (!s.empty()) {
            auto it = find_if(n->children.begin(), n->children.end(),
                [&](auto &p){ return p.first[0] == s[0]; });
            if (it == n->children.end() || commonPrefix(it->first, s) != it->first.size()) return false;
            size_t idx = it - n->children.begin();
            path.emplace_back(n, idx);
            s.erase(0, it->first.size());
            n = it->second;
        }
        if (!n->word) return false;
        n->word = false;
        // Walk backwards and collapse nodes that are no longer needed.
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            Node *parent = it->first;
            size_t idx = it->second;
            Node *child = parent->children[idx].second;
            if (child->word || child->children.size() > 1) break;
            if (child->children.empty()) {
                delete child;
                parent->children.erase(parent->children.begin() + idx);
            } else {
                auto &g = child->children[0];
                parent->children[idx].first += g.first;
                parent->children[idx].second = g.second;
                g.second = nullptr;
                delete child;
            }
        }
        return true;
    }
};

int main() {
    PatriciaTrie trie;
    for (auto s : {"apple", "app", "apricot", "banana", "band", "bandage"}) trie.insert(s);
    for (auto s : {"app", "apple", "apricot", "banana", "band", "bandage", "ban", "apples"})
        cout << s << ": " << (trie.search(s) ? "found\n" : "not found\n");
    trie.remove("band");
    trie.remove("apple");
    cout << "\nAfter deletion:\n";
    for (auto s : {"band", "bandage", "apple", "app"})
        cout << s << ": " << (trie.search(s) ? "found\n" : "not found\n");
}
