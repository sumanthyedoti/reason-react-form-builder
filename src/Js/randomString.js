function randomString() {
  return Math.random().toString(36).slice(-5);
}

export default randomString;