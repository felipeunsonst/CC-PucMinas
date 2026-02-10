//Felipe Cotsa Unsonst
//854155
module Guia_0303;

reg signed [5:0] a = 6'b10101; 
reg signed [7:0] b = 8'b110101; 
reg signed [5:0] c = 6'b00110; 
reg signed [6:0] d = 7'b010111; 
reg signed [7:0] e = 8'b110101; 

reg signed [5:0] pos_a;
reg signed [7:0] pos_b;
reg signed [5:0] pos_c;
reg signed [6:0] pos_d;
reg signed [7:0] pos_e;

initial
begin : main
  $display("Guia_0303 - Tests");

  pos_a = ~a + 1;
  $display("a = %6b -> C2(a) = %6b = %d", a, pos_a, pos_a);
  
  pos_b = ~b + 1;
  $display("b = %8b -> C2(b) = %8b = %d", b, pos_b, pos_b);
  
  pos_c = ~c + 1;
  $display("c = %6b -> C2(c) = %6b = %d", c, pos_c, pos_c);
  
  pos_d = ~d + 1;
  $display("d = %7b -> C2(d) = %7b = %d", d, pos_d, pos_d);
  
  pos_e = ~e + 1;
  $display("e = %8b -> C2(e) = %8b = %d", e, pos_e, pos_e);
end
endmodule 
