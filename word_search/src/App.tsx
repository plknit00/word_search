import React from "react";
import logo from "./logo.svg";
import "./App.css";
import { WordGridComponent } from "./WordGridComponent";

const ws = new WebSocket("ws://127.0.0.1:1234");

ws.onopen = () => {
  console.log("connected");
  ws.send("hi remy");
};

ws.onmessage = (event) => {
  console.log(event.data);
};

function Header() {
  return (
    <div className="Header">
      <h1>Word Search</h1>
    </div>
  );
}

function Body() {
  let [state, updateState] = React.useState("body");
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
