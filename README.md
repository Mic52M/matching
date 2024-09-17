# README for C Program: File String Matcher

## Overview
This C program reads a file provided by the user, scans each line, and compares the input string with the content before the comment character (`#`). If a match is found, it prints the content after the comment character. The program handles files with a specific format, where each line contains a string followed by a comment starting with `#`.

## Functionality
The program performs the following tasks:
1. Prompts the user to enter a filename and an input string.
2. Opens the specified file for reading.
3. Reads each line of the file and removes the newline character if present.
4. Searches for the comment character `#` in the line. If found, the program separates the string before `#` and the comment after it.
5. Compares the string before the `#` with the user's input string.
6. If a match is found, the program prints the comment. If no comment exists, it prints "Match not found".
7. If the file cannot be opened, an error message is displayed.

## Input File Format
The input file should have the following structure:
- Each line should consist of a string followed by a comment, separated by a `#`.
- Example:
  ```
  fc54e0d16d9764783542f0146a98b300#AsyncRAT
  8515076cbbca9dce33151b798f782456#BitRAT
  ...
  ```

## Example Usage
1. The user is prompted to enter the name of the file and an input string:
   ```
   Inserisci il nome del file: input.txt
   Inserisci l'input: fc54e0d16d9764783542f0146a98b300
   ```

2. The program opens the file `input.txt` and reads each line. It then checks if the input string matches the part before `#` in any of the lines.

3. If a match is found, the program prints the comment after the `#`:
   ```
   Corrispondenza trovata: AsyncRAT
   ```

4. If no match is found, the program will print:
   ```
   Corrispondenza non trovata
   ```

## Error Handling
- If the file cannot be opened (e.g., due to an incorrect filename), the program will display the following error message:
  ```
  Impossibile aprire il file [filename]
  ```

## How to Compile
To compile the program, use a C compiler such as `gcc`:
```bash
gcc -o file_matcher file_matcher.c
```

## How to Run
After compilation, you can run the program using the following command:
```bash
./file_matcher
```

## Limitations
- The maximum length for strings (input, file lines, and buffer) is set to 100 characters, which is defined by the constant `MAX_STRING_LENGTH`. This can be adjusted based on your needs.
- The program does not support multi-line comments or complex file formats. Each line should contain a single string and an optional comment following `#`.

## Future Improvements
- Adding support for more complex input file formats.
- Implementing case-insensitive string comparison.
- Allowing for dynamic memory allocation to handle larger strings.

