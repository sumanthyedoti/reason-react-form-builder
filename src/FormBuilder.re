open Css;
open Styles.FormBuilder;
open Mixins;
open FormTypes;

let makeInput = question: inputItem => {
  id: Utils.randomString(),
  question,
  answer: "",
};
let str = React.string;

module DeleteButton = {
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
  let (state, dispatch) = React.useContext(FormContext.context);
  React.useEffect1(
    () => {
      if (state.action == Add) {
        DomAPI.scrollToBottom(~qs="#form");
      };
      None;
    },
    [|state.form|],
  );
  <div className=formContainer>
    <form id="form" className=FormBuilder__Style.form>
      {
        state.form
        |> List.mapi((i, item) =>
             switch (item) {
             | Text(input) =>
               <div
                 className=inputContainer key={input.id}>
                 <InputNumber number={i + 1} />
                 <div className=FormBuilder__Style.input>
                   <Input.Text
                     placeholder="Type your question here"
                     onChange=(
                       event => {
                         let value = ReactEvent.Form.target(event)##value;
                         dispatch(AddText(input.id, value));
                         ();
                       }
                     )
                     value={input.question}
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
                 className=inputContainer key={input.id}>
                 <InputNumber number={i + 1} />
                 <div
                   className={
                     merge([
                       FormBuilder__Style.input,
                       Mixins.flex_col_start_start,
                     ])
                   }
                   key={input.id}>
                   <Input.Text
                     placeholder="Type your question here"
                     onChange=(
                       event => {
                         let value = ReactEvent.Form.target(event)##value;
                         dispatch(AddText(input.id, value));
                         ();
                       }
                     )
                     value={input.question}
                   />
                   <div
                     className={
                       merge([
                         flex_start_center,
                         style([paddingTop(`rem(1.))]),
                       ])
                     }>
                     <Input.Range
                       min="3"
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
          text="Text"
          icon={() => <Icons.Text />}
        />
        <Button
          icon={() => <Icons.Scale />}
          text="Scale"
          onClick={_ => dispatch(AddInput(Range(makeInput(""), 11, One)))}
        />
      </div>
    </div>
  </div>;
};