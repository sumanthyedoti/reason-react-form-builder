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
    {React.string("Simple counter with reducer")}
    <form className=AppStyle.form>
      {
        form
        |> List.map(item =>
             switch (item) {
             | Text(input) =>
               <div
                 className={merge([flex_between_center, AppStyle.input])}
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
                 <span
                   className={merge([cursor_pointer])}
                   onClick=(
                     _ => {
                       dispatch(DeleteInput(input.id));
                       ();
                     }
                   )>
                   <DeleteIcon />
                 </span>
               </div>
             | Range(input, rangeValue, scaleStart) =>
               <div
                 className=flex_between_center
                 key={Js.Float.toString(input.id)}>
                 <div className=inputItem key={Js.Float.toString(input.id)}>
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
                   <div className=flex_start_center>
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
                 <span
                   className={merge([cursor_pointer])}
                   onClick=(
                     _ => {
                       dispatch(DeleteInput(input.id));
                       ();
                     }
                   )>
                   <DeleteIcon />
                 </span>
               </div>
             }
           )
        |> Array.of_list
        |> React.array
      }
      <div>
        <button onClick={_ => dispatch(AddInput(Text(makeInput("Hello"))))}>
          {"Add Text" |> str}
        </button>
        <button
          onClick={
            _ => dispatch(AddInput(Range(makeInput("Scale"), 6, One)))
          }>
          {"Add Scale" |> str}
        </button>
      </div>
    </form>
  </main>;
};