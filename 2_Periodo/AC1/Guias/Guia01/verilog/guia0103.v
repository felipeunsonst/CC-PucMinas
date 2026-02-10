//FELIPE COSTA UNSONST
//854155

module Guia_0103;

integer x1 = 54;   
integer x2 = 67;   
integer x3 = 76;   
integer x4 = 157;  
integer x5 = 731;  

initial begin : main
  $display("Guia_0103 - Tests");

  $display("x1 (decimal) = %d", x1);
  $display("x1 (quaternary) = %d%d", (x1/4), (x1%4)); 
  $display("");

  $display("x2 (decimal) = %d", x2);
  $display("x2 (octal) = %o", x2);
  $display("");

  $display("x3 (decimal) = %d", x3);
  $display("x3 (hexadecimal) = %x", x3);
  $display("");

  $display("x4 (decimal) = %d", x4);
  $display("x4 (hexadecimal) = %x", x4);
  $display("");

  $display("x5 (decimal) = %d", x5);
  $display("x5 (hexadecimal) = %x", x5);
  $display("");
end 

endmodule 
