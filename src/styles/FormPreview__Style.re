open Css;
open Mixins;

let outputContainer =
  style([
    padding2(~v=`rem(4.), ~h=`rem(5.)),
    width(`percent(60.)),
    height(`vh(100.)),
    color(`hex("fff")),
    backgroundColor(`hex(Palette.bgPrimary)),
    media("(max-width: 700px)", [width(`percent(100.))]),
  ]);
let outputFormContainer =
  style([
    paddingRight(`rem(1.5)),
    maxHeight(`percent(100.)),
    overflow(`scroll),
    height(`percent(100.)),
  ]);

let inputContainer =
  merge([
    flex_col_start_start,
    style([
      flexGrow(0.),
      marginTop(`em(2.)),
      selector("&:first-child", [marginTop(`em(0.))]),
    ]),
  ]);

let question = (~placeholder=false) =>
  style([
    fontSize(`rem(2.6)),
    width(`percent(100.)),
    marginTop(`em(0.5)),
    color(placeholder ? `hex("888") : `hex(Palette.textWhite)),
  ]);
let scaleContainer =
  merge([
    flex_start_start,
    style([
      marginTop(`em(1.)),
      maxWidth(`percent(100.)),
      flexWrap(`wrap),
      overflowY(`scroll),
    ]),
  ]);
let scaleItem =
  merge([
    flex_center_center,
    style([
      width(`em(2.)),
      height(`em(2.5)),
      backgroundColor(`hex(Palette.bgSecondary)),
      flexShrink(0.),
      color(`hex(Palette.textBlack)),
      borderRight(px(1), `solid, lightgray),
      marginTop(`px(1)),
      selector("&:last-child", [borderRight(px(1), `none, lightgray)]),
      transition(~duration=200, "background-color"),
      selector(
        "&:hover, &:focus, &:active",
        [textDecoration(`none), backgroundColor(`hex("eee"))],
      ),
      selector("&.active", [backgroundColor(`hex(Palette.fgTertiary))]),
    ]),
  ]);

let textInput =
  style([
    backgroundColor(`hex(Palette.bgPrimary_accent)),
    fontWeight(`medium),
    fontSize(`rem(1.8)),
    width(`percent(100.)),
    border(px(1), `none, red),
    padding2(~v=em(0.6), ~h=em(1.)),
    borderRadius(`em(0.1)),
    marginTop(em(1.)),
    transition(~duration=200, "background-color, color"),
    selector(
      "&:active, &:focus",
      [
        backgroundColor(`hex(Palette.bgSecondary)),
        outline(px(1), `none, red),
        color(`hex(Palette.textBlack)),
      ],
    ),
  ]);