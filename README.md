# Huffman-encoding-decoding
C++ implementation of Huffman Coding for lossless text compression and decompression using binary trees. #c++  #Huffman-Coding   #Data-Compression   #Algorithms
This repository contains a C++ implementation of Huffman Coding, a classic lossless data compression algorithm. The project demonstrates:

How to calculate character frequencies in a text file.

How to build a Huffman Tree using a priority queue (min-heap) to assign optimal prefix codes.

How to encode text into a compressed binary string.

How to decode the compressed string back into the original text.

The repository includes two separate programs:

Encoder (huffman_encoding.cpp):

Reads input from input.txt

Generates Huffman codes (codes.txt)

Outputs the encoded string (encoded.txt)

Decoder (huffman_decoding.cpp):

Reads encoded.txt and codes.txt

Reconstructs the original text

Outputs to output_decoded.txt

Features

Fully lossless compression

Uses binary tree structure for encoding

Separate encoder and decoder for modularity

Easy to extend for large files or other character sets
