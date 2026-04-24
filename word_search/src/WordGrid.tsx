import React from "react";
import { Coordinate } from "./Coordinate";
import { DictionaryHook } from "./Dictionary";

export interface WordGrid {
  rows: number;
  cols: number;
  getLetter: (coord: Coordinate) => string;
  confirmWordIfFound: (word: string) => boolean;
  confirmTiles: (coordList: Coordinate[]) => void;
  isConfirmed: (coord: Coordinate) => boolean;
}

interface Cell {
  letter: string;
  containedInFoundWord: boolean;
}

function wordGridConstructor(width: number, height: number) {
  let grid: Cell[][] = [];
  for (let h = 0; h < height; h++) {
    grid.push([]);
    for (let w = 0; w < width; w++) {
      let sum = w + h;
      grid[h].push({ letter: sum.toString(), containedInFoundWord: false });
    }
  }
  return grid;
}

export function WordGridHook(): WordGrid {
  let rows = 5;
  let cols = 5;
  // later todo: get from my cpp code
  let [wordGrid] = React.useState(() => wordGridConstructor(rows, cols));
  let dict = DictionaryHook();

  function getLetter(coord: Coordinate): string {
    return wordGrid[coord.row][coord.col].letter;
  }

  function confirmWordIfFound(word: string): boolean {
    return dict.confirmWordIfFound(word);
  }

  function confirmTiles(coordList: Coordinate[]) {
    for (let coord of coordList) {
      wordGrid[coord.row][coord.col].containedInFoundWord = true;
    }
  }

  function isConfirmed(coord: Coordinate): boolean {
    return wordGrid[coord.row][coord.col].containedInFoundWord;
  }

  return {
    rows,
    cols,
    getLetter,
    confirmWordIfFound,
    confirmTiles,
    isConfirmed,
  };
}
