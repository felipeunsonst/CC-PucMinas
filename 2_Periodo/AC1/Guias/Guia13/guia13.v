//FELIPE COSTA UNSONST
//854155
module JK_FF (
    input j, k, clk, clr,
    output reg q
);
    always @(negedge clk or posedge clr) begin
        if (clr)
            q <= 0;
        else begin
            case ({j, k})
                2'b00: q <= q;
                2'b01: q <= 0;
                2'b10: q <= 1;
                2'b11: q <= ~q;
            endcase
        end
    end
endmodule

module AsyncDownCounter6(
    input clk, clr,
    output [5:0] q
);
    wire [5:0] t;
    assign t[0] = clk;
    genvar i;
    generate
        for (i = 0; i < 6; i = i + 1) begin : counter
            if (i == 0)
                JK_FF ff(1'b1, 1'b1, clk, clr, q[0]);
            else
                JK_FF ff(1'b1, 1'b1, q[i-1], clr, q[i]);
        end
    endgenerate
endmodule

module AsyncUpCounter6(
    input clk, clr,
    output [5:0] q
);
    wire [5:0] t;
    assign t[0] = clk;
    genvar i;
    generate
        for (i = 0; i < 6; i = i + 1) begin : counter
            if (i == 0)
                JK_FF ff(1'b1, 1'b1, clk, clr, q[0]);
            else
                JK_FF ff(1'b1, 1'b1, ~q[i-1], clr, q[i]);
        end
    endgenerate
endmodule

module DecadeUpCounter5(
    input clk, clr,
    output [4:0] q
);
    wire reset = (q == 5'd9);
    wire en = ~reset;

    wire [4:0] t;
    assign t[0] = clk & en;

    JK_FF ff0(1'b1, 1'b1, clk & en, clr, q[0]);
    JK_FF ff1(1'b1, 1'b1, ~q[0] & en, clr, q[1]);
    JK_FF ff2(1'b1, 1'b1, ~q[1] & ~q[0] & en, clr, q[2]);
    JK_FF ff3(1'b1, 1'b1, ~q[2] & ~q[1] & ~q[0] & en, clr, q[3]);
    JK_FF ff4(1'b1, 1'b1, ~q[3] & ~q[2] & ~q[1] & ~q[0] & en, clr, q[4]);
endmodule

module DecadeDownCounter5(
    input clk, clr,
    output [4:0] q
);
    wire reset = (q == 5'd0);
    wire en = ~reset;

    JK_FF ff0(1'b1, 1'b1, clk & en, clr, q[0]);
    JK_FF ff1(1'b1, 1'b1, q[0] & en, clr, q[1]);
    JK_FF ff2(1'b1, 1'b1, q[1] & q[0] & en, clr, q[2]);
    JK_FF ff3(1'b1, 1'b1, q[2] & q[1] & q[0] & en, clr, q[3]);
    JK_FF ff4(1'b1, 1'b1, q[3] & q[2] & q[1] & q[0] & en, clr, q[4]);
endmodule

module T_FF(
    input t, clk, clr,
    output reg q
);
    always @(posedge clk or posedge clr) begin
        if (clr)
            q <= 0;
        else if (t)
            q <= ~q;
    end
endmodule

module SyncCounterMod7(
    input clk, clr,
    output [2:0] q
);
    wire [2:0] t;

    assign t[0] = 1;
    assign t[1] = q[0];
    assign t[2] = q[0] & q[1];

    T_FF ff0(t[0], clk, clr, q[0]);
    T_FF ff1(t[1], clk, clr, q[1]);
    T_FF ff2(t[2], clk, clr, q[2]);
endmodule

module RingCounter6(
    input clk, clr,
    output reg [5:0] q
);
    always @(posedge clk or posedge clr) begin
        if (clr)
            q <= 6'b000001;
        else
            q <= {q[4:0], q[5]};
    end
endmodule

module TwistedRingCounter6(
    input clk, clr,
    output reg [5:0] q
);
    always @(posedge clk or posedge clr) begin
        if (clr)
            q <= 6'b000001;
        else
            q <= {~q[0], q[5:1]};
    end
endmodule
