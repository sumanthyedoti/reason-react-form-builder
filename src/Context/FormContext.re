open FormTypes;

let initialState = {
  action: None,
  form: [
    Text({id: "123123", question: "something", answer: ""}),
    Range({id: "12312", question: "something", answer: ""}, 10, Zero),
  ],
};

type dispatch = action => unit;
type contextValue = (state, dispatch);

let initialContext: contextValue = (initialState, _ => ignore());

let context = React.createContext(initialContext);

module Provider = {
  let make = React.Context.provider(context);

  /** Tell bucklescript how to translate props into JS */
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};