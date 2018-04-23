#include <iostream>
#include <string>
#include <bitset>
#include <math.h>

std::string str = "";

// Initialize hash values (first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19)
std::string h0_string = "6a09e667";
std::string h1_string = "bb67ae85";
std::string h2_string = "3c6ef372";
std::string h3_string = "a54ff53a";
std::string h4_string = "510e527f";
std::string h5_string = "9b05688c";
std::string h6_string = "1f83d9ab";
std::string h7_string = "5be0cd19";

unsigned int h0;
unsigned int h1;
unsigned int h2;
unsigned int h3;
unsigned int h4;
unsigned int h5;
unsigned int h6;
unsigned int h7;

unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
unsigned int e;
unsigned int f;
unsigned int g;
unsigned int h;


// Initialize array of round constants: (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311)
const std::string k_string[64] = {"428a2f98", "71374491", "b5c0fbcf", "e9b5dba5", "3956c25b", "59f111f1", "923f82a4", "ab1c5ed5",
                            "d807aa98", "12835b01", "243185be", "550c7dc3", "72be5d74", "80deb1fe", "9bdc06a7", "c19bf174",
                            "e49b69c1", "efbe4786", "0fc19dc6", "240ca1cc", "2de92c6f", "4a7484aa", "5cb0a9dc", "76f988da",
                            "983e5152", "a831c66d", "b00327c8", "bf597fc7", "c6e00bf3", "d5a79147", "06ca6351", "14292967",
                            "27b70a85", "2e1b2138", "4d2c6dfc", "53380d13", "650a7354", "766a0abb", "81c2c92e", "92722c85",
                            "a2bfe8a1", "a81a664b", "c24b8b70", "c76c51a3", "d192e819", "d6990624", "f40e3585", "106aa070",
                            "19a4c116", "1e376c08", "2748774c", "34b0bcb5", "391c0cb3", "4ed8aa4a", "5b9cca4f", "682e6ff3",
                            "748f82ee", "78a5636f", "84c87814", "8cc70208", "90befffa", "a4506ceb", "bef9a3f7", "c67178f2"};

unsigned int k[64];

std::string stringToBinary(std::string msg) {
    std::string temp = "";
    std::string result = "";
    for(std::size_t i = 0; i < msg.size(); ++i) {
        temp = std::bitset<8>(msg.c_str()[i]).to_string();
        result += temp;
    }
    return result;
}

unsigned int stringToHex(std::string hexString) {
    unsigned int hex = 0;
    for(int i = 0; i < hexString.length(); i++) {
        char character = hexString[i];
        int value;
        if(character == 'a' || character == 'A') {
            value = 10;
        } else if (character == 'b' || character == 'B') {
            value = 11;
        } else if (character == 'c' || character == 'C') {
            value = 12;
        } else if (character == 'd' || character == 'D') {
            value = 13;
        } else if (character == 'e' || character == 'E') {
            value = 14;
        } else if (character == 'f' || character == 'F') {
            value = 15;
        } else {
            value = (int)character - 48;
        }
        hex += value * pow(16, hexString.length() - 1 - i);
    }
    return hex;
}

unsigned int binaryToint(std::string binary) {
    std::string hex = "";
    for(int i = 0; i < binary.length() / 4; i++) {
        std::string temp = binary.substr(i * 4, 4);
        if(temp == "0000") {
            hex += "0";
        } else if (temp == "0001") {
            hex += "1";
        } else if (temp == "0010") {
            hex += "2";
        } else if (temp == "0011") {
            hex += "3";
        } else if (temp == "0100") {
            hex += "4";
        } else if (temp == "0101") {
            hex += "5";
        } else if (temp == "0110") {
            hex += "6";
        } else if (temp == "0111") {
            hex += "7";
        } else if (temp == "1000") {
            hex += "8";
        } else if (temp == "1001") {
            hex += "9";
        } else if (temp == "1010") {
            hex += "A";
        } else if (temp == "1011") {
            hex += "B";
        } else if (temp == "1100") {
            hex += "C";
        } else if (temp == "1101") {
            hex += "D";
        } else if (temp == "1110") {
            hex += "E";
        } else {
            hex += "F";
        }
    }
    return stringToHex(hex);
}

std::string decimalToBinary(unsigned int n)
{
    std::string binary = "";
    // array to store binary number
    std::string binaryArr[1000];

    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryArr[i] = std::to_string(n % 2);
        n /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        binary += binaryArr[j];
    }
    return binary;
}

std::string decimalToHex(unsigned int n)
{
    std::string hex = "";
    // array to store hex number
    std::string hexArr[1000];

    int i = 0;
    while (n > 0) {
        // storing remainder in hex array
        int temp = n % 16;
        if (temp == 10) {
            hexArr[i] = "a";
        } else if (temp == 11) {
            hexArr[i] = "b";
        } else if (temp == 12) {
            hexArr[i] = "c";
        } else if (temp == 13) {
            hexArr[i] = "d";
        } else if (temp == 14) {
            hexArr[i] = "e";
        } else if (temp == 15) {
            hexArr[i] = "f";
        } else {
            hexArr[i] = std::to_string(temp);
        }
        n = n / 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        hex += hexArr[j];
    }
    return hex;
}

