contract test {
    struct str {
        mapping(uint=>uint) map;
    }
    str data;
    function fun() public {
        mapping(uint => uint) a = data;
        data = a;
    }
}
// ----
