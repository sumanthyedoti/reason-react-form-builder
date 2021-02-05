module Styles = {
  open Css;
  let textInput =
    style([
      padding2(~v=em(0.4), ~h=em(1.)),
      border(px(0), `none, transparent),
      borderBottom(px(1), `solid, hex("aaa")), //#aaa
      width(`percent(100.)),
    ]);
};

module Text = {
  [@react.component]
  let make = (~onChange, ~value) => {
    <input onChange className=Styles.textInput value />;
  };
};

module Range = {
  [@react.component]
  let make = (~onChange, ~value, ~min, ~max) => {
    <input type_="range" onChange value min max />;
  };
};
