open Css;

let form_buttons_c_height = 50;

let container = Css.merge([Mixins.flex_start_start]);
let formContainer =
  Css.merge([
    Mixins.flex_col_between_center,
    style([
      position(`relative),
      height(`vh(100.)),
      width(`vw(40.)),
      flexGrow(0.),
    ]),
  ]);

let form =
  style([
    width(`percent(100.)),
    height(`percent(100.)),
    overflow(`scroll),
    marginBottom(`auto),
    border(px(1), `solid, red)
  ]);

let inputEntry =
  keyframes([
    (0, [opacity(0.0), transform(scale3d(0.5, 0.5, 0.5))]),
    (100, [opacity(1.0), transform(scale3d(1., 1., 1.))]),
  ]);

let input =
  style([
    animationName(inputEntry),
    animationDuration(300),
    transformOrigin(`percent(10.0), px(0)),
    paddingTop(`em(0.5)),
    paddingBottom(`em(0.5)),
    animationTimingFunction(cubicBezier(0.16, 1., 0.3, 1.)),
  ]);
let inputItem = Css.merge([input, Mixins.flex_col_start_start]);
let formButtonsContainer =
  style([
    position(`absolute),
    bottom(`zero),
    // height(`px(form_buttons_c_height)),
  ]);