// Felipe Costa Unsonst
// 854155

module ex01_a (output s, input x, y, z);
    assign s = ~(x | (y | ~z));
endmodule

module ex01_b (output s, input x, y, z);
    assign s = (~x & y) | (~x & z);
endmodule

module ex01_c (output s, input x, y, z);
    assign s = (~(x & y)) & ~z;
endmodule

module ex01_d (output s, input x, y, z);
    assign s = (~(x & ~y)) & z;
endmodule

module ex01_e (output s, input x, y, z);
    assign s = (~x & ~y) & ~(y | ~z);
endmodule


module ex02_a (output s, input x, y);
    assign s = (~x & ~y) & ~x;
endmodule

module ex02_b (output s, input x, y);
    assign s = ~y | (x | (~x & ~y));
endmodule

module ex02_c (output s, input x, y);
    assign s = (~(x & ~y)) & (x | y);
endmodule

module ex02_d (output s, input x, y);
    assign s = (~(x & ~y)) | (~(x | ~y));
endmodule

module ex02_e (output s, input x, y);
    assign s = (~(y | x)) & (y | ~x);
endmodule


module ex03_a (output s, input x, y, z);
    assign s = y & (~x | z);
endmodule

module ex03_b (output s, input x, y, z);
    assign s = (y & z & ~x) | (x & (z | y));
endmodule

module ex03_c (output s, input x, y, w, z);
    assign s = y & (~x & z | x & z);
endmodule

module ex03_d (output s, input x, y, w, z);
    assign s = (y & ~w & ~z & ~x) | (y & w & z & ~x) | (w & z & y & x) | (x & w & ~y & ~z);
endmodule

module ex03_e (output s, input x, y, w, z);
    assign s = (~y & (w & z & ~x)) | (x & ~w & (~z | y));
endmodule


module ex04_a (output s, input x, y, z);
    assign s = (~x | y | ~z) & (x | ~y | z) & (~x | y | z);
endmodule

module ex04_b (output s, input x, y, z);
    assign s = (~x | y | ~z) & (~x | y | z) & (~x | ~y | z);
endmodule

module ex04_c (output s, input x, y, w, z);
    assign s = (~x | ~y | w | z) & (~x | y | ~w | ~z) & (x | y | w | ~z);
endmodule

module ex04_d (output s, input x, y, w, z);
    assign s = (x | y | ~w | z) & (~x | y | w | ~z) & (x | ~y | w | z);
endmodule

module ex04_e (output s, input x, y, w, z);
    assign s = (~x | ~y | w | z) & (x | y | ~w | ~z) & (~x | y | ~w | z);
endmodule


module ex05_a (output s, input x, y);
    assign s = x & ~y;
endmodule

module ex05_b (output s, input x, y);
    assign s = ~x | y;
endmodule

module ex05_c (output s, input x, y, z);
    assign s = z & (~x & y | x & ~y);
endmodule

module ex05_d (output s, input x, y, z);
    assign s = (~x & ~y & ~z) | (x & y & ~z);
endmodule

module ex05_e (output s, input x, y, w, z);
    assign s = (w & z & y & ~x) | (~y & ~w & ~z & x);
endmodule
