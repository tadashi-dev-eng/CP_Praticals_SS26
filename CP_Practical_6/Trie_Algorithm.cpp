#include <iostream>   
#include <string>     
#include <vector>     

using namespace std; 

class TrieNode {
    public:
    // pointers for each lowercase English letter a-z
     // flag that indicates whether a word ends at this node

        TrieNode* children[26]; 
        bool endofWord;        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                // initialize all child pointers to null
                children[i] = nullptr; 
            }
            // initialize the word-end flag to false
            endofWord = false; 
        }
};

class Trie {
    private:
        TrieNode* root; 

    public:
        Trie() { root = new TrieNode(); } // construct trie with an empty root node

        // function to insert a word into the trie
        void insert(string word) {
            TrieNode* currNode = root; // start traversal from root
            for (char c : word) {      // loop through each character in the word
                int index = c - 'a';   // map character to array index 0..25
                if (currNode->children[index] == nullptr) {
                    currNode->children[index] = new TrieNode(); // create new node if needed
                }
                currNode = currNode->children[index]; // move to the next node
            }
            currNode->endofWord = true; // mark the final node as the end of a word
        }

        // function to search for a word in the trie
        bool search(string word) {
            TrieNode* currNode = root; // start traversal from root
            for (char c : word) {      // loop through each character in the word
                int index = c - 'a';   // map character to array index 0..25
                if (currNode->children[index] == nullptr) {
                    return false;      // if child node does not exist, word is not present
                }
                currNode = currNode->children[index]; // move to the next node
            }
            return currNode->endofWord; // return true only if the final node marks a word end
        }

        // function to remove a word from the trie
        void remove(string word) {
            TrieNode* currNode = root; // start traversal from root
            for (char c : word) {      // loop through each character in the word
                int index = c - 'a';   // map character to array index 0..25
                if (currNode->children[index] == nullptr) {
                    return;            // if path is missing, the word does not exist
                }
                currNode = currNode->children[index]; // move to the next node
            }
            currNode->endofWord = false; // unmark the end-of-word flag to delete the word logically
        }
};

int main() {
    Trie trie;                              // create a new empty trie
    trie.insert("tashi");                 // insert the word "Tashi" into the trie
    trie.insert("penjor");                // insert the word "Penjor" into the trie
    trie.insert("sonam");                 // insert the word "Sonam" into the trie

    cout << "Trie Present:" << endl;       // print heading text

    cout << trie.search("tshewang") << endl; // print result of searching "Tashi"
    cout << trie.search("pema") << endl; // print result of searching "Penjor"
    cout << trie.search("seldon") << endl; // print result of searching "Sonam"

    trie.remove("penjor");                // remove "Penjor" from the trie by clearing its end flag
    cout << trie.search("something") << endl; // print result of searching "Penjor" after removal

    return 0;                               // return 0 to indicate successful program exit
}
