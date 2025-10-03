#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// Huffman decoding
string huffman_decoding(const string& encoded_string) {
    unordered_map<string, char> code_table;
    
    // Read codes from codes.txt
    ifstream code_file("codes.txt");
    if (!code_file.is_open()) {
        cerr << "Error: Unable to open codes.txt" << endl;
        return "";
    }
    
    string line;
    while (getline(code_file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            char ch = line[0];                  // left side = character
            string code = line.substr(pos + 1); // right side = code
            code_table[code] = ch;
        }
    }
    code_file.close();

    string decoded_string = "";
    string current_code = "";

    for (char bit : encoded_string) {
        current_code += bit;
        if (code_table.find(current_code) != code_table.end()) {
            decoded_string += code_table[current_code];
            current_code = "";
        }
    }
    return decoded_string;
}

int main() {
    // Read encoded string from encoded.txt
    ifstream in_file("encoded.txt");
    if (!in_file.is_open()) {
        cerr << " Error: encoded.txt not found. Run encoder first." << endl;
        return 1;
    }
    
    string encoded_string;
    getline(in_file, encoded_string);
    in_file.close();
    
    if (encoded_string.empty()) {
        cerr << " Error: encoded.txt is empty." << endl;
        return 1;
    }

    // Decode
    string decoded_string = huffman_decoding(encoded_string);

    // Save result to output_decoded.txt
    ofstream out_file("output_decoded.txt", ios::trunc);
    if (!out_file.is_open()) {
        cerr << " Error: Unable to create output_decoded.txt" << endl;
        return 1;
    }
    out_file << "decoded string is " << decoded_string << "\n";
    out_file.close();

    cout << " Decoding complete. Check output_decoded.txt" << endl;
    return 0;
}
