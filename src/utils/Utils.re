let rec listOfRange = (start, end_) =>
  switch (start) {
  | num when num == end_ => [end_]
  | _ => List.append([start], listOfRange(start + 1, end_))
  };