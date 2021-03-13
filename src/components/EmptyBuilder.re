[%bs.raw {|require("../styles/empty-builder.css")|}];

open Css;
[@react.component]
let make = () =>
  <div className="container">
    <div className="logo" />
    <span className="title"> {"Form Builder" |> React.string} </span>
  </div>;