open FormTypes;

let formReducer = (state, action) =>
  switch (action) {
  | AddInput(input) => {action: Add, form: state.form @ [input]}
  | AddText(id, question) => {
      action: Update,
      form:
        state.form
        |> List.map(item =>
             switch (item) {
             | Text(inputItem) =>
               inputItem.id == id ?
                 Text({...inputItem, question}) : Text(inputItem)
             | Range(inputItem, rangeValue, scaleStart) =>
               inputItem.id == id ?
                 Range({...inputItem, question}, rangeValue, scaleStart) :
                 Range(inputItem, rangeValue, scaleStart)
             }
           ),
    }
  | ChangeRange(id, value) => {
      action: Update,
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
      action: Update,
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
      action: Delete,
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
    React.useReducer(formReducer, FormContext.initialState);
  // let context =
  //   React.useMemo2(() => (state.form, dispatch), (state.form, dispatch));
  <FormContext.Provider value=(state, dispatch)>  
    <App />
  </FormContext.Provider>;
};