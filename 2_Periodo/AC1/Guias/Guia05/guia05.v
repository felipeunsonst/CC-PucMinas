//Felipe Costa Unsonst
//854155

module Guia_0501 (output s, input a, b);
    assign s = ~(~(a & ~b));
endmodule

module Guia_0502 (output s, input a, b);
    assign s = ~(~a & ~b);
endmodule

module Guia_0503 (output s, input a, b);
    assign s = ~(a | ~b);
endmodule

module Guia_0504 (output s, input a, b);
    assign s = ~(a & ~b);
endmodule

module Guia_0505 (output s, input a, b);
    assign s = ~((a | b) & (~a | ~b));
endmodule

module Guia_0506 (output s, input a, b);
    assign s = ~((a & ~b) | (~a & b));
endmodule

module Guia_0507 (output s, input a, b);
    assign s = ~(~a | ~b) & ~(a | b);
endmodule

module Guia_0508 (output s, input a, b);
    assign s = ~(~a & ~b);
endmodule
