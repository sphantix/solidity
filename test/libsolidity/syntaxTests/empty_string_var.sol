contract C {
  function f() {
    string memory a = "";
    bytes1 b = bytes1(a);
    bytes memory c = bytes(a);
    string memory d = string(a);
  }
}
// ----
// TypeError: (71-80): Explicit type conversion not allowed from "string memory" to "bytes1".
