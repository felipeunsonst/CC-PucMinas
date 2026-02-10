//FELIPE COSTA UNSONST
//854155

module Guia_0104; 

integer   x;
reg [7:0] b =  0;  

initial 
begin : main 
$display ( "Guia_0104 - Tests" );

x = 5'b10110;
$display ( "10110(2) = %2b %2b (4) = %x %x", x[4:2], x[1:0], x[4:2], x[1:0] );

x = 5'b11011;
$display ( "11011(2) = %3b (8) = %o", x[4:2], x[4:2] );

x = 6'b100100;
$display ( "100100(2) = %4b (16) = %x", x[5:2], x[5:2] );

x = 6'b101011;
$display ( "101011(2) = %3b %3b (8) = %o %o", x[5:3], x[2:0], x[5:3], x[2:0] );

x = 6'b101100;
$display ( "101100(2) = %2b %2b %2b (4) = %x %x %x", x[5:4], x[3:2], x[1:0], x[5:4], x[3:2], x[1:0] );

end 
endmodule 
