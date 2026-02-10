//FELIPE COSTA UNSONST
//854155

module Guia_0202;  
   real        x;  
   integer     y = 7; 
   reg [7:0]   b = 0; 

   initial begin 
     $display("Guia_0202 - Tests");

     x = 0.625; 
     b = 0;
     y = 7;
     $display("x = %f", x); 
     while (x > 0 && y >= 0) begin 
       if (x * 2 >= 1) begin 
         b[y] = 1; 
         x = x * 2.0 - 1.0; 
       end else begin 
         b[y] = 0; 
         x = x * 2.0; 
       end 
       $display("b = 0.%8b", b); 
       y = y - 1; 
     end 

     x = 1.75; 
     b = 0;
     y = 7;
     $display("x = %f", x); 
     while (x > 0 && y >= 0) begin 
       if (x * 2 >= 1) begin 
         b[y] = 1; 
         x = x * 2.0 - 1.0; 
       end else begin 
         b[y] = 0; 
         x = x * 2.0; 
       end 
       $display("b = 0.%8b", b); 
       y = y - 1; 
     end 

     x = 3.125; 
     b = 0;
     y = 7;
     $display("x = %f", x); 
     while (x > 0 && y >= 0) begin 
       if (x * 2 >= 1) begin 
         b[y] = 1; 
         x = x * 2.0 - 1.0; 
       end else begin 
         b[y] = 0; 
         x = x * 2.0; 
       end // end if 
       $display("b = 0.%8b", b); 
       y = y - 1; 
     end 

     x = 4.3125; 
     b = 0;
     y = 7;
     $display("x = %f", x); 
     while (x > 0 && y >= 0) begin 
       if (x * 2 >= 1) begin 
         b[y] = 1; 
         x = x * 2.0 - 1.0; 
       end else begin 
         b[y] = 0; 
         x = x * 2.0; 
       end 
       $display("b = 0.%8b", b); 
       y = y - 1; 
     end 

     x = 7.875; 
     b = 0;
     y = 7;
     $display("x = %f", x); 
     while (x > 0 && y >= 0) begin 
       if (x * 2 >= 1) begin 
         b[y] = 1; 
         x = x * 2.0 - 1.0; 
       end else begin 
         b[y] = 0; 
         x = x * 2.0; 
       end 
       $display("b = 0.%8b", b); 
       y = y - 1; 
     end 
   end 
endmodule 
