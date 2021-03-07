type element;
[@bs.val] [@bs.scope "document"]
external getElementById: string => 'a = "getElementById";
[@bs.module "./Js/scrollDivToBottom"] [@bs.val]
external scrollDivToBottom: string => unit = "";

open Css;
open AppStyle;
open Mixins;
open FormTypes;

let makeInput = text: inputItem => {id: Js.Date.now(), text};
let str = React.string;

module DeleteButton = {
  open Mixins;
  [@react.component]
  let make = (~onClick) =>
    <button
      className={
        merge([
          no_default_style,
          style([
            display(`block),
            marginLeft(`auto),
            cursor(`pointer),
            opacity(0.4),
            transition(~duration=150, "opacity"),
            borderRadius(`em(0.2)),
            selector(
              "&:hover, &:focus",
              [opacity(1.), color(`hex(Palette.danger))],
            ),
          ]),
        ])
      }
      onClick>
      <Icons.Delete />
    </button>;
};
module InputNumber = {
  [@react.component]
  let make = (~number) =>
    <span className=align_self_start>
      {string_of_int(number) ++ "." |> React.string}
    </span>;
};

[@react.component]
let make = () => {
  let ({form}, dispatch) = React.useContext(FormContext.context);
  React.useEffect1(
    () => {
      scrollDivToBottom("form");
      None;
    },
    [|form|],
  );
  <div className=formContainer>
    <form id="form" className=AppStyle.form>
      {
        form
        |> List.mapi((i, item) =>
             switch (item) {
             | Text(input) =>
               <div
                 className=inputContainer key={Js.Float.toString(input.id)}>
                 <InputNumber number={i + 1} />
                 <div className=AppStyle.input>
                   <Input.Text
                     placeholder="Type your question here"
                     onChange=(
                       event => {
                         let value = ReactEvent.Form.target(event)##value;
                         dispatch(AddText(input.id, value));
                         ();
                       }
                     )
                     value={input.text}
                   />
                 </div>
                 <DeleteButton
                   onClick=(
                     _ => {
                       dispatch(DeleteInput(input.id));
                       ();
                     }
                   )
                 />
               </div>
             | Range(input, rangeValue, scaleStart) =>
               <div
                 className=inputContainer key={Js.Float.toString(input.id)}>
                 <InputNumber number={i + 1} />
                 <div
                   className={
                     merge([AppStyle.input, Mixins.flex_col_start_start])
                   }
                   key={Js.Float.toString(input.id)}>
                   <Input.Text
                     placeholder="Type your question here"
                     onChange=(
                       event => {
                         let value = ReactEvent.Form.target(event)##value;
                         dispatch(AddText(input.id, value));
                         ();
                       }
                     )
                     value={input.text}
                   />
                   <div
                     className={
                       merge([
                         flex_start_center,
                         style([paddingTop(`rem(1.))]),
                       ])
                     }>
                     <Input.Range
                       min="2"
                       max="11"
                       value={Js.Int.toString(rangeValue)}
                       onChange=(
                         event => {
                           let value: string =
                             ReactEvent.Form.target(event)##value;
                           dispatch(ChangeRange(input.id, value));
                           ();
                         }
                       )
                     />
                     <div
                       style={ReactDOM.Style.make(~paddingLeft="0.6em", ())}>
                       {React.string(string_of_int(rangeValue))}
                     </div>
                   </div>
                   <div className=flex_start_center>
                     <input
                       type_="checkbox"
                       checked={scaleStart == One}
                       value={scaleStart == One ? "1" : "0"}
                       onChange=(
                         event => {
                           let value: string =
                             ReactEvent.Form.target(event)##value;
                           dispatch(
                             ChangeScaleStart(
                               input.id,
                               value == "1" ? Zero : One,
                             ),
                           );
                           ();
                         }
                       )
                     />
                     <span
                       style={ReactDOM.Style.make(~paddingLeft="0.6em", ())}>
                       {" Scale starts at 1" |> str}
                     </span>
                   </div>
                 </div>
                 <DeleteButton
                   onClick=(_ => dispatch(DeleteInput(input.id)))
                 />
               </div>
             }
           )
        |> Array.of_list
        |> React.array
      }
    </form>
    <div className=buttonContainer>
      <p> {"Choose a question type:" |> str} </p>
      <div className=Mixins.flex_start_center>
        <Button
          onClick={_ => dispatch(AddInput(Text(makeInput(""))))}
          text="Add Text"
          icon={() => <Icons.Text />}
        />
        <Button
          icon={() => <Icons.Scale />}
          text="Add Scale"
          onClick={_ => dispatch(AddInput(Range(makeInput(""), 6, One)))}
        />
      </div>
    </div>
  </div>;
};