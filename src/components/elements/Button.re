module Styles = {
  open Css;
  let button =
    merge([
      Mixins.flex_center_center,
      style([
        padding2(~v=em(0.2), ~h=em(1.)),
        fontSize(`rem(1.5)),
        backgroundColor(`hex(Palette.fgPrimary)),
        border(`px(0), `none, transparent),
        borderRadius(`em(0.15)),
        color(`hex(Palette.textWhite)),
        transition(~duration=300, "background-color"),
        marginRight(`em(1.)),
        selector(
          "& .icon",
          [paddingRight(`em(1.)), border(px(1), `solid, red)],
        ),
        selector("&:last-child", [marginRight(`em(0.))]),
        selector(
          "&:hover, &:focus",
          [backgroundColor(`hex(Palette.buttonHover))],
        ),
      ]),
    ]);
};

[@react.component]
let make = (~onClick, ~icon=?, ~text: string) =>
  <button onClick className=Styles.button>
    {
      switch (icon) {
      | Some(icon) =>
        <span style={ReactDOM.Style.make(~paddingRight="0.6em", ~maxHeight="3rem", ())}>
          {icon()}
        </span>
      | None => React.null
      }
    }
    {text |> React.string}
  </button>;