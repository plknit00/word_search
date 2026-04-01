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

function GridCell(props: { cell: string }) {
  return <td>{props.cell}</td>;
}

function GridRow(props: { row: string[] }) {
  let row_vals = [];
  for (let c = 0; c < props.row.length; c++) {
    row_vals.push(<GridCell cell={props.row[c]} />);
  }
  return <tr>{row_vals}</tr>;
}

export function WordGridComponent() {
  let grid = new WordGrid(5, 5);
  let table = [];
  for (let r = 0; r < grid.grid.length; r++) {
    table.push(<GridRow row={grid.grid[r]} />);
  }
  return <table>{table}</table>;
}
