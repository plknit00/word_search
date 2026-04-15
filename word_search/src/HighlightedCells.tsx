export interface Coordinate {
  row: number;
  col: number;
}

export class HighlightedCells {
  // click on cell function
  click(coord: Coordinate) {
    //todo
  }
  // is highlighted
  isHighlighted(coord: Coordinate): boolean {
    //todo
    return false;
  }
  // private: update highlighted cells in grid
  // private: check if clicked cells are in a line or not
}
