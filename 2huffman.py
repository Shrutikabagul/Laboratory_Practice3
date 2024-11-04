import heapq
from collections import defaultdict

# Class for the Huffman Tree node
class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char              # Character
        self.freq = freq              # Frequency of the character
        self.left = None              # Left child
        self.right = None             # Right child

    # Overloading the less-than operator to make this object comparable in the heap
    def __lt__(self, other):
        return self.freq < other.freq

# Function to generate Huffman codes by traversing the tree
def generate_codes(root, current_code, huffman_codes):
    if root is None:
        return

    # If it's a leaf node, it contains a character
    if root.left is None and root.right is None:
        huffman_codes[root.char] = current_code
        return

    # Recurse to left and right with updated code
    generate_codes(root.left, current_code + "0", huffman_codes)
    generate_codes(root.right, current_code + "1", huffman_codes)

# Function to build the Huffman Tree and return the root and codes
def build_huffman_tree(text):
    # Count frequency of each character
    frequency = defaultdict(int)
    for char in text:
        frequency[char] += 1

    # Create a priority queue (min-heap) with leaf nodes for each character
    min_heap = [HuffmanNode(char, freq) for char, freq in frequency.items()]
    heapq.heapify(min_heap)

    # Iterate until we have a single tree (only one node in the heap)
    while len(min_heap) > 1:
        # Pop two nodes with lowest frequency
        left = heapq.heappop(min_heap)
        right = heapq.heappop(min_heap)

        # Create a new node with frequency equal to the sum of the two nodes
        merged = HuffmanNode(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        # Push the merged node back into the heap
        heapq.heappush(min_heap, merged)

    # Root of the Huffman Tree
    root = min_heap[0]

    # Generate Huffman codes
    huffman_codes = {}
    generate_codes(root, "", huffman_codes)

    return root, huffman_codes

# Function to encode the input text using the Huffman codes
def huffman_encoding(text, huffman_codes):
    return ''.join(huffman_codes[char] for char in text)

# Function to decode the encoded text using the Huffman Tree
def huffman_decoding(encoded_text, root):
    decoded_text = ""
    current = root
    for bit in encoded_text:
        # Traverse left for '0' and right for '1'
        if bit == '0':
            current = current.left
        else:
            current = current.right

        # If it's a leaf node, we have found a character
        if current.left is None and current.right is None:
            decoded_text += current.char
            current = root  # Reset to root for next character

    return decoded_text

# Main function to execute Huffman Encoding and Decoding
def main():
    text = input("Enter the text to encode: ")
    root, huffman_codes = build_huffman_tree(text)

    # Display Huffman Codes
    print("\nHuffman Codes for each character:")
    for char, code in huffman_codes.items():
        print(f"{repr(char)} : {code}")

    # Encode the text
    encoded_text = huffman_encoding(text, huffman_codes)
    print("\nOriginal text:", text)
    print("Encoded string:", encoded_text)

    # Decode the encoded text
    decoded_text = huffman_decoding(encoded_text, root)
    print("Decoded text:", decoded_text)

# Execute the program
if __name__ == "__main__":
    main()
