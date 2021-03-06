open Css;

let cursor_pointer = style([cursor(`pointer)]);
let flex_start_start =
  style([
    display(`flex),
    justifyContent(`flexStart),
    alignItems(`flexStart),
  ]);
let flex_start_center =
  style([display(`flex), justifyContent(`flexStart), alignItems(`center)]);
let flex_between_center =
  style([
    display(`flex),
    justifyContent(`spaceBetween),
    alignItems(`center),
  ]);
let flex_col_start_start =
  style([
    display(`flex),
    flexDirection(`column),
    justifyContent(`flexStart),
    alignItems(`flexStart),
  ]);
let flex_col_start_center =
  style([
    display(`flex),
    flexDirection(`column),
    justifyContent(`flexStart),
    alignItems(`center),
  ]);
let flex_col_between_center =
  style([
    display(`flex),
    flexDirection(`column),
    justifyContent(`spaceBetween),
    alignItems(`center),
  ]);