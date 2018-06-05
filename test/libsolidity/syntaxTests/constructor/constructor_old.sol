contract A { function A() public {} }
// ----
// SyntaxError: (13-35): Defining constructors as functions with the same name as the contract is not allowed. Use "constructor(...) { ... }" instead.
