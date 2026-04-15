import React from "react";
import "./WordGrid.css";
import {
  Coordinate,
  HighlightedCells,
  HighlightedCellsHook,
} from "./HighlightedCells";

class WordGrid {
  grid: string[][];

  constructor(width: number, height: number) {
    this.grid = [];
    for (let h = 0; h < height; h++) {
      this.grid.push([]);
      for (let w = 0; w < width; w++) {
        let sum = w + h;
        this.grid[h].push(sum.toString());
      }
    }
  }
}

function GridCell(props: {
  cell: string;
  highlightedCells: HighlightedCells;
  coord: Coordinate;
}) {
  let className;
  if (props.highlightedCells.isHighlighted(props.coord)) {
    className = "WordGridCellHighlighted";
  } else {
    className = "WordGridCell";
  }

  return (
    <td
      className={className}
      onClick={() => {
        props.highlightedCells.click(props.coord);
      }}
    >
      {props.cell}
    </td>
  );
}

function GridRow(props: {
  row: string[];
  highlightedCells: HighlightedCells;
  rowIndex: number;
}) {
  let row_vals = [];
  for (let c = 0; c < props.row.length; c++) {
    row_vals.push(
      <GridCell
        cell={props.row[c]}
        highlightedCells={props.highlightedCells}
        coord={{ row: props.rowIndex, col: c }}
      />,
    );
  }
  return <tr>{row_vals}</tr>;
}

export function WordGridComponent() {
  let highlightedCells = HighlightedCellsHook();
  let grid = new WordGrid(5, 5);
  let table = [];
  for (let r = 0; r < grid.grid.length; r++) {
    table.push(
      <GridRow
        row={grid.grid[r]}
        highlightedCells={highlightedCells}
        rowIndex={r}
      />,
    );
  }
  return (
    <div className="WordSearchGrid">
      <table>{table}</table>
    </div>
  );
}
