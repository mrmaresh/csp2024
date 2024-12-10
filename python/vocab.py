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
    end_quiz(incorrect_words, len(words))


def create_vocab(vocab):
    vocab = {
        "a MOD b": "Returns the remainder after dividing a by b.",
        "Abstraction": "Reduces information and detail to facilitate focus on relevant concepts. It is a process, a strategy, and the result of reducing detail to focus on concepts relevant to understanding and solving problems.",
        "Algorithm": "Precise sequences of instructions for processes that can be executed by a computer and are implemented using programming languages.",
        "Analog Data": "A continuous method of representing information. An example would be to use a cassette to record and store music or VHS to record and store video.",
        "AND": "(True, True) makes True, (True, False) makes False, (False, True) makes False, (False, False) makes False",
        "OR": "(True, True) makes True, (True, False) makes True, (False, True) makes True, (False, False) makes False",
        "APPEND(aList, value)": "The length of list is increased by 1, and value is placed at the end of list.",
        "Binary": "a numerical system that uses only two digits, 0 and 1, to represent values.",
        "Decimal": "uses ten digits (0-9).",
        "Hexadecimal": "uses base 16, representing large numbers with fewer digits.",
        "Binary Search": "An efficient algorithm for finding an item in a sorted list by repeatedly dividing the list in half.",
        "Linear Search": "An algorithm that iterates through each item in a list until it finds the target value.",
        "Bit": "The single unit of information in a computer, typically represented as a 0 or 1.",
        "Boolean Value": "Used for creating true or false statements.",
        "Byte": "A sequence of 8 bits.",
        "Code Segment": "A collection of program statements that is a part of a program.",
        "Comments": "A way to leave notes about what your code is doing in plain English so others can understand it.",
        "Conditional Statements": "The Boolean expression in an if-structure evaluated to determine which branch of code to execute.",
        "Decryption": "Taking a secret message and reproducing the original plain text.",
        "Element": "An individual value in a list, assigned an index value.",
        "Encryption": "A process of encoding messages to keep them secret, so only 'authorized' parties can read it.",
        "Floating-point representation": "The fixed number of bits used to represent real numbers.",
        "Incremental Design Process": "Breaks the problem into smaller pieces and ensures each piece works before adding it to the whole.",
        "Index": "Identifies a value's unique position in a list.",
        "INSERT(aList, i, value)": "Puts an element into a preexisting list at a particular index. All elements after move up one index.",
        "Iteration": "Statements, also called loops, repeat themselves until the stopping condition is met.",
        "Iterative Design Process": "Programmers develop prototypes, implement feedback cycles, and experiment to improve programs.",
        "Logic gate": "A device performing a Boolean logic operation on one or more binary inputs and outputs a single binary value.",
        "Logical Operators": "Symbols or words connecting expressions to form compound expressions. Examples include AND, OR, and NOT.",
        "Metadata": "Data about data, providing additional information about aspects of that data.",
        "Nested Conditional Statements": "if-then statements inside of other if-then statements.",
        "Overflow error": "Error resulting when the number of bits is insufficient to represent a number (like a car's odometer 'rolling over').",
        "Parameters": "Inputs to a procedure or function, named when the function is defined and assigned a value when called.",
        "Procedure": "A group of programming instructions. Also known as methods or functions in some programming languages.",
        "Program Inputs": "Data sent to a computer for processing by a program, in forms such as tactile, audio, visual, or text.",
        "Relational Operators": "Used to test relationships between variables, expressions, or values, returning a Boolean value.",
        "Run-time error": "A mistake in a program that happens only when it is run, such as accessing nonexistent memory.",
        "Selection": "An algorithm's ability to select between two alternative paths based on a condition (if/else).",
        "Sequencing": "The application of each step of an algorithm in the order given.",
        "Software Library": "A collection of pre-written procedures for use in programs, such as displaying images or finding derivatives.",
        "String Concatenation": "The operation of joining strings end-to-end. For example, 'snow' and 'ball' becomes 'snowball'.",
        "Substring": "A part of a string.",
        "Syntax error": "A mistake in code that violates programming language rules, preventing the code from running.",
        "Logic error": "A mistake in an algorithm or program causing unexpected behavior or incorrect results.",
        "Traversing a List": "The process of accessing each item in a list one at a time.",
        "Variable": "A placeholder in your program for a value, like in math. Usually represented by letters or words."
    }

    return vocab



def run_quiz(vocab, words, definitions, incorrect_words):
    system('clear')
    random.shuffle(definitions)
    num_definitions = len(definitions)
    count = 0
    for definition in definitions:
        print(f"Definition: {definition} \n")

        # Select the correct word for the definition
        for word in words:
            if vocab[word] == definition:
                correct_word = word
                break

        # create a list of options
        options = [correct_word]
        while len(options) < 10:
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
        print()
        while True:
            answer = input("Your choice (1-10): ")
            if not answer.isdigit():
                continue
            answer = int(answer)
            if answer >= 1 and answer <=10:
                break
        print()

        if options[answer - 1] != correct_word:
            print(f"Incorrect! The correct word was {correct_word}.")
            incorrect_words.append(correct_word)
        else:
            print("Correct!")

        print()
        count = count + 1
        print(f"{num_definitions - count} more to go")
        get_string("Press enter to continue ...")
        system('clear')






def end_quiz(incorrect_words, total):

    if len(incorrect_words) != 0:
        print(f"You got {100 - 100*len(incorrect_words)/total:.1f}% correct!")
        print("You got the following words wrong:\n")
        for word in incorrect_words:
            print(word)
    else:
        print("Congratulations! You answered all questions correctly.")




main()
