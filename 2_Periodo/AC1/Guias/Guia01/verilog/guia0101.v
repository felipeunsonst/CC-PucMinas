//FELIPE COSTA UNSONST
//854155

module Guia_0101;
integer x1 = 27;   
integer x2 = 51;   
integer x3 = 725; 
integer x4 = 132;  
integer x5 = 360;  
reg [9:0] b1 = 0;  
reg [9:0] b2 = 0;  
reg [9:0] b3 = 0;  
reg [9:0] b4 = 0;  
reg [9:0] b5 = 0;  

initial begin : main
  $display("Guia_0101 - Tests");
  
  $display("x1 = %d", x1);
  b1 = x1;
  $display("b1 = %10b", b1);
  
  $display("x2 = %d", x2);
  b2 = x2;
  $display("b2 = %10b", b2);
  
  $display("x3 = %d", x3);
  b3 = x3;
  $display("b3 = %10b", b3);
  
  $display("x4 = %d", x4);
  b4 = x4;
  $display("b4 = %10b", b4);
  
  $display("x5 = %d", x5);
  b5 = x5;
  $display("b5 = %10b", b5);
end // main
endmodule // Guia_0101
