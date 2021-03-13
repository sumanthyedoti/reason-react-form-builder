type buttonType =
  | Primary
  | Secondary;

module Styles = {
  open Css;
  let button = type_ =>
    merge([
      Mixins.flex_center_center,
      style([
        padding2(
          ~v=em(type_ === Primary ? 0.5 : 0.2),
          ~h=em(type_ === Primary ? 1.8 : 1.),
        ),
        fontSize(type_ === Primary ? `rem(2.) : `rem(1.5)),
        backgroundColor(
          switch (type_) {
          | Primary => `hex(Palette.fgPrimary)
          | Secondary => `hex(Palette.fgSecondary)
          },
        ),
        border(`px(0), `none, transparent),
        borderRadius(type_ === Primary ? `em(3.) : `em(0.2)),
        fontWeight(type_ === Primary ? `semiBold : `normal),
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
          [
            backgroundColor(
              switch (type_) {
              | Primary => `hex(Palette.fgPrimary_hover)
              | Secondary => `hex(Palette.fgSecondary_hover)
              },
            ),
          ],
        ),
      ]),
    ]);
};

[@react.component]
let make = (~onClick, ~icon=?, ~text: string, ~type_=Primary) =>
  <button onClick className={Styles.button(type_)}>
    {
      switch (icon) {
      | Some(icon) =>
        <span
          style={
            ReactDOM.Style.make(~paddingRight="1em", ~maxHeight="3rem", ())
          }>
          {icon()}
        </span>
      | None => React.null
      }
    }
    {text |> React.string}
  </button>;