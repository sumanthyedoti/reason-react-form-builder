open Css;
open AppStyle;
open Mixins;
type rangeValue = int;
type scaleStart =
  | Zero
  | One;
type inputItem = {
  id: float,
  text: string,
};
type input =
  | Text(inputItem)
  | Range(inputItem, rangeValue, scaleStart);
type state = {form: list(input)};

type action =
  | AddInput(input)
  | AddText(float, string)
  | ChangeRange(float, string)
  | ChangeScaleStart(float, scaleStart)
  | DeleteInput(float);

let str = React.string;

let makeInput = (text): inputItem => {id: Js.Date.now(), text};

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
               inputItem.id == id
                 ? Text({...inputItem, text}) : Text(inputItem)
             | Range(inputItem, rangeValue, scaleStart) =>
               inputItem.id == id
                 ? Range({...inputItem, text}, rangeValue, scaleStart)
                 : Range(inputItem, rangeValue, scaleStart)
             }
           ),
    }
  | ChangeRange(id, value) => {
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Range(inputItem, rangeValue, scaleStart) =>
               inputItem.id == id
                 ? Range(inputItem, int_of_string(value), scaleStart)
                 : Range(inputItem, rangeValue, scaleStart)
             | _ => item
             }
           ),
    }
  | ChangeScaleStart(id, scaleStartPosition) => {
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Range(inputItem, rangeValue, scaleStart) =>
               inputItem.id == id
                 ? Range(inputItem, rangeValue, scaleStartPosition)
                 : Range(inputItem, rangeValue, scaleStart)
             | _ => item
             }
           ),
    }
  | DeleteInput(id) => {
      form:
        state.form
        |> List.filter(item =>
             switch (item) {
             | Text(inputItem) => inputItem.id != id
             | Range(inputItem, _, _) => inputItem.id != id
             }
           ),
    }
  };

[@react.component]
let make = () => {
  let ({form}, dispatch) = React.useReducer(reducer, initialState);
  <main className=container>
    {React.string("Simple counter with reducer")}
    <form className=AppStyle.form>
      {form
       |> List.map(item =>
            switch (item) {
            | Text(input) =>
              <div
                className=flex_between_center
                key={Js.Float.toString(input.id)}>
                <Input.Text
                  onChange={event => {
                    let value = ReactEvent.Form.target(event)##value;
                    dispatch(AddText(input.id, value));
                    ();
                  }}
                  value={input.text}
                />
                <span
                  className={merge([cursor_pointer])}
                  onClick={_ => {
                    dispatch(DeleteInput(input.id));
                    ();
                  }}>
                  <DeleteIcon />
                </span>
              </div>
            | Range(input, rangeValue, scaleStart) =>
              <div
                className=flex_between_center
                key={Js.Float.toString(input.id)}>
                <div className=inputItem key={Js.Float.toString(input.id)}>
                  <Input.Text
                    onChange={event => {
                      let value = ReactEvent.Form.target(event)##value;
                      dispatch(AddText(input.id, value));
                      ();
                    }}
                    value={input.text}
                  />
                  <div className=flex_start_center>
                    <Input.Range
                      min="2"
                      max="11"
                      value={Js.Int.toString(rangeValue)}
                      onChange={event => {
                        let value: string =
                          ReactEvent.Form.target(event)##value;
                        dispatch(ChangeRange(input.id, value));
                        ();
                      }}
                    />
                    <div> {React.string(string_of_int(rangeValue))} </div>
                  </div>
                  <div>
                    <input
                      type_="checkbox"
                      checked={scaleStart == One}
                      value={scaleStart == One ? "1" : "0"}
                      onChange={event => {
                        let value: string =
                          ReactEvent.Form.target(event)##value;
                        dispatch(
                          ChangeScaleStart(
                            input.id,
                            value == "1" ? Zero : One,
                          ),
                        );
                        ();
                      }}
                    />
                    <span> {" Scale starts at 1" |> str} </span>
                  </div>
                </div>
                <span
                  className={merge([cursor_pointer])}
                  onClick={_ => {
                    dispatch(DeleteInput(input.id));
                    ();
                  }}>
                  <DeleteIcon />
                </span>
              </div>
            }
          )
       |> Array.of_list
       |> React.array}
    </form>
    <div>
      <button onClick={_ => dispatch(AddInput(Text(makeInput("Hello"))))}>
        {"Add Text" |> str}
      </button>
      <button
        onClick={_ =>
          dispatch(AddInput(Range(makeInput("Scale"), 6, One)))
        }>
        {"Add Scale" |> str}
      </button>
    </div>
  </main>;
};
