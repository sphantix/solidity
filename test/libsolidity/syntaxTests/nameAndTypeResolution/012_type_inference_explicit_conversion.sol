contract test {
    function f() public returns (int256 r) { int256 x = int256(uint32(2)); return x; }
}
// ----
// Warning: (20-102): Function state mutability can be restricted to pure
