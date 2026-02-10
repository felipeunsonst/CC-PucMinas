//FELIPE COSTA UNSONST
//854155

module Guia_0201; 
  real x = 0;  
  real power2 = 1.0;
  integer y = 7; 
  reg [7:0] b;     

  initial begin 
    $display("Guia_0201 - Tests");

    b = 8'b00001010; 
    $display("b = 0.%8b", b); 

    x = 0; 
    power2 = 1.0; 
    y = 7; 
    
    while (y >= 0) begin 
      power2 = power2 / 2.0; 
      if (b[y] == 1) begin 
        x = x + power2; 
      end 
      $display("x = %f", x); 
      y = y - 1; 
    end 
  end
endmodule 
