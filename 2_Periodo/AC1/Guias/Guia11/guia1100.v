//FELIPE COSTA UNSONST - 854155

`include "mealy_1101.v" 
`include "moore_1101.v" 

module Guia_1101; 
 reg   clk, reset, x; 
 wire  m1, m2; 

 mealy_1101  mealy1 ( m1, x, clk, reset ); 
 moore_1101 moore1 ( m2, x, clk, reset ); 

 initial 
  begin 
   $display ( "Time     X   Mealy Moore" ); 
 
       clk    = 1; 
       reset = 0; 
       x       = 0; 

  #5    reset = 1; 
  #10  x = 1; 
  #10  x = 0; 
  #10  x = 1; 
  #20  x = 0; 
  #10  x = 1; 
  #10  x = 1; 
  #10  x = 0; 
  #10  x = 1; 

  #30 $finish; 
 end  

 always 
  #5 clk = ~clk; 

 always @( posedge clk ) 
  begin 
   $display ( "%4d  %4b  %4b %5b", $time, x, m1, m2 ); 
  end 

endmodule 

// Module para FSM que reconhece "1010" e para após reconhecer a sequência uma vez
module guia_1101 (
    output reg found,
    input x, clk, reset
);

reg [3:0] state, next_state;

parameter start = 4'b0000, 
          id1 = 4'b0001, 
          id10 = 4'b0010, 
          id101 = 4'b0100, 
          id1010 = 4'b1000;  

always @(posedge clk or negedge reset) begin
    if (~reset) state <= start;
    else state <= next_state;
end

always @(state or x) begin
    found = 0;
    case(state)
        start: next_state = x ? id1 : start;
        id1: next_state = x ? start : id10;
        id10: next_state = x ? id101 : start;
        id101: next_state = x ? start : id1010;
        id1010: begin
            found = 1;
            next_state = start;
        end
        default: next_state = start;
    endcase
end

endmodule

