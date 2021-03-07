type rangeValue = int;
type scaleStart =
  | Zero
  | One;
type inputItem = {
  id: float,
  question: string,
  answer: string,
};
type input =
  | Text(inputItem)
  | Range(inputItem, rangeValue, scaleStart);

type inputAction =
  | None
  | Update
  | Add
  | Delete;
type action =
  | AddInput(input)
  | AddText(float, string)
  | ChangeRange(float, string)
  | ChangeScaleStart(float, scaleStart)
  | DeleteInput(float);
type state = {
  action: inputAction,
  form: list(input),
};