# Text_Generator
# Random Text Generator with Markov Model

## Overview

This project implements a **random text generator** using a **Markov chain model**. The generator uses **k-grams** (sequences of `k` consecutive characters) to build a statistical model based on the frequency of character occurrences following a k-gram in the given input text. It then uses this model to generate new text based on a starting k-gram, creating text that simulates the statistical patterns of the input.

## Features

- Generates random text of customizable length based on the frequencies of k-grams in the input.
- Allows dynamic control of k-gram length and output text length via command line arguments.
- Implements a Markov chain model where the probability of a character following a sequence is based on its frequency in the input text.

## Key Concepts

- **Markov Chain**: A mathematical system that undergoes transitions between states according to certain probabilistic rules. In this project, the states are k-grams, and the transitions are based on the frequency of characters following those k-grams.
- **K-gram**: A sequence of `k` consecutive characters that captures dependencies between adjacent characters in the text.

## Installation

### Requirements
- **C++11 or later** compiler
- **SFML** (Simple and Fast Multimedia Library) for input/output handling. 

### Steps
1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/username/RandomTextGenerator.git
    cd RandomTextGenerator
    ```

2. Compile the program:

    ```bash
    g++ -std=c++11 -o randwriter main.cpp RandWriter.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```

3. (Optional) If you haven't installed **SFML**, you may need to follow the instructions for your operating system from the official [SFML website](https://www.sfml-dev.org/download.php).

## Usage

To generate random text, run the program with the following command line arguments:

```bash
./randwriter <k> <l>
