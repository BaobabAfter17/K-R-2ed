#define swap(t, x, y) {\
    (t) temp;\
    temp = (x);\
    (x) = (y);\
    (y) = temp;\
}

/* 1. not need for parenthesis since t, x, y will not be expressions
 * 2. here we assume x or y is not of the name temp */