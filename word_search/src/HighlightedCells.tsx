import React from "react";

export interface Coordinate {
  row: number;
  col: number;
}

function isCoordEq(c1: Coordinate, c2: Coordinate): boolean {
  return c1.row === c2.row && c1.col === c2.col;
}

export interface HighlightedCells {
  click: (coord: Coordinate) => void;
  isHighlighted: (coord: Coordinate) => boolean;
}

export function HighlightedCellsHook(): HighlightedCells {
  let [clickedCell1, updateClickedCell1] = React.useState<Coordinate>();
  // let [clickedCell2, updateClickedCell2] = React.useState();

  let click = (coord: Coordinate) => {
    updateClickedCell1(coord);
  };

  let isHighlighted = (coord: Coordinate) => {
    return clickedCell1 !== undefined && isCoordEq(clickedCell1, coord);
  };

  return { click, isHighlighted };
}
