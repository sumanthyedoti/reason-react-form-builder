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