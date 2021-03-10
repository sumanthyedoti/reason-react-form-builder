type rangeValue = int;
type scaleStart =
  | Zero
  | One;
type id = float;
type answer = string;
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
  | AddText(id, string)
  | ChangeRange(id, string)
  | ChangeScaleStart(id, scaleStart)
  | DeleteInput(id)
  | Answer(id, answer);
type state = {
  action: inputAction,
  form: list(input),
};