//Felipe Costa Unsonst
//854155
module Guia_0305;
reg [7:0] a = 8'b00110110; 
reg [7:0] b = 8'b00001101; 
reg [7:0] c = 8'b1011011;  
reg [7:0] d = 8'b11100;   
reg [7:0] e = 8'b01001101; 
reg [7:0] f = 8'b00111010; 
reg [7:0] g = 8'b11010011; 
reg [7:0] h = 8'b01011101; 
reg [7:0] i = 8'b01011110; 
reg [7:0] j = 8'b11101100; 

reg [7:0] res_a;
reg [7:0] res_b;
reg [7:0] res_c;
reg [7:0] res_d;
reg [7:0] res_e;

initial
begin : main
  $display("Guia_0305 - Tests");

  res_a = a + (~b + 1);
  $display("a: %b - %b = %b", a, b, res_a);

  res_b = c + (~d + 1);
  $display("b: %b - %b = %b", c, d, res_b);

  res_c = e + (~f + 1);
  $display("c: %b - %b = %b", e, f, res_c);

  res_d = g + (~h + 1);
  $display("d: %b - %b = %b", g, h, res_d);

  res_e = i + (~j + 1); 
  $display("e: %b - %b = %b", i, j, res_e);
end
endmodule 
