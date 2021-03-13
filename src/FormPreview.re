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

[@react.component]
let make = () => {
  let (state, dispatch) = React.useContext(FormContext.context);
  Js.log("ree");
  <div className=outputContainer>
    <form className=outputFormContainer>
      {
        state.form
        |> List.mapi((i, item) =>
             switch (item) {
             | Text(input) =>
               <div
                 className=inputContainer key={input.id}>
                 <InputNumber number={i + 1} />
                 <div className=question> {input.question |> str} </div>
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
               <div
                 className=inputContainer key={input.id}>
                 <InputNumber number={i + 1} />
                 <div className=question> {input.question |> str} </div>
                 <div className=scaleContainer>
                   {
                     let start = scaleStart == Zero ? 0 : 1;
                     let range: list(int) =
                       Utils.listOfRange(start, rangeValue);
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
    </form>
  </div>;
};