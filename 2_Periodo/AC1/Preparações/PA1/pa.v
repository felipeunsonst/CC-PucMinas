// FELIPE COSTA UNSONST // 85415

// QUESTÃO 01.a - Expressão canônica SoP
module q01a(output f, input a, b, c, d);
  assign f = (~a & ~b & c & ~d) | (~a & b & c & ~d) | (~a & b & c & d) |
             (a & b & ~c & ~d) | (a & b & c & ~d) | (a & b & c & d);
endmodule

// QUESTÃO 01.b - Expressão canônica PoS
module q01b(output f, input a, b, c, d);
  assign f = (a | b | c | d) & (a | b | c | ~d) & (a | b | ~c | ~d) &
             (a | ~b | c | d) & (a | ~b | c | ~d) &
             (~a | b | c | d) & (~a | b | c | ~d) & (~a | b | ~c | d) &
             (~a | b | ~c | ~d) & (~a | ~b | c | ~d);
endmodule

// QUESTÃO 01.c - Expressão simplificada (SoP)
module q01c(output f, input a, b, c, d);
  assign f = (~a & b & c) | (a & b & c) | (~a & ~b & c & ~d) | (a & b & ~c & ~d);
endmodule

// QUESTÃO 01.e - SoP com NAND (dupla negação)
module q01e(output f, input a, b, c, d);
  wire t1, t2, t3, t4, n1;

  assign t1 = ~((~a) & b & c);
  assign t2 = ~(a & b & c);
  assign t3 = ~((~a) & (~b) & c & (~d));
  assign t4 = ~(a & b & (~c) & (~d));

  assign n1 = ~(t1 & t2 & t3 & t4);
  assign f = ~n1;
endmodule

// QUESTÃO 01.f - PoS com NOR (dupla negação)
module q01f(output f, input a, b, c, d);
  wire t1, t2, t3, t4, t5, out;

  assign t1 = ((a | b | c));
  assign t2 = ((a | ~b | c | ~d));
  assign t3 = ((~a | b | c | d));
  assign t4 = ((~a | ~b | c | d));
  assign t5 = ((~a | ~b | ~c | ~d));

  assign out = ~(t1 & t2 & t3 & t4 & t5);
  assign f = ~out;
endmodule

// QUESTÃO 02 - Circuito lógico com wires
module q02(output s, input x, y);
  wire w1, w2, w3, w4, w5;
  not (w1, x);
  not (w2, y);
  and (w3, y, w2);
  or  (w4, w1, x);
  not (w5, w4);
  and (s, w3, w5);
endmodule

// QUESTÃO 03 - MUX aninhado
module mux(output s, input a, b, sel);
  assign s = sel ? b : a;
endmodule

module q03(output s, input a, b, c);
  wire m1, m2;
  wire na, nb, nc;

  not (na, a);
  not (nb, b);
  not (nc, c);

  mux mux1(m1, a, b, c);
  mux mux2(m2, nb, na, c);
  mux mux3(s, m1, m2, nc);
endmodule

// QUESTÃO 04 - Soma binária de -100 + 53 = -47
// Resultado: 11010001 (binário)
module q04(output [7:0] s);
  assign s = 8'b11010001;
endmodule

// QUESTÃO 05 - NAND (XNOR, NOR, NOT)
module q05(output s, input a, b);
  wire na, nb, x1, n1;
  not (na, a);
  not (nb, b);
  xnor (x1, a, b);
  nor  (n1, na, nb);
  nand (s, x1, n1);
endmodule
