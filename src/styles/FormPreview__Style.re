open Css;
open Mixins;

let outputContainer =
  style([
    padding2(~v=`rem(6.), ~h=`rem(4.)),
    width(`percent(60.)),
    color(`hex("fff")),
    backgroundColor(`hex(Palette.bgPrimary)),
  ]);
let outputFormContainer =
  style([
    paddingRight(`rem(1.5)),
    maxHeight(`percent(100.)),
    overflow(`scroll),
  ]);

let inputContainer =
  merge([
    flex_col_start_start,
    style([
      flexGrow(0.),
      marginTop(`em(3.)),
      selector("&:first-child", [marginTop(`em(0.))]),
    ]),
  ]);

let question = style([fontSize(`rem(2.6)), width(`percent(100.))]);
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
        [
          textDecoration(`none),
          backgroundColor(`hex(Palette.fgPrimary_accent)),
        ],
      ),
      selector(
        "&.active",
        [
          backgroundColor(`hex(Palette.fgPrimary_hover)),
          color(whitesmoke),
        ],
      ),
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