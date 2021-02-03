type scale = int;
type rangeValue = int;
type inputItem = {
  id: float,
  text: string,
};
type input =
  | Text(inputItem)
  | Range(inputItem, rangeValue);
type state = {form: list(input)};

type action =
  | AddInput(input)
  | AddText(float, string)
  | ChangeRange(float, string);

let str = React.string;

let makeInput = text: inputItem => {id: Js.Date.now(), text};

let initialState = {form: []};

let reducer = (state, action) =>
  switch (action) {
  | AddInput(input) => {form: state.form @ [input]}
  | AddText(id, text) => {
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Text(inputItem) =>
               inputItem.id === id ?
                 Text({...inputItem, text}) : Text(inputItem)
             | Range(inputItem, rangeValue) =>
               inputItem.id === id ?
                 Range({...inputItem, text}, rangeValue) :
                 Range(inputItem, rangeValue)
             | _ => item
             }
           ),
    }
  | ChangeRange(id, value) => {
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Range(inputItem, rangeValue) =>
               inputItem.id === id ?
                 Range(inputItem, int_of_string(value)) :
                 Range(inputItem, rangeValue)
             | _ => item
             }
           ),
    }
  };

[@react.component]
let make = () => {
  let ({form}, dispatch) = React.useReducer(reducer, initialState);
  <main>
    {React.string("Simple counter with reducer")}
    <form>
      {
        form
        |> List.map(item =>
             switch (item) {
             | Text(input) =>
               <div key={string_of_float(input.id)}>
                 <input
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
             | Range(input, rangeValue) =>
               <div key={Js.Float.toString(input.id)}>
                 <input
                   onChange=(
                     event => {
                       let value = ReactEvent.Form.target(event)##value;
                       dispatch(AddText(input.id, value));
                       ();
                     }
                   )
                   value={input.text}
                 />
                 <input
                   type_="range"
                   min="2"
                   max="11"
                   value={Js.Int.toString(rangeValue)}
                   onChange=(
                     event => {
                       let value = ReactEvent.Form.target(event)##value;
                       dispatch(ChangeRange(input.id, value));
                       ();
                     }
                   )
                 />
                 <span> {React.string(string_of_int(rangeValue))} </span>
               </div>
             | _ => React.null
             }
           )
        |> Array.of_list
        |> React.array
      }
    </form>
    <div>
      <button onClick={_ => dispatch(AddInput(Text(makeInput("Hello"))))}>
        {"Add Text" |> str}
      </button>
      <button
        onClick={_ => dispatch(AddInput(Range(makeInput("Scale"), 6)))}>
        {"Add Scale" |> str}
      </button>
    </div>
  </main>;
};