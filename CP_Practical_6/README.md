# Trie Algorithm

The trie algorithm implements a basic trie (prefix tree) for lowercase English words. The trie uses an array of 26 child pointers in each node to represent the letters `a` - `z`. Words are inserted, searched, and removed by walking down child pointers according to each character in the input string. 

### Time Complexity

- `insert(word)`: O(L), where L is the length of the word. Each character is processed once.
- `search(word)`: O(L), where L is the length of the word. 
- `remove(word)`: O(L), where L is the length of the word. The implementation only unmarks the end-of-word flag and does not free nodes.

### Space Complexity

- Worst-case space: `O(N * L * 26)` for the trie structure, where N is the number of words and L is the average word length. Each node allocates an array of 26 pointers.

