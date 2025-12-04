/*
============================================================
📘 HUFFMAN CODING — GREEDY METHOD
============================================================

🎯 AIM:
To implement Huffman Coding using a greedy approach for 
lossless data compression and find Huffman codes for each character.

------------------------------------------------------------
📋 PSEUDOCODE (for exam):
------------------------------------------------------------
1. Count the frequency of each character in the input.
2. Create a leaf node for each character and insert into a min-heap.
3. Repeat until only one node remains in the heap:
      a) Extract two nodes with the smallest frequencies.
      b) Create a new internal node with frequency = sum of both.
      c) Make the two nodes as left and right children of the new node.
      d) Insert this new node back into the min-heap.
4. The remaining node is the root of the Huffman Tree.
5. Traverse the tree:
      - Append '0' for left branch and '1' for right branch.
      - When a leaf node is reached, assign that binary string as
        the Huffman code for that character.
6. Encode the input text using the generated codes.
7. Optionally, decode it to verify correctness.

------------------------------------------------------------
🧩 IMPORTANT THEORY POINTS (for viva/exam):
------------------------------------------------------------
✅ Huffman coding is a **Greedy Algorithm** — it repeatedly merges the 
   two smallest frequency nodes to form an optimal prefix code.

✅ Produces **Variable Length Codes**:
   - Frequent characters → Shorter codes
   - Rare characters → Longer codes

✅ Ensures **Prefix-Free Property**: No code is a prefix of another.

✅ Used in: File compression (ZIP), JPEG, MP3, MPEG, etc.

✅ Time Complexity: O(n + k log k)
   - n = total characters in input text
   - k = number of unique characters

✅ Space Complexity: O(n + k)

✅ Huffman Tree Nodes = 2k - 1

============================================================
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iomanip> // for table formatting
using namespace std;

// -------------------------------------------
// Node structure for Huffman Tree
// -------------------------------------------
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// -------------------------------------------
// Comparator for priority queue (min-heap)
// -------------------------------------------
struct Compare {
    bool operator()(Node* a, Node* b) {
        // smaller frequency has higher priority
        return a->freq > b->freq;
    }
};


// -------------------------------------------
// Recursive function to generate Huffman Codes
// -------------------------------------------
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    // Leaf node — store the code
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// -------------------------------------------
// Main Huffman Coding Function
// -------------------------------------------
void HuffmanCoding(const string& text) {
    if (text.empty()) {
        cout << "⚠️ Empty input. Please enter some text.\n";
        return;
    }

    // ----------------------------------------------------
    // STEP 1: Calculate frequency of each character
    // Time Complexity: O(n)
    // Space Complexity: O(k)
    // ----------------------------------------------------
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    // ----------------------------------------------------
    // STEP 2: Create a min-heap (priority queue)
    // Time Complexity: O(k log k)
    // Space Complexity: O(k)
    // ----------------------------------------------------
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // ----------------------------------------------------
    // STEP 3: Build Huffman Tree
    // Merge two smallest frequency nodes until one remains
    // Time Complexity: O(k log k)
    // Space Complexity: O(k)
    // ----------------------------------------------------
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    Node* root = pq.top();

    // ----------------------------------------------------
    // STEP 4: Generate Huffman Codes using Tree Traversal
    // Time Complexity: O(k)
    // Space Complexity: O(k)
    // ----------------------------------------------------
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // ----------------------------------------------------
    // STEP 5: Display the Huffman Codes Table
    // ----------------------------------------------------
    cout << "\nCharacter | Frequency | Huffman Code\n";
    cout << "--------------------------------------\n";
    for (auto pair : freq) {
        cout << setw(9) << (pair.first == ' ' ? '_' : pair.first) << " | "
             << setw(9) << pair.second << " | "
             << setw(12) << huffmanCode[pair.first] << "\n";
    }

    // ----------------------------------------------------
    // STEP 6: Encode the text
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // ----------------------------------------------------
    string encoded = "";
    for (char ch : text)
        encoded += huffmanCode[ch];

    cout << "\nOriginal Text: " << text << endl;
    cout << "Encoded Text : " << encoded << endl;

    // ----------------------------------------------------
    // STEP 7: Decode (to verify)
    // Time Complexity: O(n)
    // ----------------------------------------------------
    cout << "\nDecoded Text : ";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            cout << curr->ch;
            curr = root;
        }
    }
    cout << endl;

    // ----------------------------------------------------
    // 📊 SUMMARY:
    // Time Complexity = O(n + k log k)
    // Space Complexity = O(n + k)
    // ----------------------------------------------------
}

// -------------------------------------------
// DRIVER CODE
// -------------------------------------------
int main() {
    string text;
    cout << "Enter text to encode using Huffman Coding: ";
    getline(cin, text);

    HuffmanCoding(text);

    return 0;
}
