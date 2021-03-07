open Webapi;
open Webapi.Dom;

let scrollToBottom = (~qs) =>
  switch (document |> Document.querySelector(qs)) {
  | Some(ele) =>
    Element.setScrollTop(ele, float_of_int(Element.scrollHeight(ele)))
  | _ => ()
  };