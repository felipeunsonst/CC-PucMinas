//FELIPE COSTA UNSONST
//854155

module Guia_1401 (output [4:0] q, input d, input clk, input ld);
  reg [4:0] q;
  always @(posedge clk) begin
    if (ld) q[0] <= 1;
    else begin
      q[0] <= d;
      q[4:1] <= q[3:0];
    end
  end
endmodule

module Guia_1402 (output [4:0] q, input [4:0] d, input clk, input ld);
  reg [4:0] q;
  always @(posedge clk) begin
    if (ld) q <= d;
    else q[4:0] <= {q[3:0], 1'b0};
  end
endmodule

module Guia_1403 (output [4:0] q, input clk, input ld);
  reg [4:0] q;
  always @(posedge clk) begin
    if (ld) q <= 5'b00001;
    else q <= {q[0], q[4:1]};
  end
endmodule

module Guia_1404 (output [4:0] q, input clk, input ld);
  reg [4:0] q;
  always @(posedge clk) begin
    if (ld) q <= 5'b00001;
    else q <= {q[3:0], ~q[4]};
  end
endmodule

module Guia_1405 (output reg q, input [4:0] d, input clk, input ld, input rst);
  reg [4:0] shift;
  always @(posedge clk or posedge rst) begin
    if (rst) shift <= 5'b0;
    else if (ld) shift <= d;
    else shift <= {1'b0, shift[4:1]};
  end
  always @(*) begin
    q = shift[0];
  end
endmodule

module Guia_1406 (output [5:0] q, input [5:0] d, input clk, input ld);
  reg [5:0] q;
  always @(posedge clk) begin
    if (ld) q <= d;
    else q <= {q[4:0], q[5]};
  end
endmodule

module Guia_1407 (output [5:0] q, input [5:0] d, input clk, input ld);
  reg [5:0] q;
  always @(posedge clk) begin
    if (ld) q <= d;
    else q <= {q[0], ~q[5:1]};
  end
endmodule


