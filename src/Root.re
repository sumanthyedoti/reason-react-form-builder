open FormTypes;

let reducer = (state, action) =>
  switch (action) {
  | AddInput(input) => {form: state.form @ [input]}
  | AddText(id, text) => {
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Text(inputItem) =>
               inputItem.id == id ?
                 Text({...inputItem, text}) : Text(inputItem)
             | Range(inputItem, rangeValue, scaleStart) =>
               inputItem.id == id ?
                 Range({...inputItem, text}, rangeValue, scaleStart) :
                 Range(inputItem, rangeValue, scaleStart)
             }
           ),
    }
  | ChangeRange(id, value) => {
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Range(inputItem, rangeValue, scaleStart) =>
               inputItem.id == id ?
                 Range(inputItem, int_of_string(value), scaleStart) :
                 Range(inputItem, rangeValue, scaleStart)
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
               inputItem.id == id ?
                 Range(inputItem, rangeValue, scaleStartPosition) :
                 Range(inputItem, rangeValue, scaleStart)
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
  let (state, dispatch) =
    React.useReducer(reducer, FormContext.initialState);
  // let context =
  //   React.useMemo2(() => (state.form, dispatch), (state.form, dispatch));
  <FormContext.Provider value=(state, dispatch)>  
    <App />
  </FormContext.Provider>;
};