import React from "react";
import "./WordGrid.css";
import { Coordinate, HighlightedCells } from "./HighlightedCells";

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
  isHighlighted: boolean;
  updateHighlightedCells: (coords: Coordinate) => void;
  coord: Coordinate;
}) {
  let className;
  if (props.isHighlighted) {
    className = "WordGridCellHighlighted";
  } else {
    className = "WordGridCell";
  }

  return (
    <td
      className={className}
      onClick={() => {
        props.updateHighlightedCells(props.coord);
      }}
    >
      {props.cell}
    </td>
  );
}

function GridRow(props: {
  row: string[];
  highlightedCells?: Coordinate;
  rowIndex: number;
  updateHighlightedCells: (coords: Coordinate) => void;
}) {
  let row_vals = [];
  let isRow = props.rowIndex === props.highlightedCells?.row;
  for (let c = 0; c < props.row.length; c++) {
    let isHighlighted = isRow && c === props.highlightedCells?.col;
    row_vals.push(
      <GridCell
        cell={props.row[c]}
        isHighlighted={isHighlighted}
        updateHighlightedCells={props.updateHighlightedCells}
        coord={{ row: props.rowIndex, col: c }}
      />,
    );
  }
  return <tr>{row_vals}</tr>;
}

export function WordGridComponent() {
  let [highlightedCells, updateHighlightedCells] = React.useState<Coordinate>();
  let grid = new WordGrid(5, 5);
  let table = [];
  for (let r = 0; r < grid.grid.length; r++) {
    table.push(
      <GridRow
        row={grid.grid[r]}
        highlightedCells={highlightedCells}
        rowIndex={r}
        updateHighlightedCells={updateHighlightedCells}
      />,
    );
  }
  return (
    <div className="WordSearchGrid">
      <table>{table}</table>
    </div>
  );
}