std::string sha256(std::string input) {
    h0 = stringToHex(h0_string);
    h1 = stringToHex(h1_string);
    h2 = stringToHex(h2_string);
    h3 = stringToHex(h3_string);
    h4 = stringToHex(h4_string);
    h5 = stringToHex(h5_string);
    h6 = stringToHex(h6_string);
    h7 = stringToHex(h7_string);

    for(int i = 0; i < 64; i++) {
        k[i] = stringToHex(k_string[i]);
    }

    str = input;
    str = stringToBinary(str);
    // Pre-processing:
    // begin with the original message of length L bits
    int L = str.length();
    // append a single '1' bit
    str += "1";
    // append K '0' bits, where K is the minimum number >= 0 such that L + 1 + K + 64 is a multiple of 512
    int K = 0;
    while ((L + 1 + K + 64) % 512 != 0) {
      str += "0";
      K += 1;
    }
    // append L as a 64-bit big-endian integer, making the total post-processed length a multiple of 512 bits
    std::string binary = std::bitset<64>(L).to_string();
    str += binary;

    // Process the message in successive 512-bit chunks:
    // break message into 512-bit chunks
    int N = str.length() / 512;
    std::string msg[N];
    for(int i = 0; i < N; i++) {
        msg[i] = str.substr(i * 512, 512);
    }

    // for each chunk
    for(int i = 0; i < N; i++) {

        // create a 64-entry message schedule array w[0..63] of 32-bit words
        // (The initial values in w[0..63] dont matter, so many implementations zero them here)
        unsigned int w[] = {0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0};
        //copy chunk into first 16 words w[0..15] of the message schedule array
        for(int j = 0; j < 16; j++) {
            w[j] = binaryToint(msg[i].substr(j * 32, 32));
        }

        // Extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array:
        //for i from 16 to 63
        for(int j = 16; j < 64; j++) {
            //s0 := (w[i-15] rightrotate 7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift 3)
            unsigned int s0 =  ((w[j - 15] >> 7) | (w[j - 15] << ((sizeof(w[j - 15]) << 3) - 7))) ^ ((w[j - 15] >> 18) | (w[j - 15] << ((sizeof(w[j - 15]) << 3) - 18))) ^ (w[j - 15] >> 3);
            //s1 := (w[i-2] rightrotate 17) xor (w[i-2] rightrotate 19) xor (w[i-2] rightshift 10)
            unsigned int s1 =  ((w[j - 2] >> 17) | (w[j - 2] << ((sizeof(w[j - 2]) << 3) - 17))) ^ ((w[j - 2] >> 19) | (w[j - 2] << ((sizeof(w[j - 2]) << 3) - 19))) ^ (w[j - 2] >> 10);
            //w[i] := w[i-16] + s0 + w[i-7] + s1
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        // Initialize working variables to current hash value:
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;


        // Compression function main loop:
        for(int j = 0; j < 64; j++) {
            // S1 := (e rightrotate 6) xor (e rightrotate 11) xor (e rightrotate 25)
            unsigned int S1 = ((e >> 6) | (e << ((sizeof(e) << 3) - 6))) ^ ((e >> 11) | (e << ((sizeof(e) << 3) - 11))) ^ ((e >> 25) | (e << ((sizeof(e) << 3) - 25)));
            // ch := (e and f) xor ((not e) and g)
            unsigned int ch = (e & f) ^ ( (~e) & g);
            // temp1 = h + S1 + ch + K[i] + w[i]
            unsigned int temp1 = h + S1 + ch + k[j] + w[j];
            // S0 := (a rightrotate 2) xor (a rightrotate 13) xor (a rightrotate 22)
            unsigned int S0 = ((a >> 2) | (a << ((sizeof(a) << 3) - 2))) ^ ((a >> 13) | (a << ((sizeof(a) << 3) - 13))) ^ ((a >> 22) | (a << ((sizeof(a) << 3) - 22)));
            // maj := (a and b) xor (a and c) xor (b and c)
            unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
            // temp2 := S0 + maj
            unsigned int temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;

        }
    }


    // Add the compressed chunk to the current hash value:
    h0 += a;
    h0_string = decimalToHex(h0);
    h1 += b;
    h1_string = decimalToHex(h1);
    h2 += c;
    h2_string = decimalToHex(h2);
    h3 += d;
    h3_string = decimalToHex(h3);
    h4 += e;
    h4_string = decimalToHex(h4);
    h5 += f;
    h5_string = decimalToHex(h5);
    h6 += g;
    h6_string = decimalToHex(h6);
    h7 += h;
    h7_string = decimalToHex(h7);

// Produce the final hash value (big-endian):
std::string hash = decimalToHex(h0) + decimalToHex(h1) + decimalToHex(h2) + decimalToHex(h3) + decimalToHex(h4) + decimalToHex(h5) + decimalToHex(h6) + decimalToHex(h7);
return hash;
}
