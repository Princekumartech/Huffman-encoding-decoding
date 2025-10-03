#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

//  structure for min-heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

//  Huffman code recursively
void buildCodes(Node* root, string code, unordered_map<char, string>& huffCodes) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffCodes[root->ch] = code;
    }
    buildCodes(root->left, code + "0", huffCodes);
    buildCodes(root->right, code + "1", huffCodes);
}

int main() {
    // input
    ifstream in_file("input.txt");
    if (!in_file.is_open()) {
        cerr << "Error: input.txt not found!" << endl;
        return 1;
    }
    string text;
    getline(in_file, text);
    in_file.close();

    if (text.empty()) {
        cerr << "Error: input.txt is empty!" << endl;
        return 1;
    }

    // Frequency map
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    // Huffman Tree
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq) pq.push(new Node(p.first, p.second));
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    Node* root = pq.top();

    //  Huffman Codes
    unordered_map<char, string> huffCodes;
    buildCodes(root, "", huffCodes);

    //  input
    string encoded_string = "";
    for (char ch : text) encoded_string += huffCodes[ch];

    //  Write to files
    ofstream enc_file("encoded.txt", ios::trunc);
    enc_file << encoded_string;
    enc_file.close();

    ofstream code_file("codes.txt", ios::trunc);
    for (auto& p : huffCodes) {
        code_file << p.first << ":" << p.second << "\n";
    }
    code_file.close();

    cout << "Encoding complete. Check encoded.txt and codes.txt" << endl;
    return 0;
}
