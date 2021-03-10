open Css;

[@react.component]
let make = () =>
  <main
    className={
      merge([Mixins.flex_start_stretch, style([height(`vh(100.))])])
    }>
    <FormBuilder />
    <FormPreview />
  </main>;