[@bs.module "./Js/downloadPage"]
external downloadPage: unit => unit = "default";

open Css;
open Webapi.Dom;
open FormTypes;
open Mixins;
open Styles.FormPreview;

let str = React.string;
module InputNumber = {
  [@react.component]
  let make = (~number) =>
    <span style={ReactDOM.Style.make(~fontSize="2.6rem", ~color="#ccc", ())}>
      {string_of_int(number) ++ "." |> React.string}
    </span>;
};

module Question = {
  [@react.component]
  let make = (~text) =>
    <div className={question(~placeholder=text === "")}>
      {(text === "" ? "Question goes here..." : text) |> str}
    </div>;
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useContext(FormContext.context);
  Js.log("ree");
  <div className=outputContainer>
    <form className=outputFormContainer>
      {List.length(state.form) == 0 ? <PreviewIllustration /> : React.null}
      <div>
      {
        state.form
        |> List.mapi((i, item) =>
             switch (item) {
             | Text(input) =>
               <div className=inputContainer key={input.id}>
                 <InputNumber number={i + 1} />
                 <Question text={input.question} />
                 <input
                   value={input.answer}
                   className=textInput
                   placeholder="Type your answer"
                   onChange=(
                     event => {
                       let value: string =
                         ReactEvent.Form.target(event)##value;
                       dispatch(Answer(input.id, value));
                       ();
                     }
                   )
                 />
               </div>
             | Range(input, rangeValue, scaleStart) =>
               <div className=inputContainer key={input.id}>
                 <InputNumber number={i + 1} />
                 <Question text={input.question} />
                 <div className=scaleContainer>
                   {
                     let start = scaleStart == Zero ? 0 : 1;
                     let range: list(int) =
                       Utils.listOfRange(
                         start,
                         start === 0 ? rangeValue - 1 : rangeValue,
                       );
                     range
                     |> List.map(it =>
                          <a
                            href="#"
                            className={
                              merge([
                                input.answer == string_of_int(it) ?
                                  "active " : "",
                                scaleItem,
                              ])
                            }
                            onClick=(
                              e => {
                                let value =
                                  ReactEvent.Mouse.target(e)##innerText;
                                dispatch(Answer(input.id, value));
                              }
                            )>
                            {string_of_int(it) |> str}
                          </a>
                        )
                     |> Array.of_list
                     |> React.array;
                   }
                 </div>
               </div>
             }
           )
        |> Array.of_list
        |> React.array
      }
      {List.length(state.form) != 0 ? (
        <div
          className={
            merge([
              Mixins.flex_center_center,
              style([marginTop(`em(4.))]),
            ])
          }>
          <Button
            text="Submit"
            onClick=(
              e => {
                /* downloadPage(); */
                e->ReactEvent.Mouse.preventDefault;
              }
            )
          />
        </div>
      ) : React.null}
      </div>
    </form>
  </div>;
};