open Css;
open Mixins;

let form_buttons_c_height = 50;

let formContainer =
  Css.merge([
    Mixins.flex_col_between_center,
    style([
      position(`relative),
      height(`vh(100.)),
      width(`vw(40.)),
      flexGrow(0.),
      background(`hex(Palette.bgSecondary)),
    ]),
  ]);

let form =
  style([
    width(`percent(100.)),
    height(`percent(100.)),
    overflow(`auto),
    padding2(~v=`rem(0.8), ~h=rem(1.)),
  ]);

let inputContainer =
  merge([
    flex_start_center,
    style([
      padding2(~v=`rem(3.), ~h=`rem(1.)),
      borderBottom(`px(2), `dotted, lightgray),
      selector("&:last-child", [borderBottom(`px(0), `none, transparent)]),
    ]),
  ]);

let inputEntry =
  keyframes([
    (0, [opacity(0.0), transform(scale3d(0.5, 0.5, 0.5))]),
    (100, [opacity(1.0), transform(scale3d(1., 1., 1.))]),
  ]);

let input =
  style([
    animationName(inputEntry),
    animationDuration(500),
    animationTimingFunction(cubicBezier(0.16, 1., 0.3, 1.)),
    transformOrigin(`percent(10.0), px(0)),
    padding2(~v=`rem(1.), ~h=`rem(1.)),
    width(`percent(100.)),
  ]);

let formButtonsContainer = style([position(`absolute), bottom(`zero)]);

let buttonContainer =
  style([
    width(`percent(100.)),
    padding2(~v=em(1.2), ~h=em(2.)),
    borderTop(`px(2), `solid, lightgray),
    margin2(~v=`rem(1.), ~h=`rem(1.)),
  ]);