import React from "react";
import "./WordGrid.css";

interface Coordinate {
  row: number;
  col: number;
}

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
  updateHighlightedCell: (coords: Coordinate) => void;
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
        props.updateHighlightedCell(props.coord);
      }}
    >
      {props.cell}
    </td>
  );
}

function GridRow(props: {
  row: string[];
  highlightedCell?: Coordinate;
  rowIndex: number;
  updateHighlightedCell: (coords: Coordinate) => void;
}) {
  let row_vals = [];
  let isRow = props.rowIndex == props.highlightedCell?.row;
  for (let c = 0; c < props.row.length; c++) {
    let isHighlighted = isRow && c == props.highlightedCell?.col;
    row_vals.push(
      <GridCell
        cell={props.row[c]}
        isHighlighted={isHighlighted}
        updateHighlightedCell={props.updateHighlightedCell}
        coord={{ row: props.rowIndex, col: c }}
      />,
    );
  }
  return <tr>{row_vals}</tr>;
}

export function WordGridComponent() {
  let [highlightedCell, updateHighlightedCell] = React.useState<Coordinate>();
  let grid = new WordGrid(5, 5);
  let table = [];
  for (let r = 0; r < grid.grid.length; r++) {
    table.push(
      <GridRow
        row={grid.grid[r]}
        highlightedCell={highlightedCell}
        rowIndex={r}
        updateHighlightedCell={updateHighlightedCell}
      />,
    );
  }
  return <table>{table}</table>;
}
