contract A { constructor() public {} }
contract B is A { function A() public pure returns (uint8) {} }
// ----
