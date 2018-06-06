contract test {
    function f(uint256 arg1, uint32 arg2) public returns (bool ret) {
        bool x = arg1 + arg2 == 8; ret = x;
    }
}
// ----
// Warning: (20-135): Function state mutability can be restricted to pure
