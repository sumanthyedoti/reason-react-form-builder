function scrollDivToBottom(id) {
  var elem = document.getElementById(id);
  elem.scrollTop = elem.scrollHeight;
}

module.exports = {
  scrollDivToBottom: scrollDivToBottom,
};