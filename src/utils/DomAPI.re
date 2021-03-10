open Webapi.Dom;

let scrollToBottom = (~qs) =>
  switch (document |> Document.querySelector(qs)) {
  | Some(ele) =>
    Element.setScrollTop(ele, float_of_int(Element.scrollHeight(ele)))
  | _ => ()
  };

let toggleClassToSiblings = (~qs, ~className, ~target) =>
  switch (document |> Document.querySelectorAll(qs)) {
  | elements =>
    elements
    |> NodeList.forEach((ele, i) => {
         ele == target ? Js.log("true") : Js.log("false");
         ();
       });
    ();
  | _ => ()
  };