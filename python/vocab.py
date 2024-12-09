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

    run_quiz(vocab, words, definitions, incorrect_words)
    end_quiz(incorrect_words)


def create_vocab(vocab):
    vocab = {
        "aberration": "a departure from what is normal or expected",
        "benevolent": "well-meaning and kindly",
        "cogent": "clear, logical, and convincing",
        "effervescent": "bubbling or fizzing, enthusiastic",
    }
    return vocab



def run_quiz(vocab, words, definitions, incorrect_words):
    system('clear')
    random.shuffle(definitions)
    for definition in definitions:
        print(f"Definition: {definition} \n")

        # Select the correct word for the definition
        for word in words:
            if vocab[word] == definition:
                correct_word = word
                break

        # create a list of options
        options = [correct_word]
        while len(options) < 4:
            random_word = random.choice(words)
            if random_word not in options:
                options.append(random_word)
        random.shuffle(options) # Shuffle to randomize the order

        # Present options
        number = 1
        for option in options:
            print(f"{number}. {option}")
            number = number + 1

        # Get user input and check the answer
        answer = input("Your choice (1-4): ")
        print()

        if options[int(answer) - 1] != correct_word:
            print(f"Incorrect! The correct word was {correct_word}.")
            incorrect_words.append(correct_word)

        print()
        get_string("Press enter to continue ...")
        system('clear')






def end_quiz(incorrect_words):
    if len(incorrect_words) != 0:
        print("You got the following words wrong:\n")
        for word in incorrect_words:
            print(word)
    else:
        print("Congratulations! You answered all questions correctly.")




main()
