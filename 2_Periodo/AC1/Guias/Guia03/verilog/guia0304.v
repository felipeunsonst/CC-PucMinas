//Felipe Costa Unsonst
//854155
module Guia_0304;
reg [4:0] a = 5'b11101; 
reg [3:0] b = 4'b1101; 
reg [7:0] c = 8'b1011001;  
reg [7:0] d = 8'b1001;     
reg [7:0] e = 8'b110101;   
reg [7:0] f = 8'b100111;   
reg [8:0] g = 9'b011101100; 
reg [8:0] h = 9'b010110101; 
reg [11:0] i = 12'b011010100010; 
reg [11:0] j = 12'b110000010100; 

reg [4:0] res_a;
reg [7:0] res_b;
reg [8:0] res_c;
reg [8:0] res_d;
reg [11:0] res_e;

initial
begin : main
  $display("Guia_0304 - Tests");

  res_a = a + ~b + 1;
  $display("a: %b - %b = %b = %d", a, b, res_a, res_a);

  res_b = c + ~d + 1; 
  $display("b: %b - %b = %b", c, d, res_b);

  res_c = e + ~f + 1;
  $display("c: %b - %b = %b = %d", e, f, res_c, res_c);

  res_d = g + ~h + 1;
  $display("d: %b - %b = %b = %d", g, h, res_d, res_d);

  res_e = i + ~j + 1; 
  $display("e: %b - %b = %b", i, j, res_e);
end
endmodule 
