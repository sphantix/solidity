interface I {
    struct A {
    }
}
// ----
// SyntaxError: (18-34): Defining empty structs is disallowed.
// TypeError: (18-34): Structs cannot be defined in interfaces.
