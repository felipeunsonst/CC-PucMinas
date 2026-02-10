//FELIPE COSTA UNSONST
//854155

module Guia_0102; 

integer x1 = 0; 
integer x2 = 0; 
integer x3 = 0; 
integer x4 = 0; 
integer x5 = 0; 
reg [7:0] b1 = 8'b00010011; 
reg [7:0] b2 = 8'b00010101; 
reg [7:0] b3 = 8'b00010110; 
reg [7:0] b4 = 8'b0110010;  
reg [7:0] b5 = 8'b0111011;  


initial begin : main 
  $display("Guia_0102 - Tests");

  $display("b1 = %8b", b1); 
  x1 = b1; 
  $display("x1 = %d", x1); 
  $display("");

  $display("b2 = %8b", b2); 
  x2 = b2; 
  $display("x2 = %d", x2); 
  $display("");

  $display("b3 = %8b", b3); 
  x3 = b3; 
  $display("x3 = %d", x3); 
  $display("");

  $display("b4 = %8b", b4); 
  x4 = b4; 
  $display("x4 = %d", x4); 
  $display("");

  $display("b5 = %8b", b5); 
  x5 = b5; 
  $display("x5 = %d", x5); 
  $display("");
end 
endmodule 
