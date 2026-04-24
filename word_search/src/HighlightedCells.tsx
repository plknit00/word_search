import React from "react";
import {
  addDelta,
  Coordinate,
  getCoordDifference,
  isBetween,
  isCoordEq,
  isOnSnowflakeDiagonal,
} from "./Coordinate";

export enum ClickStatus {
  WordSelected,
  None,
}

export interface HighlightedCells {
  click: (coord: Coordinate) => ClickStatus;
  getHighlightedCells: () => Coordinate[];
  isHighlighted: (coord: Coordinate) => boolean;
  clear: () => void;
}

export function HighlightedCellsHook(): HighlightedCells {
  let [clickedCell1, updateClickedCell1] = React.useState<Coordinate>();
  let [clickedCell2, updateClickedCell2] = React.useState<Coordinate>();

  function click(coord: Coordinate): ClickStatus {
    if (clickedCell1 === undefined) {
      updateClickedCell1(coord);
    } else if (clickedCell2 === undefined) {
      if (isOnSnowflakeDiagonal(coord, clickedCell1)) {
        updateClickedCell2(coord);
      } else {
        updateClickedCell1(coord);
      }
    } else {
      if (isCoordEq(coord, clickedCell2)) {
        return ClickStatus.WordSelected;
      }
      updateClickedCell1(coord);
      updateClickedCell2(undefined);
    }
    return ClickStatus.None;
  }

  function getHighlightedCells() {
    if (clickedCell2 === undefined || clickedCell1 === undefined) {
      return [];
    }
    let cells: Coordinate[] = [];
    let currCoord = clickedCell1;
    let dcoord = getCoordDifference(clickedCell1, clickedCell2);
    while (!isCoordEq(currCoord, clickedCell2)) {
      cells.push(currCoord);
      currCoord = addDelta(currCoord, dcoord);
    }
    cells.push(currCoord);
    currCoord = addDelta(currCoord, dcoord);
    return cells;
  }

  function isHighlighted(coord: Coordinate) {
    if (clickedCell1 === undefined) {
      return false;
    } else if (clickedCell2 === undefined) {
      return isCoordEq(coord, clickedCell1);
    } else {
      return isBetween(coord, clickedCell1, clickedCell2);
    }
  }

  function clear() {
    updateClickedCell1(undefined);
    updateClickedCell2(undefined);
  }

  return { click, getHighlightedCells, isHighlighted, clear };
}
