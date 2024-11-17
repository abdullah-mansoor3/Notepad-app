 # Notepad App

 ## How to Run
 1. Open the terminal.
 2. Run the following command:
    ```bash
    make clean && make && ./notepad
    ```

 ---

 ## Class Structure

 ### `Notepad` Class
 - **Role**: The main class of the application.
 - **Responsibilities**:
   - Contains references to the `Frontend` and `Backend` class objects.
   - Its central "doEverything()" function:
     - Calls `Frontend` display and input functions.
     - Manages interactions between the user interface and backend operations.

 ### `Frontend` Class
 - **Role**: Handles user interactions.
 - **Responsibilities**:
   - Displays the interface and collects input.
   - Has a reference to the `Backend` class object to:
     - Pass user input.
     - Retrieve and display output (e.g., text, suggestions).

 ### `Backend` Class
 - **Role**: Manages data and logic for text operations and suggestions.
 - **Components**:
   - **AVL Tree**: Stores a dictionary for fast word searching.
   - **List**: Keeps track of all typed text.
   - **Stack**: Stores the last word typed (for insertion and deletion operations).
   - **Dynamic Array**: Holds suggestions for the current word.
 - **Responsibilities**:
   - Updates text and generate suggestions according to `Frontend` input.
   - Calls `getSuggestions` after each insertion or deletion.
   - **File Loading**: Clears current text and loads content from `notepad.txt`.
   - **File Saving**: Saves current text to `notepad.txt`.

 ### `AVL` Class
 - **Role**: Manages a dictionary for fast word lookup.
 - **Key Functions**:
   - **Insertion**: Adds new words.
   - **Search**: Finds if a word exists.
   - **Delete Tree**: Removes all nodes when the program exits(balance is not updated). No `deleteNode` is implemented since nodes are deleted only at exit.
 - **Suggestion Logic**:
   `getSuggestions` generates up to 4 suggestions for a word using these methods:
   - **Insertion**: Inserts a letter at every position to form valid words.
   - **Substitution**: Replaces each letter with other letters to form valid words.
   - **Omission**: Removes one letter at a time to form valid words.
   - **Reversal**: Swaps adjacent letters to form valid words.

 ---

 ## Features
 - **Dynamic Text Management**: Tracks and updates the typed text efficiently.
 - **Word Suggestions**: Provides real-time suggestions based on the current word using multiple strategies.
 - **File Handling**: Supports saving and loading text from a file (`notepad.txt`).
 - **Fast Search**: Uses an AVL tree for quick word lookups.

 ---
