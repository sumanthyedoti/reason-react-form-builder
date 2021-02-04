open Css;

let container = style([]);
let inputEntry =
    Css.(
      keyframes([
        (0, [opacity(0.0), transform(scale3d(0.5, 0.5, 0.5))]),
        (100, [opacity(1.0), transform(scale3d(1., 1., 1.))]),
      ])
    );

  let input =
    style([
      animationName(inputEntry),
      animationDuration(300),
      transformOrigin(`percent(10.0), px(0)),
      animationTimingFunction(cubicBezier(0.16, 1., 0.3, 1.)),
      margin(em(1.)),
    ]);
  let inputItem = Css.merge([input, Mixins.flex_col_start_start]);

