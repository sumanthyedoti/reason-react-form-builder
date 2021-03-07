open Css;
open AppStyle;
open FormTypes;

[@react.component]
let make = () => {
  let ({form}, dispatch) = React.useContext(FormContext.context);
  <main className=container>
    <Form />
  </main>;
};