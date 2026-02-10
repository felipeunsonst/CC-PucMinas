//FELIPE COSTA UNSONST 
//854155

// RAM 1x4 usando flip-flops JK
module RAM1x4(
    input clk,
    input clr,
    input rw,
    input addr,
    input [3:0] data_in,
    output reg [3:0] data_out
);
    reg [3:0] mem;

    always @(posedge clk or posedge clr) begin
        if (clr)
            mem <= 4'b0000;
        else if (addr && rw) // write enable
            mem <= data_in;
    end

    always @(negedge clk) begin
        if (addr && !rw) // read enable
            data_out <= mem;
        else
            data_out <= 4'bz;
    end
endmodule

// RAM 1x8 usando dois módulos RAM 1x4
module RAM1x8(
    input clk,
    input clr,
    input rw,
    input addr,
    input [7:0] data_in,
    output [7:0] data_out
);
    wire [3:0] low, high;

    RAM1x4 low_bits(clk, clr, rw, addr, data_in[3:0], low);
    RAM1x4 high_bits(clk, clr, rw, addr, data_in[7:4], high);

    assign data_out = {high, low};
endmodule

// RAM 2x8 usando 2 módulos RAM 1x8
module RAM2x8(
    input clk,
    input clr,
    input rw,
    input [0:0] addr,
    input [7:0] data_in,
    output [7:0] data_out
);
    wire [7:0] out0, out1;

    RAM1x8 ram0(clk, clr, rw & ~addr, 1'b1, data_in, out0);
    RAM1x8 ram1(clk, clr, rw &  addr, 1'b1, data_in, out1);

    assign data_out = addr ? out1 : out0;
endmodule

// RAM 4x8 usando 2 módulos RAM 2x8
module RAM4x8(
    input clk,
    input clr,
    input rw,
    input [1:0] addr,
    input [7:0] data_in,
    output [7:0] data_out
);
    wire [7:0] out0, out1;

    RAM2x8 ram0(clk, clr, rw & ~addr[1], addr[0], data_in, out0);
    RAM2x8 ram1(clk, clr, rw &  addr[1], addr[0], data_in, out1);

    assign data_out = addr[1] ? out1 : out0;
endmodule

// RAM 8x8 usando 2 módulos RAM 4x8
module RAM8x8(
    input clk,
    input clr,
    input rw,
    input [2:0] addr,
    input [7:0] data_in,
    output [7:0] data_out
);
    wire [7:0] out0, out1;

    RAM4x8 ram0(clk, clr, rw & ~addr[2], addr[1:0], data_in, out0);
    RAM4x8 ram1(clk, clr, rw &  addr[2], addr[1:0], data_in, out1);

    assign data_out = addr[2] ? out1 : out0;
endmodule

// RAM 4x16 usando dois RAM4x8
module RAM4x16(
    input clk,
    input clr,
    input rw,
    input [1:0] addr,
    input [15:0] data_in,
    output [15:0] data_out
);
    wire [7:0] out_low, out_high;

    RAM4x8 ram_low(clk, clr, rw, addr, data_in[7:0], out_low);
    RAM4x8 ram_high(clk, clr, rw, addr, data_in[15:8], out_high);

    assign data_out = {out_high, out_low};
endmodule

// RAM 8x16 usando 2 módulos RAM 4x16
module RAM8x16(
    input clk,
    input clr,
    input rw,
    input [2:0] addr,
    input [15:0] data_in,
    output [15:0] data_out
);
    wire [15:0] out0, out1;

    RAM4x16 ram0(clk, clr, rw & ~addr[2], addr[1:0], data_in, out0);
    RAM4x16 ram1(clk, clr, rw &  addr[2], addr[1:0], data_in, out1);

    assign data_out = addr[2] ? out1 : out0;
endmodule
