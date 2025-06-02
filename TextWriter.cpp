// Copyright 2025 Brendan Kelleher
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include "./RandWriter.hpp"
int main(int argc, char* argv[]) {
    try {
    int k = atoi(argv[1]);
    int l = atoi(argv[2]);
    std::string inputText((std::istreambuf_iterator<char>(std::cin)),
                          std::istreambuf_iterator<char>());
    RandWriter R(inputText, k);
    std::string kgram = inputText.substr(0, k);
    std::string outputText = R.generate(kgram, l);
    std::cout << outputText << std::endl;
    }
    catch(const std::invalid_argument& arg) {
        std::cerr << arg.what() << std::endl;
    }
    return 0;
}
