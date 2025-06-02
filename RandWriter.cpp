// Copyright 2025 Brendan Kelleher
#include<vector>
#include<string>
#include "/autograder/playground/RandWriter.hpp"
RandWriter::RandWriter(const std::string& str, size_t k) : gen(std::random_device {}()) {
    size_t len = str.length();
    orig_text = str;
    K = k;
    if (len < k) throw std::invalid_argument("string length is smaller than k");
    for (size_t i = 0; i < len; i++) {
        std::string kgram;

        for (size_t j = 0; j < k; j++) {
            kgram += str[(i+j) % len];
        }
        char next_char = str[(i+k) % len];
        map[kgram][next_char]++;
    }
}
size_t RandWriter::orderK() const {
    return K;
}
int RandWriter::freq(const std::string& kgram) const {
    int freq = 0;
    if (kgram.length() != K)
    throw std::invalid_argument("kgram is of the wrong length");
    auto kgramIt = map.find(kgram);
    if (kgramIt == map.end()) return 0;
    for (const auto& pair : kgramIt->second) {
        freq += pair.second;
    }
    return freq;
}
int RandWriter::freq(const std::string& kgram, char c) const {
    if (kgram.length() != K)
    throw std::invalid_argument("kgram is of the wrong length");
    if (K == 0) {
        int freq = 0;
        for (size_t i = 0; i < orig_text.length(); i++) {
            if (orig_text[i] == c) {
                freq++;
            }
        }
        return freq;
    }
    auto kgramIt = map.find(kgram);
    if (kgramIt == map.end()) return 0;
    auto charIt = kgramIt->second.find(c);
    if (charIt == kgramIt->second.end()) return 0;
    return charIt->second;
}
char RandWriter::kRand(const std::string& kgram) {
    std::vector<char> characters;
    std::vector<int> weights;
    if (kgram.length() != K)
    throw std::invalid_argument("kgram is of the wrong length");
    auto kgramIt = map.find(kgram);
    if (kgramIt == map.end())
    throw std::invalid_argument("kgram was not found in the text");
    for (const auto& pair : kgramIt->second) {
        characters.push_back(pair.first);
        weights.push_back(pair.second);
    }
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    int random_num = dist(gen);
    return characters[random_num];
}
std::string RandWriter::generate(const std::string& kgram, size_t l) {
    std::string markovString = kgram;
    if (kgram.length() != K)
    throw std::invalid_argument("kgram is of the wrong length");
    for (size_t i = K ; i < l; i++) {
         markovString.push_back
        (kRand(markovString.substr(markovString.length() - K)));
    }
    return markovString;
}
