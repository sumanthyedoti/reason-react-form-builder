open Css;
open AppStyle;
open Mixins;
open FormTypes;

let makeInput = text: inputItem => {id: Js.Date.now(), text};
let str = React.string;

[@react.component]
let make = () => {
  let ({form}, dispatch) = React.useContext(FormContext.context);
  <main className=container>
    <Form />
  </main>;
};