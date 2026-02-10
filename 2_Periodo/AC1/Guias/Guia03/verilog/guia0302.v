//Felipe Costa Unsonst
//854155
module Guia_0302;

reg [5:0] a = 6'b100011; 
reg [7:0] b = 8'b11000100; 
reg [5:0] c = 6'b110100; 
reg [9:0] d = 10'b0010101101; 
reg [7:0] e = 8'b01111101; 
reg [5:0] res_a = 0;
reg [7:0] res_b = 0;
reg [5:0] res_c = 0;
reg [9:0] res_d = 0;
reg [7:0] res_e = 0;

initial 
begin : main
  $display("Guia_0302 - Tests");

  res_a = ~a;
  $display("a = %6b -> C1(a) = %6b", a, res_a);
  
  res_b = ~b;
  $display("b = %8b -> C1(b) = %8b", b, res_b);

  res_c = ~c + 1;
  $display("c = %6b -> C2(c) = %6b", c, res_c);
  
  res_d = ~d + 1;
  $display("d = %10b -> C2(d) = %10b", d, res_d);
  
  res_e = ~e + 1;
  $display("e = %8b -> C2(e) = %8b", e, res_e);
end 
endmodule 
