import React from "react";
import { Coordinate } from "./Coordinate";

export interface WordGrid {
  rows: number;
  cols: number;
  getLetter: (coord: Coordinate) => string;
}

function wordGridConstructor(width: number, height: number) {
  let grid: string[][] = [];
  for (let h = 0; h < height; h++) {
    grid.push([]);
    for (let w = 0; w < width; w++) {
      let sum = w + h;
      grid[h].push(sum.toString());
    }
  }
  return grid;
}

export function WordGridHook(): WordGrid {
  let rows = 5;
  let cols = 5;
  // later todo: get from my cpp code
  let [wordGrid] = React.useState(() => wordGridConstructor(rows, cols));

  let getLetter = (coord: Coordinate): string => {
    return wordGrid[coord.row][coord.col];
  };

  return { rows, cols, getLetter };
}
