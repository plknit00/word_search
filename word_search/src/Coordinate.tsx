export interface Coordinate {
  row: number;
  col: number;
}

export interface Delta {
  dr: number;
  dc: number;
}

export function isCoordEq(c1: Coordinate, c2: Coordinate): boolean {
  return c1.row === c2.row && c1.col === c2.col;
}

export function isOnSnowflakeDiagonal(c1: Coordinate, c2: Coordinate) {
  let dr = Math.abs(c2.row - c1.row);
  let dc = Math.abs(c2.col - c1.col);
  return dr === 0 || dc === 0 || dr === dc;
}

export function isSameLine(coord: Coordinate, c1: Coordinate, c2: Coordinate) {
  let dr1 = coord.row - c1.row;
  let dc1 = coord.col - c1.col;
  let dr2 = c2.row - c1.row;
  let dc2 = c2.col - c1.col;
  return dr1 * dc2 === dc1 * dr2;
}

export function isBetween(coord: Coordinate, c1: Coordinate, c2: Coordinate) {
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

function normalize(n1: number, n2: number): number {
  if (n2 - n1 > 0) {
    return 1;
  } else if (n2 - n1 < 0) {
    return -1;
  } else return 0;
}

export function getCoordDifference(c1: Coordinate, c2: Coordinate): Delta {
  return {
    dr: normalize(c1.row, c2.row),
    dc: normalize(c1.col, c2.col),
  };
}

export function addDelta(coord: Coordinate, delta: Delta): Coordinate {
  return { row: coord.row + delta.dr, col: coord.col + delta.dc };
}
