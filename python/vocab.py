import random
from os import system
from cs50 import get_string


def main():
    # Build vocab dictionary
    vocab = {}
    vocab = create_vocab(vocab)

    # List of words and their corresponding definition
    words = list(vocab.keys())
    definitions = list(vocab.values())

    # List to store incorrect words
    incorrect_words = []

    run_quiz(vocab, words, definitions)
    end_quiz()


def create_vocab(vocab):
    vocab = {
        "aberration": "a departure from what is normal or expected",
        "benevolent": "well-meaning and kindly",
        "cogent": "clear, logical, and convincing",
        "effervescent": "bubbling or fizzing, enthusiastic",
    }
    return vocab



def run_quiz(vocab, words, definitions):
    system('clear')
    for definition in definitions:
        print(f"Definition: {definition} \n")

        # Select the correct word for the definition
        for word in words:
            if vocab[word] == definition:
                correct_word = word
                break



def end_quiz():
    pass




main()
