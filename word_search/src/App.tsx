import React from "react";
import logo from "./logo.svg";
import "./App.css";
import { WordGridComponent } from "./WordGridComponent";

function Header() {
  return (
    <div className="Header">
      <h1>Word Search</h1>
    </div>
  );
}

function Body() {
  let [state, updateState] = React.useState("bodu");
  return (
    <div
      className="Body"
      onClick={() => {
        updateState("BODY");
      }}
    >
      <h1>{state}</h1>
    </div>
  );
}

function App() {
  return (
    <div className="App">
      <Header />
      <Body />
      <WordGridComponent />
    </div>
  );
}

export default App;
