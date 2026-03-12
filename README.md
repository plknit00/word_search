# Advanced Word Search Solver

This program takes in a dictionary list of words and a 2D grid of letters and searches for which words in the dictionary can be found in the word grid on the following axes:
1. Vertical
2. Horizontal
3. Either diagonal
4. Any axis defined by the a rational number (ex. 3/5 so up/down 3 and left/right 5)

## Input Requirements
1. Words in the dictionary must have 1 or more letters.
2. Dictionary of words separated by newline.
3. 2D letter grid separated by a single space and newlines.

## Testing Instructions

1. run >> cd build
2. run >> cmake (if build configurations were changed)
3. run >> make (if any files were changed)
4. run >> ctest (runs tests)