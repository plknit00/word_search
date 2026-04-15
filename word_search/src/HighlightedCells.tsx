import React from "react";

export interface Coordinate {
  row: number;
  col: number;
}

function isCoordEq(c1: Coordinate, c2: Coordinate): boolean {
  return c1.row === c2.row && c1.col === c2.col;
}

function isOnSnowflakeDiagonal(c1: Coordinate, c2: Coordinate) {
  let dr = Math.abs(c2.row - c1.row);
  let dc = Math.abs(c2.col - c1.col);
  return dr === 0 || dc === 0 || dr === dc;
}

function isSameLine(coord: Coordinate, c1: Coordinate, c2: Coordinate) {
  let dr1 = coord.row - c1.row;
  let dc1 = coord.col - c1.col;
  let dr2 = c2.row - c1.row;
  let dc2 = c2.col - c1.col;
  return dr1 * dc2 === dc1 * dr2;
}

function isBetween(coord: Coordinate, c1: Coordinate, c2: Coordinate) {
  let minr = Math.min(c1.row, c2.row);
  let minc = Math.min(c1.col, c2.col);
  let maxr = Math.max(c1.row, c2.row);
  let maxc = Math.max(c1.col, c2.col);
  return (
    isSameLine(coord, c1, c2) &&
    coord.row >= minr &&
    coord.row <= maxr &&
    coord.col >= minc &&
    coord.col <= maxc
  );
}

export interface HighlightedCells {
  click: (coord: Coordinate) => void;
  isHighlighted: (coord: Coordinate) => boolean;
}

export function HighlightedCellsHook(): HighlightedCells {
  let [clickedCell1, updateClickedCell1] = React.useState<Coordinate>();
  let [clickedCell2, updateClickedCell2] = React.useState<Coordinate>();

  let click = (coord: Coordinate) => {
    if (clickedCell1 === undefined) {
      updateClickedCell1(coord);
    } else if (clickedCell2 === undefined) {
      if (isOnSnowflakeDiagonal(coord, clickedCell1)) {
        updateClickedCell2(coord);
      } else {
        updateClickedCell1(coord);
      }
    } else {
      updateClickedCell1(coord);
      updateClickedCell2(undefined);
    }
  };

  let isHighlighted = (coord: Coordinate) => {
    if (clickedCell1 === undefined) {
      return false;
    } else if (clickedCell2 === undefined) {
      return isCoordEq(coord, clickedCell1);
    } else {
      return isBetween(coord, clickedCell1, clickedCell2);
    }
  };

  return { click, isHighlighted };
}
