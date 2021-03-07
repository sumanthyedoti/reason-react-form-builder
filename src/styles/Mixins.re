open Css;

let cursor_pointer = style([cursor(`pointer)]);
let no_default_style = style([
  border(`px(0), `none, transparent),
  // outline(`px(0), `none, transparent),
  backgroundColor(transparent),
  margin(`px(0)),
  padding(`px(0)),
])

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
let flex_center_center =
  style([display(`flex), justifyContent(`center), alignItems(`center)]);
let flex_around_center =
  style([
    display(`flex),
    justifyContent(`spaceAround),
    alignItems(`center),
  ]);
let flex_evenly_center =
  style([
    display(`flex),
    justifyContent(`spaceEvenly),
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
let align_self_start = style([alignSelf(`selfStart)]);
let align_self_end = style([alignSelf(`selfEnd)]);