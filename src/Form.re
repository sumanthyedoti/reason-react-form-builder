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
  [@react.component]
  let make = (~onClick) =>
    <span
      className={
        merge([
          cursor_pointer,
          style([display(`block), marginLeft(`auto)]),
        ])
      }
      onClick>
      <DeleteIcon />
    </span>;
};

[@react.component]
let make = () => {
  let ({form}, dispatch) = React.useContext(FormContext.context);
  let scrollFormToBottom = () => {
    // let elem = getElementById("form");
    // elem##scrollTop = elem##scrollHeight;
    scrollDivToBottom("form");
  };
  <div className=formContainer>
    <form id="form" className=AppStyle.form>
      {
        form
        |> List.mapi((i, item) =>
             switch (item) {
             | Text(input) =>
               <div
                 className=inputContainer key={Js.Float.toString(input.id)}>
                 <span className=align_self_start>
                   {string_of_int(i + 1) |> React.string}
                 </span>
                 <div className=AppStyle.input>
                   <Input.Text
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
                 <span className=align_self_start>
                   {string_of_int(i + 1) |> React.string}
                 </span>
                 <div
                   className={
                     merge([AppStyle.input, Mixins.flex_col_start_start])
                   }
                   key={Js.Float.toString(input.id)}>
                   <Input.Text
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
                     <div> {React.string(string_of_int(rangeValue))} </div>
                   </div>
                   <div>
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
                     <span> {" Scale starts at 1" |> str} </span>
                   </div>
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
             }
           )
        |> Array.of_list
        |> React.array
      }
    </form>
    <div className="">
      <button
        onClick={
          _ => {
            scrollFormToBottom();
            dispatch(AddInput(Text(makeInput("Hello"))));
          }
        }>
        {"Add Text" |> str}
      </button>
      <button
        onClick={
          _ => {
            scrollFormToBottom();
            dispatch(AddInput(Range(makeInput("Scale"), 6, One)));
          }
        }>
        {"Add Scale" |> str}
      </button>
    </div>
  </div>;
};