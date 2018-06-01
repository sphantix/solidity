contract A { function A() public {} }
// ----
// ParserError: (22-23): Defining constructors as functions with the same name as the contract is not allowed. Use "constructor(...) { ... }" instead.
