import React from "react";
import "./WordGridComponent.css";
import {
  ClickStatus,
  HighlightedCells,
  HighlightedCellsHook,
} from "./HighlightedCells";
import { WordGrid, WordGridHook } from "./WordGrid";
import { Coordinate } from "./Coordinate";

function GridCell(props: {
  grid: WordGrid;
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
        let status = props.highlightedCells.click(props.coord);
        if (status === ClickStatus.WordSelected) {
          let cells = props.highlightedCells.getHighlightedCells();
          let word = "";
          for (let cell of cells) {
            let letter = props.grid.getLetter(cell);
            word = word + letter;
          }
          console.log(word);
        }
      }}
    >
      {props.grid.getLetter(props.coord)}
    </td>
  );
}

function GridRow(props: {
  grid: WordGrid;
  highlightedCells: HighlightedCells;
  rowIndex: number;
}) {
  let row_vals = [];
  for (let c = 0; c < props.grid.cols; c++) {
    row_vals.push(
      <GridCell
        grid={props.grid}
        highlightedCells={props.highlightedCells}
        coord={{ row: props.rowIndex, col: c }}
      />,
    );
  }
  return <tr>{row_vals}</tr>;
}

export function WordGridComponent() {
  let highlightedCells = HighlightedCellsHook();
  let grid = WordGridHook();
  let table = [];
  for (let r = 0; r < grid.rows; r++) {
    table.push(
      <GridRow grid={grid} highlightedCells={highlightedCells} rowIndex={r} />,
    );
  }
  return (
    <div className="WordSearchGrid">
      <table>{table}</table>
    </div>
  );
}
