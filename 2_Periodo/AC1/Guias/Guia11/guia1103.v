//FELIPE COSTA UNSONST - 854155

module guia_1103 (
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
            next_state = id1;  
        end
        default: next_state = start;
    endcase
end

endmodule
