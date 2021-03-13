open Css;

[@react.component]
let make = () =>
  <main
    className={
      merge([
        Mixins.flex_start_stretch,
        style([
          height(`vh(100.)),
          media("(max-width: 700px)", [flexDirection(`column)]),
        ]),
      ])
    }>
    <FormBuilder />
    <FormPreview />
  </main>;